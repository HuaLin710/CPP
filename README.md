# C++ Learning Notes

A C++ practice repository covering basic syntax exercises, textbook chapter examples, and an iteratively developed bank account system.

## Directory Structure

```text
CPP/
├── learning/     # Basic syntax: I/O, references, overloading, namespaces, etc.
├── book/         # Textbook chapter examples (Chapter 3–16)
└── OOP/          # Banking system project, iterated from Ver01 to Ver11
```

### `learning/`

Introductory exercises covering addition, function overloading, default arguments, references, inline functions, namespaces, and more.

### `book/`

Examples and homework organized by chapter:

| Chapter | Main Topics |
|------|----------|
| Chapter 3–4 | Classes and objects, encapsulation |
| Chapter 5–6 | Copy constructors, object relationships |
| Chapter 7–8 | Inheritance, virtual functions |
| Chapter 9 | Multiple inheritance |
| Chapter 10–11 | Operator overloading, functors |
| Chapter 12 | String class |
| Chapter 13–14 | Function templates, class templates |
| Chapter 15 | Exception handling |
| Chapter 16 | Type conversions (`static_cast` / `dynamic_cast`, etc.) |

### `OOP/`

Evolving versions of a bank account system (`BankingSystemVer01` → `Ver11`), gradually adding inheritance, virtual functions, array encapsulation, a custom `String` class, exception handling, and more.

## Build and Run

Environment: macOS + `clang++`.

Single-file examples:

```bash
clang++ -g example.cpp -o example
./example
```

Multi-file projects (using `OOP/BankingSystemVer11` as an example):

```bash
cd OOP/BankingSystemVer11
clang++ -g *.cpp -o BankingSystemMain
./BankingSystemMain
```

In VS Code / Cursor, you can compile the currently open `.cpp` file with the existing C/C++ build task.

## Notes

This repository tracks only source files (`.cpp` / `.h`) and necessary editor configuration. Generated executables, `.dSYM` debug symbols, and `.DS_Store` files are not committed.
