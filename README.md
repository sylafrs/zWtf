## zWtf
### Presentation
A for C-beginner Exercice from the siteduzero website.

The aim of this project is to create a program that searches some acronyms from a dictionary and give his definition from another one, at the same line.

### Description
My program first store data in an array of structure manualy allocated.
Then, it sort this array (merge-sort).

When the array is loaded, the program ask the user to put an acronym,
Then, it searches the first structure of the array that contains the acronym (binary search)
When it's done, it enumarates every possible definition for the acronym typed. 

### Files

* *acronym.h* : Contains the definition of the Acronym structure (two pointers to char array (strings))
* *ressources.h* : Contains the declaration of the ressources.c functions
* *algorithms.h* : Contains the declaration of the algorithms.c functions
* *prog.c* : Contains the main function
* *ressources.c* : Contains functions that load, read and free the Acronyms
* *algorithms.c* : Contains useful functions (generic merge sort and binary search)
* *Makefile* : Do the "make" command and enjoy ;)
* *README.md* : What you are reading ;)