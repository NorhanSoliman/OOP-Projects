#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include <iostream>

class SortedArray {
private:
    unsigned int* data;
    size_t size; 
    size_t capacity;

    void sort(); 

public:
    
    class Proxy;
    SortedArray();

    explicit SortedArray(size_t initialCapacity );

    SortedArray(const SortedArray& other);

    SortedArray(SortedArray&& other) noexcept;

    SortedArray& operator=(const SortedArray& other);

    SortedArray& operator=(SortedArray&& other) noexcept;


    const unsigned int& operator[](size_t index) const;

    SortedArray::Proxy operator[](size_t index);

    void setAt(size_t index, unsigned int value);

    unsigned int getAt(size_t index) const;

    bool operator==(const SortedArray& other) const;

    friend std::ostream& operator<<(std::ostream& os, const SortedArray& arr);

    void insert(unsigned int value);

    size_t getSize() const;


    ~SortedArray();

    
};


//a proxy class that will be used in operator[] overload function
//to keep the array sorted in case of modification
class SortedArray::Proxy {
private:
    unsigned int* element;
    SortedArray* arr;
    size_t index;

public:
    Proxy(unsigned int* elem, SortedArray* array, size_t idx) 
        : element(elem), arr(array), index(idx) {}

    Proxy& operator=(unsigned int value) {
        if (index >= arr->size) {
            throw std::out_of_range("Index out of range");
        }
        *element = value;
        arr->sort(); //sorted the array after modifying an element
        return *this;
    }

    operator unsigned int() const {
        if (index >= arr->size) {
            throw std::out_of_range("Index out of range");
        }
        return *element;
    }
};

#endif 

