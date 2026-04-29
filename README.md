# LLVM Compiler Infrastructure

This repository contains a compact learning and experimentation workspace built around parts of the LLVM Kaleidoscope tutorial and a small custom language implementation (referred to as "comlang" / "toy"). It is intended for educational exploration of compiler front-ends, AST construction, and runtime code generation using LLVM's JIT APIs.

## Project Overview

- **Purpose:** provide a minimal, self-contained environment for implementing and experimenting with a simple language (parser, lexer, AST, codegen) and running JIT-compiled code.
- **Key components:**
	- `include/comlang/` — public headers for the toy language (AST, Lexer, Parser, CodeGen, Core runtime, and JIT support).
	- `src/comlang/` — example programs and buildable sources for the language runtime and tools (`toy`, `main`).
	- `examples/` — example usage and a REPL implementation under `examples/comlang/`.
	- Top-level helpers: `KaleidoscopeJIT.h`, `main.cpp`, and `toy.cpp` (some at project root and under `src/comlang/` for parallel examples).

## Modifications and Implementation

This fork/working copy includes the following notable implementations and changes (concise):

- Implemented a small expression language (the "toy/comlang") with:
	- A hand-written `Lexer` and `Parser` able to parse numeric literals, identifiers, function prototypes, and simple expressions.
	- An `AST` hierarchy representing expressions, prototypes, and function bodies.
	- `CodeGen` that lowers the AST to LLVM IR, suitable for JIT execution via a lightweight Kaleidoscope-style JIT wrapper.
- Added `KaleidoscopeJIT.h` to encapsulate JIT setup and symbol lookup using LLVM's ORC APIs. This provides a reusable interface for compiling LLVM IR modules in-memory and executing functions directly.
- Provided example binaries and entry points:
	- `toy` / `toy.cpp` — a small driver demonstrating parsing, IR generation, and immediate JIT execution of expressions.
	- `main` / `main.cpp` — an alternative entry that may integrate REPL-like behavior or test harnesses under `examples/comlang/repl.cpp`.
- Project layout normalization: headers consolidated under `include/comlang/` so other tools or external builds can include only the public headers.

## Build & Run (quick start)

This repository uses simple CMake files found in `examples/` and `lib/` to illustrate building. A minimal build sequence (macOS / Linux) is:

1. Create a build directory and run CMake:

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

2. Run the example JIT runner (from `src/comlang` or built binary location):

```bash
./toy
```

Notes: LLVM development headers and libraries are required to build; install LLVM via your preferred package manager (e.g., Homebrew on macOS) and point `cmake` to the correct LLVM installation if automatic discovery fails.

## Files of Interest

- `include/comlang/AST.h` — AST node definitions.
- `include/comlang/Lexer.h` — lexical scanner.
- `include/comlang/Parser.h` — parser for expressions and function prototypes.
- `include/comlang/CodeGen.h` — code generation interface to produce LLVM IR.
- `include/comlang/KaleidoscopeJIT.h` — lightweight ORC JIT wrapper used by examples.
- `src/comlang/main.cpp` — main runner demonstrating file. parse -> codegen -> JIT execution.

## Testing and Extending

- To experiment: modify or add source files under `src/comlang/`, update headers in `include/comlang/`, re-run CMake, and run the produced binary.
- To add a new language feature: extend the `AST` nodes, update the `Parser`, and implement lowering in `CodeGen`.

## Contact / Attribution

This repository is an educational sandbox derived from the Kaleidoscope tutorial and LLVM examples. Use it to learn and prototype; attribution to LLVM and the LLVM Project is advised when using larger parts of their code or examples.

---
Updated: April 2026 — overview and implementation notes added.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details. Copyright (c) 2026 North South University (NSU).