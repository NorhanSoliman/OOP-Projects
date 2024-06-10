#include <iostream>
#include "SortedArray.h"


int main() {
 
   SortedArray arr; //default constructor

   //testing insert function
    arr.insert(5);
    arr.insert(3);
    arr.insert(8);
    arr.insert(1);

    std::cout << "Array: " << arr << std::endl; //stream output operator

    //testing that the array stays sorted after modification using the index operator
    arr[1] = 10; 
    std::cout << "Array after modification: " << arr << std::endl;

    //getsize function
    std::cout << "Size of the array: " << arr.getSize() << std::endl;

    //index operator
    std::cout << "Element at index 2: " << arr[2] << std::endl;

    //copy constructor
    SortedArray arr_copy = arr;
    std::cout << "Copy of array: " << arr_copy << std::endl;

    //move constructor
    SortedArray arr_move = std::move(arr);
    std::cout << "Array after move: " << arr_move << std::endl;

    
    std::cout << (arr == arr_copy ? "Yes" : "No") << std::endl;

    return 0;
}
