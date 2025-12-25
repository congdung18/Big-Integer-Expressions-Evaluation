# Big Integer Expression Evaluation (C++)

A C++ project that evaluates arithmetic expressions with **arbitrary-precision integers**, implemented from scratch using **custom Stack and Queue based on Linked Lists**.

---

## Features
- Big Integer arithmetic implemented using `std::string`
- Support basic operations: **addition (+), subtraction (-), multiplication (*), division (/)**
- Manual implementation of arithmetic algorithms (no built-in big integer libraries)
- Convert **infix expressions to postfix (Reverse Polish Notation)**
- Evaluate postfix expressions using custom Stack
- Fully custom data structures:
  - Stack (Linked List)
  - Queue (Linked List)

---

## Core Concepts
- Data Structures: Stack, Queue, Linked List
- Expression parsing and evaluation
- Reverse Polish Notation (Postfix)
- String-based arithmetic
- Modular C++ design (header / implementation separation)

---

## How to Use
1. Clone or pull the project to your local machine
2. Compile and run **`Main.cpp`**
   - The program should generate an `output.txt` file
3. Compile and run **`Test.cpp`**
4. If all test cases are correct, the console will print:
```text
    The files are identical
```
---

## File Structure
```text
├── BigIntHeader.hpp
├── BigIntImplementation.cpp
├── Main.cpp
├── Test.cpp
```

## File Description
**BigIntHeader.hpp:** Contains required libraries, data structure definitions, and function declarations.

**BigIntImplementation.cpp** Implements:
- Big Integer arithmetic operations
- Stack and Queue using Linked Lists
- Expression conversion (Infix → Postfix)
- Postfix expression evaluation

**Main.cpp:**
- Main executable file.
- Reads expressions, evaluates them, and writes results to output.txt.

**Test.cpp:** Testing utility used to compare the generated output with the expected output.