# Gerardosh - A Custom Unix Shell Implementation

A lightweight Unix shell written in C, supporting basic command execution, pipelines, and I/O redirection.

## Project Overview
This project implements a minimal Unix-style shell capable of:
- Executing external programs
- Handling basic built-in commands (`cd`, `exit`)
- Supporting pipelines (`cmd1 | cmd2`)
- Redirecting input/output (`>`, `<`)

Designed as a learning exercise to put OS concepts into practice. The concept I was learning was process controls such as (`fork`, `exec`, `wait`) and file descriptor management.

## Features
- Tokenizes input into executable commands
- Handles quoted arguments and whitespace

### Process Execution
- Uses `fork()` + `exec()` to run programs
- Implements `wait()` for process synchronization

### Pipelines
- Supports multiple commands like (`ls | grep .c | wc -l`)
- Uses Unix pipes (`pipe()`) and file descriptor redirection

### I/O Redirection
- Basic file redirection (`echo "text" > file.txt`)

### Built-in Commands
- `cd` (directory navigation)
- `exit` (shell termination)

## Technical Details
- **Language**: C 
- **Dependencies**: Standard C library, GNU Make
- **Tested On**: Linux (Ubuntu)


## Build & Run
```sh
git clone https://github.com/Gerardos0/gerardosh.git
cd gerardosh
make
./gerardosh

```

## My Learning Outcomes
- Deepened understanding of Unix process management
- Experience with file descriptors and system calls
- C package organization
