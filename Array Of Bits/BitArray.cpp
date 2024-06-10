#include "BitArray.h"
#include <iostream>
using namespace std;

//default constructor
BitArray::BitArray() : size(32), data(new unsigned char[4]) { //dynamic memory allocation for 32 bits(4 bytes)
    //to initialize all bytes to 0
    for (int i = 0; i < 4; ++i) {
        data[i] = 0;
    }
}
BitArray::BitArray(int size) : size(size), data(new unsigned char[(size + 7) / 8]) {
    //add 7 and then divide size by 8 to ensure that we allocate enough memory 
    // to hold the specified number of bits while 
    //also accounting for any extra bits that may not completely fill a byte.
    for (int i = 0; i < size; ++i)
        setValue(i, 0);
}

//copy constructor
BitArray::BitArray(const BitArray& other) : size(other.size), 
                    data(new unsigned char[(other.size + 7) / 8]) {
    for (int i = 0; i < size; ++i)
        setValue(i, other.getValue(i));
}


//move constructor
BitArray::BitArray(BitArray&& other) noexcept : size(other.size), data(other.data) {
    other.size = 0;
    other.data = nullptr;
}


bool BitArray::getValue(int index) const {
    if (index < 0 || index >= size) {
        //cout << "Error: Index out of range." << endl;
        return false; 
    }
    return (data[index / 8] >> (index % 8)) & 1;
}

void BitArray::setValue(int index, bool value) {
    if (index < 0 || index >= size) {
        cout << "Error: Index out of range." << endl;
        return; 
    }
    if (value)
        data[index / 8] |= (1 << (index % 8)); //byte index |= 1<< bit position 
    else
        data[index / 8] &= ~(1 << (index % 8));
}

//prints only indices of bits with value 1
void BitArray::printArray() const {
    for (int i = 0; i < size; ++i) {
        if (getValue(i))
            cout << i << " ";
    }
    cout << endl;
}


BitArray BitArray::merge(const BitArray& other) const { //union
    int newSize = size > other.size ? size : other.size; //gets size of the greater object
    BitArray result(newSize);
    for (int i = 0; i < newSize; ++i) {
        result.setValue (i, getValue(i) || other.getValue(i));
    }
    return result;
}

BitArray BitArray::differ(const BitArray& other) const { //difference
    BitArray result(size);
    for (int i = 0; i < size; ++i) {
        result.setValue(i, getValue(i) && !other.getValue(i)); //current bit AND not other
    }
    return result;
}


bool BitArray::operator[](int index) const {
    if (index < 0 || index >= size) {
        cout << "Error: Index out of range." << endl;
        return false; 
    }
    return (data[index / 8] >> (index % 8)) & 1;
}

BitArray::~BitArray() {
    delete[] data;
}
