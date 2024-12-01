/*
=== OPERATIONS PLAN ===

||| DEV

* bucket optimal constants, whatever
* md5 / hashcalc method
* bucket dispatch logic
* alloc corner cases and problems: the test code in the task should not meet the RAM limits, I guess :)

 + explore some RTTI in the context of templates : hmm, not relevant to the problems

 * tried to use conversion to double for both int and double (optional) - the if (data) cast to bool does not work, I'm drowning and drowning

 - implement the std::optional<V> so the thing compiles (without functionality for now)
  + reduce to the most simple thing possible using the class to help gcc deduce the types
  + optional works with int
  - make it work with strings : no results


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
    double td;

    optional(V _val)
    {
        val = _val;
        isEmty = false;
    }

    optional()
    {
        isEmty = true;
    }

    operator bool() const {
        return !isEmty;
    }

    operator int*() const {
        return ((int*)(&val));
    }

    operator double*() {
        td = (double)val;
        //double d = (double)val;
        return ((double*)(&val));
        //return ((double*)(&d));
    }

    V* operator->() const
    {
        if (isEmty) {
            return nullptr;
        } else {
            return val;
        }
    }

};

// simple adhoc int/double
// template<typename K, typename V>
// class OpTestClass
// {
// public:
//     OpTestClass() { }
//
//     // Lookup the given key in the map, if the key is not found return nullptr
//     optional<V> lookup(K key)
//     {
// //        return 123;
// //
// //        optional<V> opt;
// //        opt.isEmty = true;
// //
// //        return opt;
//
//
//         return 123.456;
//
//         optional<V> opt;
//         opt.isEmty = true;
//
//         return opt;
//     }
//
//     V storedValue;
// };

template<typename K, typename V>
class OpTestClass
{
public:
    OpTestClass() { }

    // Lookup the given key in the map, if the key is not found return nullptr
    optional<V> lookup(K key)
    {
        return storedValue;

        //optional<V> opt;
        //opt.isEmty = true;
        //
        //return opt;
    }

    V storedValue;
};

// ====================== ====================== ======================

// my RTTI using sizeof?

//template<typename T>
//class rttic
//{
//public:
//    rttic() { }
//
//    void foo(T val)
//    {
//
//
//        int sz = sizeof(T);
//        cout << sz;
//    }
//
//    // V storedValue;
//};

int main() {

// ====================== ====================== ======================
    //rttic<>
    //dynamic_cast<>
// ====================== ====================== ======================

// === string/double k:v ===

    OpTestClass<string, double> stringMap;

    stringMap.storedValue = 123.456;

    auto piValue = stringMap.lookup("pi");

//    cout << *piValue;

    if (piValue) {
        cout << "pi: " << *piValue << endl;
    } else {
        cout << "Key 'pi' not found." << endl;
    }

// === int/int k:v ===

    OpTestClass<int, int> otc;

    otc.storedValue = 123;

    auto data = otc.lookup(1);

    if (data) {
        cout << "data: " << *data << endl;
    } else {
        cout << "Key not found." << endl;
    }

// ====================== ====================== ======================

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
