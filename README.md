# Cpp Executor Daemon

This C++ program runs as a background daemon that tracks specific keyboard events, manages clipboard content, and automates the creation, compilation, and execution of C++ files based on clipboard data. 

## Features
1. **Track Keyboard Press**: The program listens for key combinations like `Ctrl + Shift + 1`, `Ctrl + Shift + 2`, and `Ctrl + Shift + 3` to trigger different functionalities.
2. **Enable Clipboard Tracking (`Ctrl + Shift + 1`)**: When this key combination is pressed, the daemon starts monitoring the clipboard. Every time `Ctrl + C` is pressed (copy action), it collects data from the clipboard.
3. **Create and Run C++ File (`Ctrl + Shift + 2`)**: This key combination compiles the collected clipboard data (assuming it's valid C++ code) into a temporary C++ file, compiles it, and executes it. The output of the program is displayed, and the temporary file is deleted afterward.
4. **Stop Daemon (`Ctrl + Shift + 3`)**: This combination stops the daemon and terminates the process.

## Project Structure

```plaintext
cpp-executor-daemon/
│
├── src/
│   ├── clipboard/
│   │   ├── Clipboard.cpp       # Clipboard handling implementation
│   │   └── Clipboard.hpp       # Clipboard handling header
│   ├── CppManager/
│   │   ├── CppManager.cpp      # C++ file creation and compilation logic
│   │   └── CppManager.hpp      # C++ file creation and compilation header
│   ├── FileExecuter/
│   │   ├── FileExecuter.cpp    # File execution logic
│   │   └── FileExecuter.hpp    # File execution header
│   ├── CMakeLists.txt          # CMake configuration file
│   └── main.cpp                # Main program that ties everything together
└── README.md                   # Project documentation
![image](https://github.com/user-attachments/assets/e48f086d-6c3e-47d8-855c-d2422a4adb2b)
