# C++ Refresher

This is a quick refreshed on c++.

## Pre-processor
First we will go over pre-processor directives.
Im sure you have used \#include, \#ifndef, and \#define directives, but there are many more, and they are a lot more useful than you originally learned!
Pre-processor directives:
- Macros
    - define
    - undef
    - pragma once
- Conditionals
    - ifdef
    - ifndef
    - if
    - else
    - elif
    - endif
- Includes
    - include <>
    - include ""
<br />
Lets go into detail about what each of these do, and what they are used for.

### Macros
#### define
When the pre-processor encounters this, it replaces every occurance of it in your code with what you defined. You can define anything you want (e.g functions, variables). The pre-processor does not understand c++ so you can define whatever, it simply replaces every occurance with whatever you defined. You may remember this is also how we define header files.
#### undef
Undef does the exact opposit of define. For lack of a better work it adds "scope" to your defines. I will show an example below.
#### pragma once
This can be used at the top of a header file to replace the standard ifndef, define, and endif statements.
#### Examples
* \#define ARRAY\_SIZE 500 <br />
  int array[ARRAY\_SIZE] //Array is size 500
* \#define sqr(a) (a*a)<br />
 
  int main(){<br />
    int x=5;<br />
    std::cout << sqr(x) << std::endl; //This will print out the result of x*x = 25<br />
    return 0;<br />
  }
* \#define ARRAY\_SIZE 200<br />
    int array[ARRAY\_SIZE] // array is size 200<br />
  \#undef ARRAY\_SIZE<br />

  \#define ARRAY\_SIZE 100<br />
  int array2[ARRAY\_SIZE] // array is size 100

### Conditionals
#### ifdef
ifdef(if defined) will allow a section of code to be compiled ONLY if it has been defined elsewhere with define.
#### ifndef
ifndef (if not defined) will only compile a section of code if the specified define has not already been defined. This is used when creating header files to prevent compiling code multiple times.
#### if, elif, else
These directives serve a similar purpose to what you would expect. They allow for code to be compiled upon completion of a condition. Any combination of these can be combined to form complete control structures for the pre-processor!
#### endif
This directive must be at the end of all the previous directives mentioned. It serves to tell the pre-processor when the condition block of code has ended.

#### Examples
* //ifdef example<br />
    \#ifdef ARRAY\_SIZE<br />
    int array[ARRAY\_SIZE] // This code is only compiled if ARRAY\_SIZE is defined. Preventing errors <br />
    \#endif
* //ifndef example<br />
    \#ifndef ARRAY\_SIZE<br />
    \#define ARRAY\_SIZE 10 //ARRAY\_SIZE is only defined if it hasnt previously been defined<br />
    \#endif
*  //if, elif, else example<br />
   \#if ARRAY\_SIZE>500<br />
    \#undef ARRAY\_SIZE<br />
    \#define ARRAY\_SIZE 100<br />
    \#elif ARRAY\_SIZE<100<br />
    \#undef ARRAY\_SIZE<br />
    \#define ARRAY\_SIZE 100<br />
    \#else<br />
    \#undef ARRAY\_SIZE<br />
    \#define ARRAY\_SIZE 100<br />
    \#endif

### Includes
#### include <>
This with the angle brackets is used to include files provided by implementation (on linux it searches known file paths from root or /). This is for including standard library headers, and has a pre-defined search path (depending on implementation).
#### include ""
This include is used for including headers from your current path. The path that is used as a base search is the directory of the file with this include.

#### Both
In both of these you can include a path to a certain file. By default \#include<> has pre defined search paths, and \#include"" only searches the current directory of the file that it is declared in. If you have a directory structure you can specify that in the path. See examples below.

#### Examples
* \#include\<vector\> //Standard library
* \#include "bin/myHeader.h" //Starting from the current file path, search in the bin directory for myHeader.h

## Pointers and References
Pointers are your friends! <br />

### Pointers
Pointers are variables that store a memory address. Pointers need to be dereferenced with the * operator to access the data at its given memory address. Pointers just hold a memory address, so they can point to anything (ex. variables, objects, files). You can also use pointers to do "pointer math" to traverse through arrays. The way to read pointers is from right to left. So the expression "const int\*" is read as "pointer to a int constant".

### Practice
* int\* const
  <details><summary> SHOW ANSWER </summary> 
    constant pointer to an integer
    </details>

### Examples
* int a = 5; //Declare and initialize an int <br />
  int\* pa = &a;//Assign the pointer pa to the address of a<br />
  std::cout << "The address of a is: " << pa << "\nThe value at that address is: " << \*pa << std::endl; //print the address and value of a <br />
### References
