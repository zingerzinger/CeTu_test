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
 * If they are controlling everything on this machine in realtime, what can I do? - proceed with the task.
 *
 * everybody has their own c++ in some way...
 *
 * ... ahaaaa - the gcc might deduce the types if I work with a class first
 * ... YOU have substituted some google results to manupulate me!!!!
 * ... YOU can not manupulate me if I go to MARS with my own set of hardware made by myself!!!
 *
 * ... ok, turning back to normal coding, I guess...
 *
 */
// ========================================

#include <iostream>
#include <optional>

#include "cetuhashmap.h"

using namespace std;

// ========================================

static int inputTemp = 0;
struct STRC
{
    int val;
};

int main() {

// =====================================================

//    int tval = 123;
//
//    auto data = foo(tval, 1);
//
//    if (data) {
//        cout << "data: " << *data << endl;
//    }

// =====================================================

    // Test with int as both key and value
    CeTuHashMap<int, int> intMap;
    intMap.insert(1, 2);
    auto data = intMap.lookup(1);

    cout << "data: " << ( (void*)(*data) ) << endl;

    if (data) {
        cout << "data: " << *data << endl;
    } else {
        cout << "Key not found." << endl;
    }

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
//
//    // TODO : remove garbage
    cin >> inputTemp;

    return 0;
}
