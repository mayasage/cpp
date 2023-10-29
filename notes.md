# Environment Setup

## Tools

- **Vscode** with Microsoft's _C/C++_ extension.

- Following compilers & debugger:

  **GCC**

  ```sh
  sudo apt install build-essential # gcc-9, g++-9
  sudo apt install gcc-10 g++-10
  sudo apt install gdb

  g++-10 --version
  gcc-10 --version
  gdb --version
  ```

  **Clang**

  ```sh
  sudo apt install clang-12

  clang++-12 --version
  clang-12 --version
  ```

## Setup VScode

1. Create **tasks.json** file in _.vscode_ folder.

   a. Click on Terminal > Configure Tasks.

   b. Select "_g++-10 build active file_" for **_gcc_**, "_clang++-12 build active file_" for **clang**.

2. Replace it with the following:

   **tasks.json**

   _gcc_

   ```json
   {
     "version": "2.0.0",
     "tasks": [
       {
         "type": "cppbuild",
         "label": "Build with GCC",
         "command": "/usr/bin/g++-10",
         "args": [
           "-g",
           "-std=c++20",
           "${workspaceFolder}/*.cpp",
           "-o",
           "${fileDirname}/gene.maya"
         ],
         "options": {
           "cwd": "${fileDirname}"
         },
         "problemMatcher": ["$gcc"],
         "group": "build",
         "detail": "compiler: /usr/bin/g++-10"
       }
     ]
   }
   ```

   _clang_

   ```json
   {
     "version": "2.0.0",
     "tasks": [
       {
         "type": "cppbuild",
         "label": "Build with Clang",
         "command": "/usr/bin/clang++-12",
         "args": [
           "-g",
           "-std=c++20",
           "${workspaceFolder}/*.cpp",
           "-o",
           "${fileDirname}/gene.maya"
         ],
         "options": {
           "cwd": "${fileDirname}"
         },
         "problemMatcher": ["$gcc"],
         "group": "build",
         "detail": "compiler: /usr/bin/clang++-12"
       }
     ]
   }
   ```

   _both_

   ```json
   {
     "version": "2.0.0",
     "tasks": [
       {
         "type": "cppbuild",
         "label": "Build with GCC",
         "command": "/usr/bin/g++-10",
         "args": [
           "-g",
           "-std=c++20",
           "${workspaceFolder}/*.cpp",
           "-o",
           "${fileDirname}/gene.maya"
         ],
         "options": {
           "cwd": "${fileDirname}"
         },
         "problemMatcher": ["$gcc"],
         "group": "build",
         "detail": "compiler: /usr/bin/g++-10"
       },
       {
         "type": "cppbuild",
         "label": "Build with Clang",
         "command": "/usr/bin/clang++-12",
         "args": [
           "-g",
           "-std=c++20",
           "${workspaceFolder}/*.cpp",
           "-o",
           "${fileDirname}/gene.maya"
         ],
         "options": {
           "cwd": "${fileDirname}"
         },
         "problemMatcher": ["$gcc"],
         "group": "build",
         "detail": "compiler: /usr/bin/clang++-12"
       }
     ]
   }
   ```

3. To run:
   1. Click on Terminal > Run Task.
   2. Click "_Build With GCC_" for **gcc**, "_Build With Clang_" for **clang**.

### Getting rid of sqiggly lines.

1.  Click on View > Command Palette... > C/C++ Edit Configuration (UI).
2.  Scroll down to C++ Standard and select _c++20_.

### Setup CodeRunner VSCode Extension

1. Install CodeRunner.
2. Go to settings.json > code-runner.executorMap > cpp, and replace it with following:

   _gcc_

   ```json
   {
     "code-runner.executorMap": {
       "cpp": "cd $dir && /usr/bin/g++-10 -g -std=c++20 *.cpp -o $fileNameWithoutExt.maya && $dir$fileNameWithoutExt.maya"
     }
   }
   ```

   _clang_

   ```json
   {
     "code-runner.executorMap": {
       "cpp": "cd $dir && /usr/bin/clang++-12 -g -std=c++20 *.cpp -o $fileNameWithoutExt.maya && $dir$fileNameWithoutExt.maya"
     }
   }
   ```

3. Open a source file, right click & click _Run Code_.
4. Don't keep any source file in your root folder.

### Setup script to remove .maya files

1. Add this file to your root folder.

   **delete-dot-maya-files.sh**

   ```sh
   #!/bin/sh

   ext="*.maya"

   fileCount=$(find . -type f -name "${ext}" | wc -l)

   if [ $fileCount -gt 0 ]; then

     # Print Found Files
     echo "Files Found:"
     find . -type f -name "*.maya" -exec echo {} \;

     echo "Deleting..."

     # Delete Found Files
     find . -type f -name "*.maya" -exec rm {} \;
     echo "Deleted found Files."

   else

     echo "No files found."

   fi
   ```

2. Don't keep any source file in your root folder.

## Setup Debugger

1. Click on Run > Add Configuration...

   1. This will open a **launch.json** file, and
   2. Give you a dropdown list to select a configuration from.
   3. Select _C/C++: (gdb) Launch_.

2. Replace

   ```
   "program": "enter program name, for example ${workspaceFolder}/a.out",
   ```

   With

   ```
   "program": "${fileDirname}/${fileBasenameNoExtension}.maya",
   ```

3. Click on _Run > Start Debugging_ to debug.

4. **Configuration**

   ```json
   {
     // Use IntelliSense to learn about possible attributes.
     // Hover to view descriptions of existing attributes.
     // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
     "version": "0.2.0",
     "configurations": [
       {
         "name": "(gdb) Launch",
         "type": "cppdbg",
         "request": "launch",
         "program": "${fileDirname}/${fileBasenameNoExtension}.maya",
         "args": [],
         "stopAtEntry": false,
         "cwd": "${fileDirname}",
         "environment": [],
         "externalConsole": false,
         "MIMode": "gdb",
         "setupCommands": [
           {
             "description": "Enable pretty-printing for gdb",
             "text": "-enable-pretty-printing",
             "ignoreFailures": true
           },
           {
             "description": "Set Disassembly Flavor to Intel",
             "text": "-gdb-set disassembly-flavor intel",
             "ignoreFailures": true
           }
         ]
       }
     ]
   }
   ```
