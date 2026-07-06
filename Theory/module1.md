# Module 1: Theory Solutions

### Q9. Differences Between Git Pull, Fetch, and Clone

| Command | Operational Mechanism | Primary Use Case |
| :--- | :--- | :--- |
| **`git clone`** | Downloads an entire target remote repository, including all file assets, revision histories, and branch mappings, down to a local directory for the first time. | Executed when initiating work on a pre-existing remote project or pulling down a collaborator's repository to your local workstation. |
| **`git fetch`** | Queries the remote repository to retrieve the latest tracking branch metadata and commit headers without merging changes into your active working directory. | Executed to inspect modifications made by external contributors without risking local codebase stability or merge conflicts. |
| **`git pull`** | Sequentially executes a `git fetch` to grab the latest remote objects followed immediately by a `git merge` to integrate them directly into your current checked-out branch. | Executed to keep your local operational branch synchronized with the latest upstream deployments. |

---

### Q10. The Role and Structure of a `.gitignore` File

#### Definition
A `.gitignore` file is a plain-text configuration file situated at the root level of a Git workspace. It explicitly defines specific file patterns, system tracking artifacts, compiled binaries, or localized configuration paths that Git should completely bypass during staging (`git add`) actions.

#### Recommended `.gitignore` Architecture for Arduino Projects
```text
# --- Arduino/C++ Compiled Binaries ---
*.hex
*.elf
*.o
*.a
*.d

# --- Operating System Hidden Files ---
.DS_Store
Thumbs.db

# --- Development IDE & Toolchain Build Folders ---
.vscode/
build/
.build/