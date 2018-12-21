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
* \#define sqr(a) (a*a)\\
  
  int main(){\\
    int x=5;\\
    std::cout << sqr(x) << std::endl; //This will print out the result of x*x = 25\\
    return 0;\\
  }
* \#define ARRAY\_SIZE 200\\
    int array[ARRAY\_SIZE] // array is size 200\\
  \#undef ARRAY\_SIZE\\

  \#define ARRAY\_SIZE 100\\
  int array2[ARRAY\_SIZE] // array is size 100


