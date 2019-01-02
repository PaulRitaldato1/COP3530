# C++ Refresher

## Getting Started
First things first, you will need to be able to create/edit C++ (.cpp/.h) files, and you will need to be able to compile/run them. <br /><br />
Here are a few ways you may want to go about this:
### IDEs
- Clion (Windows 64-bit, Mac, Linux 64-bit)
- VisualStudio (Windows)
- Code::Blocks (Any)
### Command Line
<details><summary> Linux </summary>

 
* <details><summary> Debian based systems (Ubuntu Included) </summary> 
		
	#### To install the g++ compiler open a terminal and type:
		sudo apt install g++
	#### To compile a .cpp file run the command:
		g++ -std=c++11 myProg.cpp -o myProg
	#### To run the file simply type the command:
		./myProg
	#### To combine these into a single command:
		g++ -std=c++11 myProg.cpp -o myProg && ./myProg
	</details>


* <details><summary> Arch based systems </summary>

	#### To install the g++ compiler open a terminal and type:
		sudo pacman -S g++
	#### To compile a .cpp file run the command:
		g++ -std=c++11 myProg.cpp -o myProg
	##### To run the file simply type the command:
		./myProg
	#### To combine these into a single command:
		g++ -std=c++11 myProg.cpp -o myProg && ./myProg
	</details>


</details>
<details><summary> Windows </summary> 


In windows you have two options:


1. <details><summary> Windows Subsystem for Linux (WSL)(recommended) </summary>
	To install WSL follow these instructions: <br />
	1. Open powershell as an <b>administrator</b> <br />
	2. Copy and paste this command into powershell: <br />
	<code>Enable-WindowsOptionalFeature -Online -FeatureName 	Microsoft-Windows-Subsystem-Linux </code><br />
	3. Restart your computer <br />
	4. Open the Windows/Microsoft store and search for "Ubuntu" <br />
	5. Install Ubuntu <br />
	6. Run it, then create a username and password as prompted <br />
	

	#### To install the g++ compiler open the ubuntu terminal you just installed and type:
		sudo apt install g++
	#### To compile a .cpp file run the command:
		g++ -std=c++11 myProg.cpp -o myProg
	#### To run the file simply type the command:
		./myProg
	#### To combine these into a single command:
		g++ -std=c++11 myProg.cpp -o myProg && ./myProg
	</details>


2. <details><summary> Cygwin (recommended) </summary>
	To install Cygwin follow this tutorial:

	<a href="http://www.youtube.com/watch?feature=player_embedded&v=dDbCZB1Mx-E" target="_blank"><img 	src="https://www.youtube.com/watch?v=dDbCZB1Mx-E/0.jpg" alt="Cygwin Tutorial" width="240" 		height="180" border="10" /></a>
	</details>
			
		
</details>
<details><summary>Mac</summary>
Instructions to install g++ on a mac:

1. Open a terminal and type "g++"
2. Click install on the menu that pops up
	#### To compile a .cpp file run the command:
		g++ -std=c++11 myProg.cpp -o myProg
	#### To run the file simply type the command:
		./myProg
	#### To combine these into a single command:
		g++ -std=c++11 myProg.cpp -o myProg && ./myProg

</details>


## Pre-processor
First, we will go over pre-processor directives.


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
When the pre-processor encounters this, it replaces every occurance of it in your code with what you defined. You can define anything you want (e.g functions, variables). The pre-processor does not understand c++ so you can define anything, it simply replaces every occurance with what you defined. You may remember this is also how we define header files.
#### undef
Undef does the exact opposit of define. For lack of a better word it adds "scope" to your defines. I will show an example below.
#### pragma once
This can be used at the top of a header file to replace the standard ifndef, define, and endif statements.
#### Examples
* <pre><code>#define ARRAY\_SIZE 500 <br />
  int array[ARRAY\_SIZE] //Array is size 500</code></pre>
* <pre><code>#define sqr(a) (a\*a)<br />
 
  int main(){<br />
    int x=5;<br />
    std::cout << sqr(x) << std::endl; //This will print out the result of x*x = 25<br />
    return 0;<br />
  }</code></pre>
* <pre><code>#define ARRAY\_SIZE 200<br />
    int array[ARRAY\_SIZE] // array is size 200<br />
  \#undef ARRAY\_SIZE<br />

  \#define ARRAY\_SIZE 100<br />
  int array2[ARRAY\_SIZE] // array is size 100</code></pre>
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
* <pre><code>//ifdef example<br />
    #ifdef ARRAY\_SIZE<br />
    int array[ARRAY\_SIZE] // This code is only compiled if ARRAY\_SIZE is defined. Preventing errors <br />
    #endif</code></pre>
* <pre><code>//ifndef example<br />
    #ifndef ARRAY\_SIZE<br />
    #define ARRAY\_SIZE 10 //ARRAY\_SIZE is only defined if it hasnt previously been defined<br />
    #endif</code></pre>
*  <pre><code>//if, elif, else example
   	#if ARRAY\_SIZE>500<br />
    	#undef ARRAY\_SIZE<br />
    	#define ARRAY\_SIZE 100<br />
    #elif ARRAY\_SIZE<100<br />
    	#undef ARRAY\_SIZE<br />
    	#define ARRAY\_SIZE 100<br />
    #else<br />
    	#undef ARRAY\_SIZE<br />
    	#define ARRAY\_SIZE 100<br />
    #endif</code></pre>
### Includes
#### include <>
This with the angle brackets is used to include files provided by implementation (on linux it searches known file paths from root or /). This is for including standard library headers, and has a pre-defined search path (depending on implementation).
#### include ""
This include is used for including headers from your current path. The path that is used as a base search is the directory of the file with this include.

#### Both
In both of these you can include a path to a certain file. By default \#include<> has pre defined search paths, and \#include"" only searches the current directory of the file that it is declared in. If you have a directory structure you can specify that in the path. See examples below.

#### Examples
* <code>\#include\<vector\> //Standard library</code>
* <code>\#include "bin/myHeader.h" //Starting from the current file path, search in the bin directory for myHeader.h </code>

## Pointers and References
Pointers are your friends! <br />

### Pointers
Pointers are variables that store a memory address. Pointers need to be dereferenced with the * operator to access the data at its given memory address. Pointers just hold a memory address, so they can point to anything (ex. variables, objects, files). You can also use pointers to do "pointer math" to traverse through arrays. The way to read pointers is from right to left. So the expression "const int\*" is read as "pointer to an int constant".

### Practice
* int\* const
  <details><summary> SHOW ANSWER </summary> 
    constant pointer to an integer
    </details>
* const char\* const
  <details><summary> SHOW ANSWER </summary>
    constant pointer to a character constant
    </details>
* char const\* const
    <details><summary> SHOW ANWER </summary>
    constant pointer to a constant character
    </details>

### Dynamically Allocated Memory
Sometimes you will need to allocate memory dynamically. This means that the memory is allocated on the heap, at runtime. This is expecially useful for dynamically allocated arrays, which would allow the user to allocate memory at runtime. Normally, C++ must know the size of an array at compile time, this is why dynamic memory is useful.
#### The new Keyword
The new keyword is used to allocated dynamic memory in C++. It can be used to allocate any datatype. It does not initialize the memory, it "reserves" the memory.
#### The delete Keyword
The delete keyword is used to de-allocate memory that was allocated with new. This is used to prevent memory leaks. Memory leaks can cause serious issues in larger programs, especially ones that are expected to run for long periods of time (what you would be working on in a professional setting).


### Examples
* <pre><code>//basic pointer example
  int a = 5; //Declare and initialize an int
  int\* pa = &a;//Assign the pointer pa to the address of a
  std::cout << "The address of a is: " << pa << "\nThe value at that address is: " << \*pa << std::endl; //print the address and value of a </code></pre>


* <pre><code>//pointer math example
  int a[5] = {1, 2, 3, 4, 5};
  int\* pa = a; //Arrays are pointers! So you dont need to use the & operator
  std::cout << "a[2] is: " << \*(pa + 2) << std::endl; //This will print out a[2]</code></pre>

* <pre><code>myObject\* a; //Assume there is some object called myObject
  myObject->function(); //The -> operator is used in place of . when you have a pointer to an object</code></pre>
* <pre><code>//Dynamic memory example
  int size;
  std::cin >> size; //get size of the shopping list from user
  std::string* shopping_list;
  shopping_list = new std::string[size]; //allocate an array to the size specified at runtime</code></pre>
### References
References are an 'alias' to a variable. You do not need to dereference references to access their data.

### Example
* <pre><code>int i = 5;
  int& ri = i; //ri is a reference or alias to i
  std::cout << "Printing out i through the reference ri: " << ri << std::endl;
  </code></pre>
### When to use what
* Pointers
    * To implement data structures (This class!)
    * If you need pointer arithmetic
* References
    * For function parameters
    * Return values
    * The reason you would want this is so that you do not have to copy objects (or anything really) to pass it into a function.

## STL (Standard Template Library)
The c++ STL is extremely useful and will be used throughout this course. STL provides templates for all (or most) of the data structures shown in this class. 

### Useful headers from the STL (not complete list)
1. #include \<vector\> //allows you to use vectors
2. #include \<iostream\> //allows basic io to stdout and stdin
3. #include \<utility\> //allows the use of pairs and smart pointers
4. #include \<unordered\_map\> //allows the use of hashmaps
5. #include \<stack\> //allows the use of stacks
6. #include \<queue\> //allows the use of queues
7. #include \<list\> //allows the use of (linked)lists

## Templates, Classes/Structs
These are what distinguish C++ from C. There are many differences between C and C++, but they mostly consist of the addition of object oriented programming (OOP) features.

### Templates
Templates allow functions and classes in C++ to operate with generic types. This allows us to reduce the amount of code we have to write by preventing duplicate code. This allows us to write generic code, so that instead of rewriting/overloading functions for different parameter types, we can write one template to accomplish the same thing.

### Classes/Structs
The only difference between classes and structs in C++ are the default accessibility of their members. Classes by default have all members as private (unless specified otherwise) and structs have all members public by default. 

### Examples
* All data structure implementations in the C++ STL (Standard Template Library) are templated, so they can be used with any datatype.

* <pre><code>template &lt;typename T&gt;
	 T max(T a, T b){
	 	return a > b ? a : b;
	 }</code></pre>
* <pre><code>//This example shows a very basic node struct that would be used in a linked list
//The node can be any data type, allowing the linked list to store any data type
template &lt;typename T&gt;
struct node{ //Part of a linked list. NOT comprehensive, just a simple example
public:
	node();
	~node();

	T get_value(T value);
private:
	T _value;
	node* next;
};</code></pre>
		
