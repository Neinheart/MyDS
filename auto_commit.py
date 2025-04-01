# auto_commit.py
import subprocess
import os
from collections import Counter

# file extension to commit type mapping
TYPE_MAP = {
    'cpp': 'feat',
    'cc': 'feat',
    'cxx': 'feat',
    'h': 'feat',
    'hpp': 'feat',
    'md': 'docs',
    'txt': 'docs',
    'cmake': 'chore',
    'py': 'tool'
}

# scope override based on folder name
SCOPE_MAP = {
    'test': 'test',
    'bench': 'bench',
    'doc': 'docs',
    'cmake': 'build',
    'common': 'infra',
    'third_party': 'deps'
}

def get_changed_files():
    output = subprocess.check_output(['git', 'diff', '--cached', '--name-only']).decode()
    return output.strip().split('\n') if output else []

def detect_scope(file_path):
    parts = file_path.split('/')
    if parts:
        folder = parts[0]
        return SCOPE_MAP.get(folder, folder)
    return 'core'

def detect_type(file_path):
    ext = file_path.split('.')[-1].lower()
    return TYPE_MAP.get(ext, 'chore')

def main():
    files = get_changed_files()
    if not files:
        print("No staged changes found.")
        return

    scope_counter = Counter(detect_scope(f) for f in files)
    type_counter = Counter(detect_type(f) for f in files)

    major_type = type_counter.most_common(1)[0][0]
    major_scope = ','.join(sorted(set(scope_counter)))

    # construct message
    message = f"{major_type}({major_scope}): update {len(files)} files"

    # optional: show detailed breakdown
    print("Files to be committed:")
    for f in files:
        print(f" - {f}")
    print(f"\nGenerated commit message:\n{message}\n")

    # confirm before committing
    confirm = input("Proceed with commit? [y/N]: ").strip().lower()
    if confirm == 'y':
        subprocess.call(['git', 'commit', '-m', message])
    else:
        print("Commit cancelled.")

if __name__ == '__main__':
    main()