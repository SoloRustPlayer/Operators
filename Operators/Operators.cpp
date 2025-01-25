#include <iostream>
#include "Array.h" 
#include "String.h" 

int main() {
    // Работа с Array
    std::cout << "=== Работа с Array ===" << std::endl;
    Array<int> arr1;
    Array<int> arr2;

    arr1.Add(1);
    arr1.Add(2);
    arr1.Add(3);

    arr2.Add(3);
    arr2.Add(4);
    arr2.Add(5);

    std::cout << "Array 1: " << arr1 << std::endl;
    std::cout << "Array 2: " << arr2 << std::endl;

    Array<int> arrSum = arr1 + arr2;
    std::cout << "Array 1 + Array 2: " << arrSum << std::endl;

    arr1 += arr2;
    std::cout << "Array 1 += Array 2: " << arr1 << std::endl;

    Array<int> arrIntersection = arr1 * arr2;
    std::cout << "Intersection of Array 1 and Array 2: " << arrIntersection << std::endl;

    std::cout << "Array 1[1]: " << arr1[1] << std::endl;

    std::cout << "Array 1 == Array 2: " << (arr1 == arr2) << std::endl;
    std::cout << "Array 1 != Array 2: " << (arr1 != arr2) << std::endl;
    std::cout << "Array 1 > Array 2: " << (arr1 > arr2) << std::endl;
    std::cout << "Array 1 < Array 2: " << (arr1 < arr2) << std::endl;

    // Работа с String
//    std::cout << "\n=== Работа с String ===" << std::endl;
//    String str1("Hello");
//    String str2("World");
//
//    std::cout << "String 1: " << str1 << std::endl;
//    std::cout << "String 2: " << str2 << std::endl;
//
//    String strSum = str1 + ", " + str2 + "!";
//    std::cout << "String 1 + String 2: " << strSum << std::endl;
//
//    str1 += " Everyone";
//    std::cout << "String 1 += \" Everyone\": " << str1 << std::endl;
//
//    std::cout << "String 1[1]: " << str1[1] << std::endl;
//
//    std::cout << "String 1 == String 2: " << (str1 == str2) << std::endl;
//    std::cout << "String 1 != String 2: " << (str1 != str2) << std::endl;
//    std::cout << "String 1 > String 2: " << (str1 > str2) << std::endl;
//    std::cout << "String 1 < String 2: " << (str1 < str2) << std::endl;
//
//    return 0;
//}
