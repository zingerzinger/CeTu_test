/*
=== OPERATIONS PLAN ===

||| DEV

* memory management : all the stuff in main is on stack
* bucket optimal constants, whatever
* md5 / hashcalc method
* bucket dispatch logic
* alloc corner cases and problems: the test code in the task should not meet the RAM limits, I guess :)

* use my vector for my string?

 ~ implement the std::vector<T>   so the thing compiles (with functionality for now)

 sleep needed

 - implement the std::string      so the thing compiles (without functionality for now)
 - implement the std::optional<V> so the thing compiles (without functionality for now)

||| MISC

 - readme.md : build&run instructions
 - merge dev --> main

=== === === === === === */

// TODO: move the include to the right with tabs so nobody sees it
#include "CeTu.h";
int main() {

// =====================================================

    // Test with int as both key and value
    CeTuHashMap<int, int> intMap;
    intMap.insert(1, 2);
    auto data = intMap.lookup(1);

    if (data) {
        cout << "data: " << *data << endl;
    } else {
        cout << "Key not found." << endl;
    }

// =====================================================
    // Attempt to lookup a key that doesn't exist
    auto missingData = intMap.lookup(3);
    if (missingData) {
        cout << "Missing data: " << *missingData << endl;
    } else {
        cout << "Key 3 not found." << endl;
    }

// =====================================================

    intMap.print();

    // Erase a key and then attempt to look it up
    intMap.erase(1);

    intMap.print();

    auto erasedData = intMap.lookup(1);
    if (erasedData) {
        cout << "Erased data: " << *erasedData << endl;
    } else {
        cout << "Key 1 not found after erase." << endl;
    }

// =====================================================
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
//    stringMap.print();

// =====================================================
//    // Insert additional values and demonstrate lookup
//    stringMap.insert("e", 2.71828);
//    auto eValue = stringMap.lookup("e");
//    if (eValue) {
//        cout << "e: " << *eValue << endl;
//    } else {
//        cout << "Key 'e' not found." << endl;
//    }
//
//    stringMap.print();
//// =====================================================
//    // Erase a key and then attempt to look it up
//    stringMap.erase("pi");
//    auto erasedPiValue = stringMap.lookup("pi");
//    if (erasedPiValue) {
//        cout << "Erased pi value: " << *erasedPiValue << endl;
//    } else {
//        cout << "Key 'pi' not found after erase." << endl;
//    }
//
//    stringMap.print();

    return 0;
}
