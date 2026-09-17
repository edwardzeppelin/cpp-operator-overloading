# C++ Operator Overloading Demo: Coords & Dynamic Stack

An educational C++ project demonstrating custom operator overloading for mathematical 3D coordinates and a custom dynamically allocated linked-list stack implementation.

## Features

* **Custom Stack Implementation**: Built on top of a singly linked list with dynamic node allocation and deep copy assignment.
* **Coordinate Manipulations**: 3D coordinate logic with overloaded unary, binary, and I/O operators.
* **Overloaded Operators**:
  * **Coords**: `!`, prefix/postfix `++` and `--`, `<<`.
  * **Stack**: `=`, `==`, `<`, `>`, `!`, `-`, `-=`, `/`, `/=`, `<<`, `>>`.
* **Interactive CLI**: Menu-driven console interface with randomized initial data generation.

## Project Structure

* `coords.h` / `coords.cpp` — 3D coordinate class definition and operator implementations.
* `stack.h` / `stack.cpp` — Node-based dynamic stack data structure with arithmetic operator overloads.
* `main.cpp` — Interactive console application and testbench.

## How to Build and Run

### Using GCC / Clang

```bash
g++ -std=c++11 main.cpp coords.cpp stack.cpp -o app
./app
```
