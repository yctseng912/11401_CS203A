# Connect to GitHub with VSCode (Ubuntu Docker on macOS)


### Development Environment

- Host OS: macOS

- Editor: Visual Studio Code

- Version Control: Git + GitHub

- Compilation Platform: Ubuntu 24.04 (Docker container)

Note: Code is edited on macOS using VSCode, but compiled and tested inside an Ubuntu Docker container.

---
### Prerequisites

Before you begin, ensure you have the following:
- Visual Studio Code installed on your computer. [Download VS Code here](https://code.visualstudio.com/)

- Git installed and configured on your system. [Download Git here](https://git-scm.com/).

- Docker installed to run Ubuntu container. [Download Docker here](https://www.docker.com/).
- A GitHub account.

---

### Steps to Connect and Work with GitHub

1. **Install GitHub Extension for VSCode**
    - Open VSCode.

    - Go to Extensions view → search **GitHub Pull Requests and Issues** → install it.

2. **Sign in to GitHub**
    - Open Command Palette (`Cmd+Shift+P` on macOS)

    - Type `GitHub: Sign in` → follow prompts to authenticate.

3. **Clone a Repository**

    - Command Palette → `Git: Clone` → paste repository URL

    - Select local folder for repository

    - Open the cloned folder in VSCode**

4. **Edit Code**

    - Edit C / C++ files in VSCode

    - Use Source Control tab to stage, commit, and write commit messages

5. **Compile and Run in Ubuntu Docker**

    - Open terminal in macOS or VSCode

    - Start Docker container and mount project folder:
    ``` bash 
    docker run -it --rm -v $(pwd):/app  <Docker image name>
    ```

    - Navigate to project folder

    - Build project using Makefile:
    ``` bash
    make       # build all
    make c     # build C version only
    make cxx   # build C++ version only
    ```

    - Run compiled binaries:
    ``` bash
    ./C/hash_function
    ./CXX/hash_function_cpp
    ```

6. **Push Changes to GitHub**
    - After committing, click **Sync Changes** in VSCode Source Control tab to push updates.

---

### Additional Tips

- Use VSCode terminal to run advanced Git commands if needed

- Install **GitLens** extension for better Git history and insights

- Always test code inside Docker container to ensure Linux compatibility