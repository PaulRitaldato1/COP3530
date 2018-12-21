# C++ Refresher

This is a quick refreshed on c++.

## Pre-processor
First we will go over pre-processor directives.
Im sure you have used \#include, \#ifndef, and \#define directives, but there are many more, and they are a lot more useful than you originally learned!
Pre-processor directives:
- Macros
    - define
    - undef
- Conditionals
    - ifdef
    - ifndef
    - if
    - else
    - elif
    - endif
    
Lets go into deteail about what each of these do, and what they are used for.

### Macros
#### define
When the pre-processor encounters this, it replaces every occurance of it in your code with what you defined. You can define anything you want (e.g functions, variables). The pre-processor does not understand c++ so you can define whatever, it simply replaces every occurance with whatever you defined. You may remember this is also how we define header files.
#### undef
Undef does the exact opposit of define. For lack of a better work it adds "scope" to your defines. I will show an example below.
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
### ifdef
ifdef(if defined) will allow a section of code to be compiled ONLY if it has been defined elsewhere with define.
### ifndef
ifndef (if not defined) will only compile a section of code if the specified define has not already been defined. This is used when creating header files to prevent compiling code multiple times.
### if, elif, else
These directives serve a similar purpose to what you would expect. They allow for code to be compiled upon completion of a condition. Any combination of these can be combined to form complete control structures for the pre-processor!
### endif
This directive must be at the end of all the previous directives mentioned. It serves to tell the pre-processor when the condition block of code has ended.

### Examples
* //ifdef example<br />
    \#ifdef ARRAY\_SIZE<br />
    int array[ARRAY\_SIZE] // This code is only compiled if ARRAY\_SIZE is defined. Preventing errors <br />
    \#endif
* //ifndef example<br />
    \#ifndef ARRAY\_SIZE<br />
    \#define ARRAY\_SIZE 10 //ARRAY\_SIZE is only defined if it hasnt previously been defined<br />
    \#endif
* //if, elif, else example<br />
    \#if ARRAY\_SIZE>500<br />
    \#undef ARRAY\_SIZE<br />
    \#define ARRAY\_SIZE 100<br />
<br />
    \#elif ARRAY\_SIZE<100<br />
    \#undef ARRAY\_SIZE<br />
    \#define ARRAY\_SIZE 100<br />
<br />
    \#else<br />
    \#undef ARRAY\_SIZE<br />
    \#define ARRAY\_SIZE 100<br />
    \#endif

`code`
