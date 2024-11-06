#include <iostream>

class DynamicArray {
private:
    int* data;          // pointer to  array
    int capacity;       // current capacity of the array
    int size;           // curent number of elements

    //function to resize the array when it's full
    void resize() {
        capacity *= 2;  //fouble the capacity
        int* newData = new int[capacity];  //Allocate a new larger array
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];  //Copy elements to the new array
        }
        delete[] data;  // Free old array memory
        data = newData; // Point to the new array
    }

public:
    // Constructor
    DynamicArray() {
        capacity = 2;          // Initial capacity
        size = 0;               // Start with no elements
        data = new int[capacity]; // Allocate initial memory
    }

    // Destructor
    ~DynamicArray() {
        delete[] data;  // Free allocated memory
    }

    // Add an element to the end of the array
    void push_back(int value) {
        if (size == capacity) {
            resize();  // Resize if array is full
        }
        data[size++] = value;  // Add element and increment size
    }

    // Remove the last element from the array
    void pop_back() {
        if (size > 0) {
            size--;  // Decrease size
        }
    }

    // Access an element by index
    int operator[](int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        throw std::out_of_range("Index out of bounds");
    }

    // Get the current number of elements
    int getSize() const {
        return size;
    }

    // Get the current capacity of the array
    int getCapacity() const {
        return capacity;
    }
};

int main() {
    DynamicArray arr;

    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);

    std::cout << "Array elements: ";
    for (int i = 0; i < arr.getSize(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Size: " << arr.getSize() << std::endl;
    std::cout << "Capacity: " << arr.getCapacity() << std::endl;

    arr.pop_back();
    std::cout << "After pop_back, size: " << arr.getSize() << std::endl;

    return 0;
}
