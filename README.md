# Java Compiler

This project is a simplified Java compiler developed using **Flex** and **Bison** in **C**. It performs lexical and syntax analysis, builds and manages a symbol table, and parses a subset of Java-like code including classes, methods, expressions, control structures, and exception handling.

It also handles **semantic analysis**, generates **quadruples**, performs **basic optimizations**, and produces **object code**.

---

##  Features

- **Lexical analysis** with Flex  
- **Syntax analysis** with Bison  
- **Semantic analysis**  
- **Symbol table management**  
- **Support for**:
  - Class, method, and constructor declarations  
  - Control structures 
  - Expressions: arithmetic, logical, assignment, method calls, etc.  
  - Arrays and matrices  
  - Exception handling  
- **Intermediate code generation** (quadruplets)  
- **Basic optimization**  
- **Object code generation**  
- **Type and scope tracking**  
- 🧪 Error reporting (syntax and undeclared identifiers)

---

## 🧰 Requirements

Flex, Bison, GCC

---

## ⚙️ Compilation Instructions

To compile and run the compiler, you have two options:

### ▶️ Option 1: Run the batch script

```bash
commands.bat
