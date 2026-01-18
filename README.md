# SS Library

A comprehensive C language library providing fundamental utility functions for string manipulation, character classification, memory management, and output operations.

## Table of Contents

- [Overview](#overview)
- [Installation](#installation)
- [Type Definitions](#type-definitions)
- [Function Reference](#function-reference)
  - [String Functions](#string-functions)
  - [Character Classification](#character-classification)
  - [Output Functions](#output-functions)
  - [Memory Management](#memory-management)
- [Compilation](#compilation)
- [Usage Examples](#usage-examples)

## Overview

`ss_lib` is a custom C library that implements common standard library functions with the `ss_` prefix. It provides a robust set of utilities for string operations, character validation, file descriptor output, and memory handling.

## Installation

Clone the repository and compile the library:

```bash
git clone https://github.com/marcioeduine/ss_lib.git
cd ss_lib
make
```

Include the header file in your project: 

```c
#include "ss_lib.h"
```

## Type Definitions

The library uses the following type aliases for improved readability:

| Type | Definition | Description |
|------|------------|-------------|
| `text` | `char *` | Pointer to a character string |
| `matrix` | `char **` | Pointer to an array of strings (2D array) |
| `number` | `size_t` | Unsigned integer type for sizes and counts |
| `generic` | `void *` | Generic pointer type |

### Structures

#### `t_list`
```c
typedef struct s_list
{
    generic         content;  // Pointer to the node's content
    number          size;     // Size of the content
    struct s_list   *next;    // Pointer to the next node
} t_list;
```

## Function Reference

### String Functions

#### `ss_strlen`
```c
number ss_strlen(const text s);
```
**Description:** Calculates the length of a null-terminated string.

**Parameters:**
- `s`: The string to measure

**Returns:** The number of characters in the string (excluding null terminator)

---

#### `ss_strchr`
```c
text ss_strchr(const text s, number c);
```
**Description:** Locates the first occurrence of a character in a string.

**Parameters:**
- `s`: The string to search
- `c`: The character to locate

**Returns:** Pointer to the first occurrence of the character, or `NULL` if not found

---

#### `ss_strrchr`
```c
text ss_strrchr(const text s, number c);
```
**Description:** Locates the last occurrence of a character in a string.

**Parameters:**
- `s`: The string to search
- `c`: The character to locate

**Returns:** Pointer to the last occurrence of the character, or `NULL` if not found

---

#### `ss_strdup`
```c
text ss_strdup(const text s);
```
**Description:** Creates a duplicate of a string by allocating memory and copying the content.

**Parameters:**
- `s`: The string to duplicate

**Returns:** Pointer to the newly allocated duplicate string, or `NULL` on failure

---

#### `ss_substr`
```c
text ss_substr(const text s, number start, number length);
```
**Description:** Extracts a substring from a given string.

**Parameters:**
- `s`: The source string
- `start`: The starting index
- `length`: The maximum number of characters to extract

**Returns:** Newly allocated substring, or `NULL` on failure

**Notes:**
- If `start` is beyond the string length, returns `NULL`
- If `start + length` exceeds the string length, the substring is truncated

---

#### `ss_strtrim`
```c
text ss_strtrim(const text s, const text charset);
```
**Description:** Removes characters from the beginning and end of a string that match any character in the charset.

**Parameters:**
- `s`: The string to trim
- `charset`: Set of characters to remove

**Returns:** Newly allocated trimmed string, or `NULL` on failure

---

#### `ss_split`
```c
matrix ss_split(const text s, const text charset);
```
**Description:** Splits a string into an array of substrings using delimiters specified in charset.

**Parameters:**
- `s`: The string to split
- `charset`: Set of delimiter characters

**Returns:** Null-terminated array of strings (matrix), or `NULL` on failure

**Notes:**
- The returned matrix must be freed using `ss_free_matrix`
- Consecutive delimiters are treated as a single separator

---

#### `ss_world_counter`
```c
number ss_world_counter(const text s);
```
**Description:** Counts the number of words in a string (note: likely "word_counter" in intent).

**Parameters:**
- `s`: The string to analyse

**Returns:** The number of words in the string

---

### Character Classification

All character classification functions return `true` if the character matches the criteria, `false` otherwise.

#### `ss_isascii`
```c
bool ss_isascii(int c);
```
**Description:** Checks if a character is a valid ASCII character (0-127).

---

#### `ss_isalpha`
```c
bool ss_isalpha(number c);
```
**Description:** Checks if a character is an alphabetic letter (a-z, A-Z).

---

#### `ss_isdigit`
```c
bool ss_isdigit(number c);
```
**Description:** Checks if a character is a decimal digit (0-9).

---

#### `ss_isalnum`
```c
bool ss_isalnum(number c);
```
**Description:** Checks if a character is alphanumeric (letter or digit).

---

#### `ss_isprint`
```c
bool ss_isprint(number c);
```
**Description:** Checks if a character is printable (including space).

---

#### `ss_islower`
```c
bool ss_islower(number c);
```
**Description:** Checks if a character is a lowercase letter. 

---

#### `ss_isupper`
```c
bool ss_isupper(number c);
```
**Description:** Checks if a character is an uppercase letter. 

---

#### `ss_isspace`
```c
bool ss_isspace(number c);
```
**Description:** Checks if a character is whitespace (space, tab, newline, etc.).

---

### Output Functions

All output functions write to a specified file descriptor. 

#### `ss_putchar_fd`
```c
void ss_putchar_fd(char c, number fd);
```
**Description:** Writes a single character to a file descriptor.

**Parameters:**
- `c`: The character to write
- `fd`: The file descriptor (e.g., 1 for stdout)

---

#### `ss_putstr_fd`
```c
void ss_putstr_fd(const text s, number fd);
```
**Description:** Writes a string to a file descriptor.

**Parameters:**
- `s`: The string to write
- `fd`: The file descriptor

---

#### `ss_putendl_fd`
```c
void ss_putendl_fd(const text s, number fd);
```
**Description:** Writes a string followed by a newline to a file descriptor.

**Parameters:**
- `s`: The string to write
- `fd`: The file descriptor

---

#### `ss_putnbr_fd`
```c
void ss_putnbr_fd(int _number, number fd);
```
**Description:** Writes an integer to a file descriptor.

**Parameters:**
- `_number`: The integer to write
- `fd`: The file descriptor

---

### Memory Management

#### `ss_calloc`
```c
generic ss_calloc(number member, number size);
```
**Description:** Allocates memory for an array and initialises all bytes to zero.

**Parameters:**
- `member`: Number of elements
- `size`: Size of each element in bytes

**Returns:** Pointer to allocated memory, or `NULL` on failure

---

#### `ss_memset`
```c
generic ss_memset(generic s, number c, number length);
```
**Description:** Fills a block of memory with a specified value.

**Parameters:**
- `s`: Pointer to the memory block
- `c`: The value to set (converted to unsigned char)
- `length`: Number of bytes to set

**Returns:** Pointer to the memory block, or `NULL` if `s` is `NULL`

**Warning:** The current implementation has a bug - it returns the advanced pointer instead of the original pointer.

---

#### `ss_free_matrix`
```c
void ss_free_matrix(matrix _matrix, number size);
```
**Description:** Frees a matrix (2D array) created by functions like `ss_split`.

**Parameters:**
- `_matrix`: The matrix to free
- `size`: Number of rows in the matrix

---

## Compilation

The library includes a Makefile for easy compilation.  Available targets:

```bash
make        # Builds the library
make clean  # Removes object files
make fclean # Removes object files and library
make re     # Rebuilds the library from scratch
```

## Usage Examples

### Example 1: String Splitting
```c
#include "ss_lib.h"
#include <stdio.h>

int main(void)
{
    text str = "Hello,World,from,ss_lib";
    matrix words = ss_split(str, ",");
    
    for (number i = 0; words[i]; i++)
        ss_putendl_fd(words[i], 1);
    
    ss_free_matrix(words, ss_world_counter(str));
    return (0);
}
```

### Example 2: Character Validation
```c
#include "ss_lib.h"

int main(void)
{
    char c = 'A';
    
    if (ss_isalpha(c))
        ss_putstr_fd("It's a letter!\n", 1);
    if (ss_isupper(c))
        ss_putstr_fd("It's uppercase!\n", 1);
    
    return (0);
}
```

### Example 3: String Trimming
```c
#include "ss_lib.h"

int main(void)
{
    text str = "   trim me   ";
    text trimmed = ss_strtrim(str, " ");
    
    ss_putendl_fd(trimmed, 1);  // Outputs: "trim me"
    free(trimmed);
    
    return (0);
}
```

## Licence

This project is open source.  Please refer to the repository for licence information.

## Author

Developed by Márcio Eduine, the Ser Superior (SS).

## Contributing

Contributions, issues, and feature requests are welcome.  Feel free to check the issues page. 
