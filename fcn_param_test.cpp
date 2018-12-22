#include <iostream>

void myFunc(int& i){
    i *= i;
    std::cout << "i inside myFunc: " << i << std::endl;
}

void myFunc2(int i){
    i *= i;
    std::cout << "i inside myFunc2: " << i << std::endl;
}

void myFunc3(int* i){
    *i *= *i;
    std::cout << "i inside myFunc3: " << *i << std::endl;
}
int main(){

    int i = 2;

    std::cout << "i in main before anything: " << i << std::endl;
    myFunc(i);
    std::cout << "i in main after myFunc: " << i << std::endl;
    myFunc2(i);
    std::cout << "i in main after myFunc2: " << i << std::endl;
    myFunc3(&i);
    std::cout << "i in main after myFunc3: " << i << std::endl;
}
