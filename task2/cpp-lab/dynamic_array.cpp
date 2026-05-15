#include <iostream>
#include <algorithm>

class DynamicArray {
    int* data;
    int size, capacity;
    
public:
    DynamicArray(int cap = 10) : data(new int[cap]), size(0), capacity(cap) {}
    
    // Copy constructor (deep copy)
    DynamicArray(const DynamicArray& other)
        : data(new int[other.capacity]), size(other.size), capacity(other.capacity) {
        std::copy(other.data, other.data + size, data);
    }
    
    // Copy assignment
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new int[capacity];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }
    
    // Destructor
    ~DynamicArray() { delete[] data; }
    
    void push_back(int val) {
        if (size >= capacity) {
            capacity *= 2;
            int* new_data = new int[capacity];
            std::copy(data, data + size, new_data);
            delete[] data;
            data = new_data;
        }
        data[size++] = val;
    }
    
    int& operator[](int i) { return data[i]; }
    int get_size() const { return size; }
    
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& arr) {
        os << "[";
        for (int i = 0; i < arr.size; i++) {
            os << arr.data[i];
            if (i < arr.size - 1) os << ", ";
        }
        return os << "]";
    }
};

int main() {
    DynamicArray a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);
    std::cout << "a = " << a << std::endl;
    
    DynamicArray b = a; // Copy constructor
    b.push_back(40);
    std::cout << "b = " << b << std::endl;
    std::cout << "a = " << a << std::endl; // Unchanged (deep copy)
    
    return 0;
}
