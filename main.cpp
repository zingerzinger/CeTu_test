/*
=== OPERATIONS PLAN ===

||| DEV

* bucket optimal constants, whatever
* md5 / hashcalc method
* bucket dispatch logic
* alloc corner cases and problems: the test code in the task should not meet the RAM limits, I guess :)

 - implement the std::optional<V> so the thing compiles (without functionality for now)
  ~ reduce to the most simple thing possible using the class to help gcc deduce the types

 - use the CeTu/std instead of std in the HashMap
 - build and run, so that there is no normal std stuff

 - proceed with the hashing logic

||| MISC

 - readme.md : build&run instructions
 - merge dev --> main

=== === === === === === */

// TODO: move the include to the right with tabs so nobody sees it, so that everything works according to specifications
#include "CeTu.h";

// === optional test ===

// class nullopt { /* overload dereferencing? (ret nullptr) */ };

template<typename V>
class optional
{

public:

    bool isEmty = true;
    V val;

    optional(V _val)
    {
        val = _val;
        isEmty = false;
    }

    optional()
    {
        isEmty = true;
    }

//    operator int() const {
//
//        if (isEmty) {
//            return nullptr;
//        } else {
//            return ((int)val);
//        }
//    }

    operator bool() const {
        return !isEmty;
    }

    operator int() const {
        return (int)val;
    }

    // overload some casts
    V* operator->() const
    {
        if (isEmty) {
            return nullptr;
        } else {
            //return *val;
            return val;
        }
    }

};

template<typename V>
class OpTestClass
{
public:
    OpTestClass() { }

    // Lookup the given key in the map, if the key is not found return nullptr
    optional<V> lookup(int key)
    {

        // TODO: return the found value
        //return 123;

        // ------------------

        // return null:

        optional<V> opt;
        opt.isEmty = true;

        return opt;
    }
};

int main() {

// =====================================================

    OpTestClass<int> otc;

    auto data = otc.lookup(1);

    //cout << "data: " << ((int)(data)) << endl;

    if (data) {
        //cout << "data: " << *data << endl;
    } else {
        cout << "Key not found." << endl;
    }

// ======================

     //optional<int> opt = tlookup(123);

//    optional<int> data = tlookup(123);
//    cout << "data: " << data << endl;

//    auto data = tlookup(123);
//
//    if (data) {
//        cout << "data: " << *data << endl;
//    } else {
//        cout << "Key not found." << endl;
//    }

// =====================================================
// =====================================================
// =====================================================

    // Test with int as both key and value
//    CeTuHashMap<int, int> intMap;
//    intMap.insert(1, 2);
//    auto data = intMap.lookup(1);
//
//    if (data) {
//        cout << "data: " << *data << endl;
//    } else {
//        cout << "Key not found." << endl;
//    }
//
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
//
//    intMap.print();
//
//    // Erase a key and then attempt to look it up
//    intMap.erase(1);
//
//    intMap.print();
//
//    auto erasedData = intMap.lookup(1);
//    if (erasedData) {
//        cout << "Erased data: " << *erasedData << endl;
//    } else {
//        cout << "Key 1 not found after erase." << endl;
//    }
//
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
