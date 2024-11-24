#include <iostream>

#include "cetuhashmap.h"

using namespace std;

// int main()
// {
//     std::cout << "Shalom CeTu!";
//     std::cout << "Shabbat shalom!";
//     int t = 0;
//     std::cin >> t;
//     return 0;
// }

// ========================================

struct STRC
{
    int val;
};

template<typename K, typename V>
std::optional<V> foo(K key)
{
    return std::nullopt; // implement CeTu::nullopt ?
    //return 123;
}

//template<typename T>
//std::optional<T> foo(T val)
//{
////    T* tval = (T*)val;
//
//    return std::nullopt; // implement CeTu::nullopt ?
//    return 123;
//
//}

// ========================================

/* Hmm
 * The task:
 * do not use std library
 * comments : use std::string
 * test code : cout , no std namespace usage
 *
 * Possibilities:
 *
 * - substitute the gcc with my version that just simulates a particular binary output for the CPU
 * - study some more CPP meta
 * - I might substitute anything if I have time and will, whooh.
 *
 */

static int inputTemp = 0;

int main() {

// =====================================================

    int tval = 123;

    auto data = foo(tval);

    if (data) {
        cout << "data: " << *data << endl;
    }

// =====================================================

//    // Test with int as both key and value
//    CeTuHashMap<int, int> intMap;
//    intMap.insert(1, 2);
//    auto data = intMap.lookup(1);
//    if (data) {
//        cout << "data: " << *data << endl;
//    } else {
//        cout << "Key not found." << endl;
//    }

//// =====================================================
//    // Attempt to lookup a key that doesn't exist
//    auto missingData = intMap.lookup(3);
//    if (missingData) {
//        cout << "Missing data: " << *missingData << endl;
//    } else {
//        cout << "Key 3 not found." << endl;
//    }
//
//// =====================================================
//    // Erase a key and then attempt to look it up
//    intMap.erase(1);
//    auto erasedData = intMap.lookup(1);
//    if (erasedData) {
//        cout << "Erased data: " << *erasedData << endl;
//    } else {
//        cout << "Key 1 not found after erase." << endl;
//    }
//
//// =====================================================
//    // Test with std::string as key and double as value
//    CeTuHashMap<string, double> stringMap;
//    stringMap.insert("pi", 3.14159);
//    auto piValue = stringMap.lookup("pi");
//    if (piValue) {
//        cout << "pi: " << *piValue << endl;
//    } else {
//        cout << "Key 'pi' not found." << endl;
//    }
//
//// =====================================================
//    // Insert additional values and demonstrate lookup
//    stringMap.insert("e", 2.71828);
//    auto eValue = stringMap.lookup("e");
//    if (eValue) {
//        cout << "e: " << *eValue << endl;
//    } else {
//        cout << "Key 'e' not found." << endl;
//    }
//
//// =====================================================
//    // Erase a key and then attempt to look it up
//    stringMap.erase("pi");
//    auto erasedPiValue = stringMap.lookup("pi");
//    if (erasedPiValue) {
//        cout << "Erased pi value: " << *erasedPiValue << endl;
//    } else {
//        cout << "Key 'pi' not found after erase." << endl;
//    }

    // TODO : remove garbage
    cin >> inputTemp;

    return 0;
}
