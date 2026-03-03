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
  - [Utility Functions](#utility-functions)
  - [Number Conversion](#number-conversion)
- [Compilation](#compilation)
- [Usage Examples](#usage-examples)

## Overview

`ss_lib` is a custom C library that implements common standard library functions with the `ss_` prefix. It provides a robust set of utilities for string operations, character validation, file descriptor output, and memory handling. The library uses ISO 646 boolean operators (`not`, `and`, `or`, `xor`) for improved code consistency across multiple programming languages.

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

The library uses the following type aliases for improved readability and cross-language compatibility:

| Type | Definition | Description |
|------|------------|-------------|
| `text` | `char *` | Pointer to a character string |
| `matrix` | `char **` | Pointer to an array of strings (2D array) |
| `number` | `long long` | Long long integer type for sizes, counts, and numeric operations |
| `generic` | `void *` | Generic pointer type for flexible memory handling |

### Structures

#### `t_list`
```c
typedef struct s_list
{
	generic			content;  // Pointer to the node's content
	number			size;     // Size of the content
	struct s_list	*next;    // Pointer to the next node
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

**Notes:** Returns 0 if the string is NULL.

---

#### `ss_strchr`
```c
text ss_strchr(const text s, number c);
```
**Description:** Locates the first occurrence of a character in a string.

**Parameters:**
- `s`: The string to search
- `c`: The character to locate (passed as `number`, cast to `char`)

**Returns:** Pointer to the first occurrence of the character, or `NULL` if not found. Also returns a pointer to the end of the string if searching for the null terminator.

---

#### `ss_strrchr`
```c
text ss_strrchr(const text s, number c);
```
**Description:** Locates the last occurrence of a character in a string.

**Parameters:**
- `s`: The string to search
- `c`: The character to locate (passed as `number`, cast to `char`)

**Returns:** Pointer to the last occurrence of the character, or `NULL` if not found

---

#### `ss_strdup`
```c
text ss_strdup(const text s);
```
**Description:** Creates a duplicate of a string by allocating memory and copying the content.

**Parameters:**
- `s`: The string to duplicate

**Returns:** Pointer to the newly allocated duplicate string, or `NULL` on failure or if `s` is NULL

**Memory:** The caller is responsible for freeing the returned string using `free()`.

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

**Returns:** Newly allocated substring, or `NULL` if the starting index is beyond the string length

**Notes:**
- If `start + length` exceeds the string length, the substring is truncated to the available characters
- The returned substring is dynamically allocated and must be freed by the caller

**Memory:** The caller is responsible for freeing the returned substring.

---

#### `ss_strtrim`
```c
text ss_strtrim(const text s, const text charset);
```
**Description:** Removes characters from the beginning and end of a string that match any character in the charset.

**Parameters:**
- `s`: The string to trim
- `charset`: Set of characters to remove from both ends

**Returns:** Newly allocated trimmed string, or `NULL` on failure or if parameters are invalid

**Notes:** Only removes characters from the beginning and end; interior occurrences are preserved.

**Memory:** The caller is responsible for freeing the returned string.

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
- The returned matrix must be freed using `ss_free_matrix()`
- Consecutive delimiters are treated as a single separator
- Empty strings resulting from splitting are omitted
- Use `ss_world_counter()` to obtain the number of words for proper deallocation

---

#### `ss_strljoin`
```c
text ss_strljoin(const text dest, const text src, number length);
```
**Description:** Concatenates a source string with a limited number of characters from another string.

**Parameters:**
- `dest`: The destination string (base string)
- `src`: The source string to append
- `length`: Maximum number of characters to append from `src`

**Returns:** Newly allocated concatenated string, or `NULL` on failure or if parameters are invalid

**Notes:** If `length` exceeds the length of `src`, only the available characters from `src` are appended.

**Memory:** The caller is responsible for freeing the returned string.

---

### Character Classification

All character classification functions return `true` if the character meets the specified criteria, `false` otherwise. They accept a `number` parameter (though typically a single character).

#### `ss_isascii`
```c
bool ss_isascii(number c);
```
**Description:** Verifies whether a character is a valid ASCII character.

**Returns:** `true` if `0 ≤ c ≤ 127`, `false` otherwise

---

#### `ss_isalpha`
```c
bool ss_isalpha(number c);
```
**Description:** Verifies whether a character is an alphabetic letter.

**Returns:** `true` if the character is lowercase (a-z) or uppercase (A-Z), `false` otherwise

---

#### `ss_isdigit`
```c
bool ss_isdigit(number c);
```
**Description:** Verifies whether a character is a decimal digit.

**Returns:** `true` if the character is 0-9, `false` otherwise

---

#### `ss_isalnum`
```c
bool ss_isalnum(number c);
```
**Description:** Verifies whether a character is alphanumeric.

**Returns:** `true` if the character is a letter or digit, `false` otherwise

---

#### `ss_isprint`
```c
bool ss_isprint(number c);
```
**Description:** Verifies whether a character is printable, including space.

**Returns:** `true` if `32 ≤ c ≤ 126`, `false` otherwise

---

#### `ss_islower`
```c
bool ss_islower(number c);
```
**Description:** Verifies whether a character is a lowercase letter.

**Returns:** `true` if the character is a-z, `false` otherwise

---

#### `ss_isupper`
```c
bool ss_isupper(number c);
```
**Description:** Verifies whether a character is an uppercase letter.

**Returns:** `true` if the character is A-Z, `false` otherwise

---

#### `ss_isspace`
```c
bool ss_isspace(number c);
```
**Description:** Verifies whether a character is whitespace.

**Returns:** `true` if the character is space (32), tab (9), newline (10), vertical tab (11), form feed (12), or carriage return (13), `false` otherwise

---

#### `ss_isnumber_limit`
```c
bool ss_isnumber_limit(double n);
```
**Description:** Verifies whether a number exceeds the limits of a `long long` integer.

**Parameters:**
- `n`: A double value to check

**Returns:** `true` if `n < LLONG_MIN` or `n > LLONG_MAX`, `false` otherwise

**Notes:** Used internally by `ss_tonumber()` to validate number conversion boundaries.

---

### Output Functions

All output functions write to a specified file descriptor. They use ISO 646 operators for consistency.

#### `ss_putchar_fd`
```c
void ss_putchar_fd(char c, number fd);
```
**Description:** Writes a single character to a file descriptor.

**Parameters:**
- `c`: The character to write
- `fd`: The file descriptor (e.g., 1 for standard output)

---

#### `ss_putstr_fd`
```c
void ss_putstr_fd(const text s, number fd);
```
**Description:** Writes a string to a file descriptor.

**Parameters:**
- `s`: The string to write
- `fd`: The file descriptor

**Notes:** If `s` is NULL, writes the string "(null)" instead.

---

#### `ss_putendl_fd`
```c
void ss_putendl_fd(const text s, number fd);
```
**Description:** Writes a string followed by a newline character to a file descriptor.

**Parameters:**
- `s`: The string to write
- `fd`: The file descriptor

---

#### `ss_putnbr_fd`
```c
void ss_putnbr_fd(number _number, number fd);
```
**Description:** Writes an integer to a file descriptor.

**Parameters:**
- `_number`: The integer to write (type `number`, which is `long long`)
- `fd`: The file descriptor

**Notes:** Handles special case of `LLONG_MIN` by converting it to text first due to mathematical limitations.

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

**Notes:** Internally uses `ss_memset()` to initialise allocated memory to zero.

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

**Returns:** Pointer to the advanced memory location after filling (note: this differs from standard `memset`)

**Warning:** Returns the advanced pointer instead of the original pointer, which differs from the standard C `memset()` behaviour.

---

#### `ss_free_matrix`
```c
void ss_free_matrix(matrix _matrix, number size);
```
**Description:** Frees a matrix (2D array) created by functions like `ss_split()`.

**Parameters:**
- `_matrix`: The matrix to free
- `size`: Number of rows in the matrix

**Notes:** Safely handles NULL pointers and sets the pointer to NULL after freeing.

---

### Utility Functions

#### `ss_world_counter`
```c
number ss_world_counter(const text s);
```
**Description:** Counts the number of words in a string by counting whitespace characters after trimming.

**Parameters:**
- `s`: The string to analyse

**Returns:** The number of words in the string (0 if string is empty or NULL)

**Notes:** Trims leading and trailing whitespace, then counts internal whitespace occurrences. Useful for determining the size needed when freeing matrices from `ss_split()`.

---

#### `ss_swap`
```c
ss_swap(a, b)
```
**Description:** Macro that swaps the values of two variables.

**Parameters:**
- `a`: First variable
- `b`: Second variable

**Notes:** This is a macro defined as `#define ss_swap(a, b) _ss_swap((generic *)&(a), (generic *)&(b))` that calls the internal `_ss_swap()` function. Works with any data type by treating operands as generic pointers.

---

### Number Conversion

#### `ss_tonumber`
```c
number ss_tonumber(const text s);
```
**Description:** Converts a string to a `long long` integer.

**Parameters:**
- `s`: The string to convert

**Returns:** The converted number, or 0 if the string is invalid, empty, or the number exceeds `long long` bounds

**Notes:**
- Skips leading whitespace
- Handles optional leading '+' or '-' sign
- Validates against `LLONG_MIN` and `LLONG_MAX` limits
- Returns 0 if the number exceeds limits

---

#### `ss_totext`
```c
text ss_totext(number n);
```
**Description:** Converts a `long long` integer to a dynamically allocated string.

**Parameters:**
- `n`: The integer to convert

**Returns:** Newly allocated string representation of the number, or `NULL` on failure

**Notes:**
- Handles special case of `LLONG_MIN` explicitly
- Returns "0" for the value 0
- The returned string must be freed by the caller
- Correctly handles negative numbers

**Memory:** The caller is responsible for freeing the returned string.

---

## Compilation

The library includes a Makefile for easy compilation. Available targets:

```bash
make        # Builds the static library (ss_lib.a)
make clean  # Removes object files
make fclean # Removes object files and library
make re     # Rebuilds the library from scratch
make main   # Builds the library and compiles main.c with it
```

### Build Flags

The Makefile uses the following compilation flags:
- `-Wall`: Enable all standard warnings
- `-Wextra`: Enable extra warnings
- `-Werror`: Treat warnings as errors
- `-std=c99`: Use C99 standard

---

## Usage Examples

### Example 1: String Splitting
```c
#include "ss_lib.h"
#include <stdio.h>

int main(void)
{
	text str = "Hello,World,from,ss_lib";
	matrix words = ss_split(str, ",");
	number word_count = ss_world_counter(str);
	
	for (number i = 0; words[i]; i++)
		ss_putendl_fd(words[i], 1);
	
	ss_free_matrix(words, word_count);
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

### Example 4: Number Conversion
```c
#include "ss_lib.h"

int main(void)
{
	text num_str = "12345";
	number num = ss_tonumber(num_str);
	text back_to_str = ss_totext(num);
	
	ss_putendl_fd(back_to_str, 1);  // Outputs: "12345"
	free(back_to_str);
	
	return (0);
}
```

### Example 5: Memory Allocation
```c
#include "ss_lib.h"

int main(void)
{
	number *array = (number *)ss_calloc(10, sizeof(number));
	
	if (not array)
		return (1);
	
	// All elements are initialised to 0
	ss_putnbr_fd(array[5], 1);  // Outputs: "0"
	
	free(array);
	return (0);
}
```

---

## Code Style

This library uses ISO 646 boolean operators (`not`, `and`, `or`, `xor`) instead of standard C operators for enhanced code consistency across multiple programming languages (C, Python, GDScript).

**Example:**
```c
if (not s)
	return (0);

while (i < length and s[i])
	i++;

if (ss_isalpha(c) and ss_isupper(c))
	// ...
```

---

## Licence

This project is open source. Please refer to the repository for licence information.

## Author

Developed by Márcio Eduine, the Ser Superior (SS).

## Contributing

Contributions, issues, and feature requests are welcome. Feel free to check the issues page.
