*This project has been created as part of the 42 curriculum by rafcrist.*

# Libft

## Description

Libft is a C library created as part of the 42 curriculum.
The goal of this project is to recreate several standard C library functions and implement additional utility functions that can be reused in future projects.

This library includes functions for character checking, string manipulation, memory manipulation, number conversion, file descriptor output, and linked list manipulation.

## Library overview

The library is divided into three main parts:

### Part 1 - Libc functions

This part contains reimplementations of common libc functions, such as:

* character checking functions
* memory functions
* string functions
* conversion functions

Examples:

* `ft_strlen`
* `ft_memset`
* `ft_memcpy`
* `ft_atoi`
* `ft_strdup`

### Part 2 - Additional functions

This part contains useful functions that are not directly part of libc, such as:

* `ft_substr`
* `ft_strjoin`
* `ft_strtrim`
* `ft_split`
* `ft_itoa`
* file descriptor output functions

### Part 3 - Linked list functions

This part contains functions to create and manipulate linked lists using the `t_list` structure.

Examples:

* `ft_lstnew`
* `ft_lstadd_front`
* `ft_lstsize`
* `ft_lstlast`
* `ft_lstadd_back`
* `ft_lstclear`
* `ft_lstmap`

## Instructions

To compile the library, run:

```bash
make
```

This will generate the static library:

```bash
libft.a
```

To remove object files:

```bash
make clean
```

To remove object files and the library:

```bash
make fclean
```

To rebuild the project from scratch:

```bash
make re
```

## Resources

Resources used during this project:

* C manual pages
* 42 Libft subject
* Peer discussions
* Notes and personal testing

AI was used as a learning support tool to explain concepts, review reasoning, and help understand difficult topics such as memory allocation, function prototypes, Makefile structure, and linked lists.

AI support was used to guide the learning process step by step, with focus on understanding the logic behind the code rather than simply copying final solutions.
