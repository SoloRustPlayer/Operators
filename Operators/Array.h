#include <iostream>

template <typename T>
class Array {
private:
    T* data;
    size_t size;
    size_t capacity;

    void Resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Array(size_t initialCapacity = 10)
        : size(0), capacity(initialCapacity) {
        data = new T[capacity];
    }

    Array(const Array& other)
        : size(other.size), capacity(other.capacity) {
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~Array() {
        delete[] data;
    }

    void Add(const T& element) {
        if (size >= capacity) {
            Resize(capacity * 2);
        }
        data[size++] = element;
    }

    size_t GetSize() const {
        return size;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    Array operator+(const Array& other) const {
        Array result(size + other.size);
        for (size_t i = 0; i < size; ++i) {
            result.Add(data[i]);
        }
        for (size_t i = 0; i < other.size; ++i) {
            result.Add(other.data[i]);
        }
        return result;
    }

    Array& operator+=(const Array& other) {
        for (size_t i = 0; i < other.size; ++i) {
            Add(other.data[i]);
        }
        return *this;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            std::cerr << "Index out of range" << std::endl;
            exit(1);
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            std::cerr << "Index out of range" << std::endl;
            exit(1);
        }
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const Array& arr) {
        for (size_t i = 0; i < arr.size; ++i) {
            os << arr.data[i] << " ";
        }
        return os;
    }

    bool operator==(const Array& other) const {
        if (size != other.size) {
            return false;
        }
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Array& other) const {
        return !(*this == other);
    }

    bool operator>(const Array& other) const {
        return size > other.size;
    }

    bool operator<(const Array& other) const {
        return size < other.size;
    }
    Array operator*(const Array& other) const {
        Array result;
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < other.size; ++j) {
                if (data[i] == other.data[j]) {
                    result.Add(data[i]);
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Array<int> arr1;
    Array<int> arr2;

    arr1.Add(1);
    arr1.Add(2);
    arr1.Add(3);

    arr2.Add(2);
    arr2.Add(3);
    arr2.Add(4);

    Array<int> combined = arr1 + arr2;
    Array<int> intersection = arr1 * arr2;

    std::cout << "Array 1: " << arr1 << std::endl;
    std::cout << "Array 2: " << arr2 << std::endl;
    std::cout << "Combined: " << combined << std::endl;
    std::cout << "Intersection: " << intersection << std::endl;

    return 0;
}
