#include "SortedArray.h"
#include <stdexcept>


//default
SortedArray::SortedArray() : 
    data(new unsigned int[10]), size(0), capacity(10) {}

//parametrized
SortedArray::SortedArray(size_t initialCapacity) : data(nullptr), size(0), capacity(initialCapacity) {
    if (initialCapacity <= 0) {
        throw std::invalid_argument("Initial capacity must be greater than zero.");
    }
    data = new unsigned int[initialCapacity];
}

//copy
SortedArray::SortedArray(const SortedArray& other) : data(new unsigned int[other.capacity]), 
         size(other.size), capacity(other.capacity) {
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

//move
SortedArray::SortedArray(SortedArray&& other) noexcept : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

//copy assignment operator
SortedArray& SortedArray::operator=(const SortedArray& other) {
    if (this != &other) {
        delete[] data;
        data = new unsigned int[other.capacity];
        size = other.size;
        capacity = other.capacity;

        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

//move assignment operator
SortedArray& SortedArray::operator=(SortedArray&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;

        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
}

void SortedArray::sort() {
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (data[i] > data[j]) {
                unsigned int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}


//const version is for reading elements
const unsigned int& SortedArray::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}


//unconst version for modifying elements. returning a proxy to keep the array sorted
SortedArray::Proxy SortedArray::operator[](size_t index) {
    
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return Proxy(&data[index], this, index);
}



void SortedArray::setAt(size_t index, unsigned int value) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
    sort();
}


unsigned int SortedArray::getAt(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}


bool SortedArray::operator==(const SortedArray& other) const {
    if (size != other.size) {
        return false;
    }
    //traverse to compare every element
    for (size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}



std::ostream& operator<<(std::ostream& os, const SortedArray& arr) {
    os << "[";
    for (size_t i = 0; i < arr.size; ++i) {
        os << arr.data[i];

        if (i < arr.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}



void SortedArray::insert(unsigned int value) {
    if (size == capacity) {
        //if size equals capacity, resize the array
        capacity *= 2;
        unsigned int* newData = new unsigned int[capacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = value; 

    //resorting the array
    sort();
}


size_t SortedArray::getSize() const {
    return size;
}

SortedArray::~SortedArray() {
    delete[] data;
}




