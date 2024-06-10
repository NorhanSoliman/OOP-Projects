#include "BitArray.h"
#include <iostream>
using namespace std;

int main() {
  
    BitArray arr1(50); 
    BitArray arr2;     //default array (32 bits)


    arr1.setValue(25,1);
    cout << "Value at index 25: " << arr1.getValue(25) << endl;
    arr1.setValue(20, 1);
    arr1.setValue(15, 1);
    arr2.setValue(10, 1);
    arr2.setValue(5, 1);
 
    

    cout << "Array 1:";
    arr1.printArray();
    cout << "Array 2:";
    arr2.printArray();

    arr1.setValue(51, 1); //error out of range expected

 
    BitArray arr3 = arr1.merge(arr2);
    BitArray arr4 = arr1.differ(arr2);

    cout << "Merged array: ";
    arr3.printArray();

    cout << "Differed array: ";
    arr4.printArray();

    //operator test

    cout << arr1.getValue(25) << endl; 
    cout << arr1[25] << endl;

    return 0;
}
