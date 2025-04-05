# Gerardosh - A Custom Unix Shell Implementation

A lightweight Unix shell written in C, supporting basic command execution, pipelines, and I/O redirection.

## Project Overview
This project implements a minimal Unix-style shell capable of:
- Executing external programs
- Handling basic built-in commands (`cd`, `exit`)
- Supporting pipelines (`cmd1 | cmd2`)
- Redirecting input/output (`>`, `<`)

Designed as a learning exercise in systems programming, it demonstrates core OS concepts such as process control (`fork`, `exec`, `wait`) and file descriptor management.

## Key Features
### Command Parsing
- Tokenizes input into executable commands
- Handles quoted arguments and whitespace

### Process Execution
- Uses `fork()` + `exec()` to run programs
- Implements `wait()` for process synchronization

### Pipelines
- Supports multi-stage commands (`ls | grep .c | wc -l`)
- Uses Unix pipes (`pipe()`) and file descriptor redirection

### I/O Redirection
- Basic file redirection (`echo "text" > file.txt`)

### Built-in Commands
- `cd` (directory navigation)
- `exit` (shell termination)

## Technical Details
- **Language**: C (POSIX-compliant)
- **Dependencies**: Standard C library, GNU Make
- **Tested On**: Linux (WSL/macOS should work)

## Learning Outcomes

    Deepened understanding of Unix process management

    Practical experience with file descriptors and system calls

    Modular software design in C

## Build & Run
```sh
git clone https://github.com/Gerardos0/gerardosh.git
cd gerardosh
make
./gerardosh

