# 🦀 Simple Shell in C

A simple shell implementation written in **C**, inspired by the Linux shell.
This project is mainly for learning purposes — exploring command parsing, REPL design, and implementing basic shell features.

## ✨ Features

* **REPL (Read-Eval-Print Loop)**
* **Command parsing** → split user input into command + arguments
* **Built-in commands** → e.g., `exit`, `help`
* **Execute external commands** → run system programs like `ls`, `echo`, `pwd`
* **Error handling** → basic handling of invalid commands

## 🚀 Planned Features

* Command pipelines (`ls | grep foo`)
* Input/output redirection (`>`, `<`)
* Environment variables (`$PATH`, `$HOME`)
* Basic scripting support

## 📦 Installation

Clone the repository and build with Cargo:

```bash
git clone https://github.com/velukuberan/shell-in-c.git
cd shell-in-c 
chmod +x build.sh 
./build.sh

# to clean the build (removes the build dir)
./build.sh clean

# for coding standards (format it according to the google standards)
./build.sh format

```

Run the shell:

```bash
# From project root - this also works
./build/bin/shell
```

## 💻 Usage

Once running, you can type commands just like in a Linux shell:

```bash
$ exit
```

## 📚 Learning Goals

* Practice C system programming
* Learn about **parsing**, **process management**, and **I/O** in C
* Build a foundation for exploring OS-level concepts

## ⚠️ Disclaimer

This is a **learning project**, I Use it for fun, exploration, and learning C internals.
