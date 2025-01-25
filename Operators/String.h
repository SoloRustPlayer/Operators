#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t length;

    void CopyFrom(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }

public:
    String() : data(nullptr), length(0) {
        data = new char[1];
        data[0] = '\0';
    }

    String(const char* str) {
        CopyFrom(str);
    }

    String(const String& other) {
        CopyFrom(other.data);
    }

    ~String() {
        delete[] data;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            CopyFrom(other.data);
        }
        return *this;
    }

    String operator+(const String& other) const {
        size_t newLength = length + other.length;
        char* newData = new char[newLength + 1];
        strcpy(newData, data);
        strcat(newData, other.data);
        String result(newData);
        delete[] newData;
        return result;
    }

    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }

    char& operator[](size_t index) {
        if (index >= length) {
            std::cerr << "Index out of range" << std::endl;
            exit(1);
        }
        return data[index];
    }

    const char& operator[](size_t index) const {
        if (index >= length) {
            std::cerr << "Index out of range" << std::endl;
            exit(1);
        }
        return data[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }

    bool operator==(const String& other) const {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    bool operator>(const String& other) const {
        return length > other.length;
    }

    bool operator<(const String& other) const {
        return length < other.length;
    }
};

int main() {
    String str1("Hello");
    String str2("World");

    String str3 = str1 + ", " + str2 + "!";
    str1 += " Everyone";

    std::cout << "String 1: " << str1 << std::endl;
    std::cout << "String 2: " << str2 << std::endl;
    std::cout << "String 3: " << str3 << std::endl;

    std::cout << "Character at index 1 in String 1: " << str1[1] << std::endl;
    std::cout << "String 1 == String 2: " << (str1 == str2) << std::endl;
    std::cout << "String 1 != String 2: " << (str1 != str2) << std::endl;
    std::cout << "String 1 > String 2: " << (str1 > str2) << std::endl;
    std::cout << "String 1 < String 2: " << (str1 < str2) << std::endl;

    return 0;
}
