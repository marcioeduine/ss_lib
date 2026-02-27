# Copilot Instructions for `ss_lib`

This repository is a C utility library implementing custom versions of standard functions, all prefixed with `ss_`. The goal is to provide robust, readable, and reusable components for string, character, memory, and output operations.

## Project Structure & Conventions
- **All functions are prefixed with `ss_`** (e.g., `ss_strlen`, `ss_isalpha`).
- **Header:** All public APIs are declared in `ss_lib.h`.
- **Type Aliases:**
  - `text` = `char *` (string)
  - `matrix` = `char **` (array of strings)
  - `number` = `size_t`
  - `generic` = `void *`
- **Custom List Structure:** `t_list` is defined for generic linked lists.
- **Memory Management:** Functions returning `matrix` (e.g., `ss_split`) require freeing with `ss_free_matrix`.
- **No external dependencies**; pure C standard library only.

## Build & Usage
- **Build:** Use `make` (see Makefile for `make`, `make clean`, `make fclean`, `make re`).
- **Include:** `#include "ss_lib.h"`
- **Link:** Link the generated library as needed in your project.

## Key Patterns & Examples
- **String splitting:** Use `ss_split` and free with `ss_free_matrix`.
- **Character checks:** Use `ss_isalpha`, `ss_isdigit`, etc. for ASCII validation.
- **Output:** Use `ss_put*` functions to write to file descriptors.
- **Bug Note:** `ss_memset` currently returns the advanced pointer, not the original (see README warning).

## File Overview
- `ss_*.c`: Each file implements a single function or a small related group.
- `main.c`: For manual testing/examples (not a test suite).
- `Makefile`: Standard targets for build/clean.
- `README.md`: Full API documentation and usage examples.

## Project-Specific Advice for AI Agents
- **Follow the `ss_` prefix for all new functions.**
- **Use provided type aliases** for consistency.
- **Document any non-standard behavior** (e.g., deviations from standard C library behavior) in the README and function comments.
- **When adding new functions, update `ss_lib.h` and README.md`.**
- **No external libraries**—keep all code portable and dependency-free.
- **Testing:** Manual tests go in `main.c`.

## References
- See `README.md` for detailed function documentation and usage patterns.
- Use `ss_lib.h` as the source of truth for public API.

---
For any new patterns or conventions, update this file and the README to keep documentation in sync.
