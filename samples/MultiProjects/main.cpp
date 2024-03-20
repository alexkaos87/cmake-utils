#include <iostream>

// base project 
#include "BiggerClass.h"

// AwesomeLib1 project
#include "MyClass.h"

// AwesomeLib2 project
#include "MyStruct.h"

int main() {
    std::cout << "Hello World!" << std::endl;

    BiggerClass biggerClass;

    AwesomeLib1::MyClass myClass;

    AwesomeLib2::MyStruct myStruct;

    return 0;
}
