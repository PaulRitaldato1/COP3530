# C++ Refresher

This is a quick refreshed on c++.

## Pre-processor
First we will go over pre-processor directives.

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
When the pre-processor encounters this, it replaces every occurance of it in your code with what you defined. You can define anything you want (e.g functions, variables). The pre-processor does not understand c++ so you can define whatever, it simply replaces every occurance with whatever you defined.
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


