# MyFirstLanguage Frontend — Design mapping

This folder outlines a suggested file structure for implementing the "MyFirstLanguage"
frontend following LLVM's "MyFirstLanguageFrontend" tutorial.

Suggested repo layout (place under project root):

- examples/comlang/              — Example REPL and small frontend demo (this repo)
  - CMakeLists.txt                  — Example build target
  - repl.cpp                        — REPL/driver (lexer+parser+AST)

- include/comlang/              — Public headers (AST, Parser, CodeGen interfaces)
  - AST.h
  - Lexer.h
  - Parser.h
  - CodeGen.h

- src/comlang/                  — Implementation sources
  - Lexer.cpp
  - Parser.cpp
  - CodeGen.cpp

- lib/                              — Reusable libraries and passes
  - CMakeLists.txt

- tools/                            — Compiler tools (opt, custom tool drivers)

- tests/                            — Unit tests (parser, codegen, IR checks)

- docs/                             — Design notes, tutorial mapping, diagrams
  - design/comlang/structure.md  — (this file)

Notes mapping to LLVM tutorial:
- Lexer/Parser/AST: implement in `include/myfirstlang` + `src/myfirstlang`.
- CodeGen: produce LLVM IR in `src/myfirstlang/CodeGen.cpp` using LLVM APIs.
- Tooling: add an `opt`-like tool in `tools/` to load IR and run passes.
- Tests: add regression tests that compile example source into IR and validate output.

Build: add `CMakeLists.txt` entries to build the example and libraries, and install targets.
