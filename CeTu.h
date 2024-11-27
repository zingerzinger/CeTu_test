#ifndef CETU_H
#define CETU_H

#include <stdio.h> // might be substituted with ___asm calls for linux kernel calls, nobody asked for this thx God!

#include <string.h> // TODO: exclude it

//#include "stdlib.h"

#include "cetuhashmap.h"

#define std CeTu
#define endl "\r\n"

#define std CeTu

namespace CeTu
{

    // === the string ===

    // ok, make a simple string
    class string
    {
    private:

        static const int MAX_CHARS = 16;

    public:
        char chars[MAX_CHARS];

        string (const char* buf)
        {
            char* s = ((char*)buf);
            char* d = &(chars[0]);

            do {
                *d = *s;
                d++;
                s++;
            } while (*s != '\0');
            *d = '\0';
        }

        operator char*()
        {

          //while ()

          //char* test = new char[required_bytes];
          // Fill 'test'
          //return test;
        }

//        operator int() const // string --> int
//        {
//          return data;
//        }


        // I guess we need a sophisticated copy constructor!

    };

    // === standard output ===

    class coutt
    {
    public:

        coutt& operator << (int val/*cout& is, T& obj */)
        {
            printf("%d", val);
            return (*this);
        }

        coutt& operator << (const char* val)
        {
            printf("%s", val);
            return (*this);
        }

        coutt& operator << (string val)
        {
            printf("%s", &(val.chars[0]));
            return (*this);
        }
    };

    // === vector container ===

    // * memory alignment issues?

    template<typename T>
    class vector
    {
    public:
        vector() { }

        ~vector() {
            if (buffer) { free(buffer); }
        }

        // alloc new buffer (size+1), copy old contents and the val, free old buffer
        void push_back(T val) {

            void* newBuffer = malloc( (sizeof(T)*(m_size+1)) );

            if (m_size) {
                memcpy(newBuffer, buffer, (sizeof(T)*(m_size)));
                free(buffer);
            }

            buffer = newBuffer;

            // put it HERE
            memcpy(newBuffer + (sizeof(T)*(m_size)),
                   (T*)(&val),
                   (sizeof(T)));

            m_size++;
        }

        // we're doing it in the simpliest way possible for now
        void pop_back() {

            void* newBuffer = malloc( (sizeof(T)*(m_size-1)) );

            //if (m_size) {
                memcpy(newBuffer, buffer, (sizeof(T)*(m_size-1)));
                free(buffer);
            //}

            buffer = newBuffer;

            m_size--;
        }

        T operator[] (int idx)
        {
            T* obj = (T*)((buffer) + idx * (sizeof(T)));
            return (*obj);
        }

        int size() { return m_size; }

    private:

        int m_size = 0;
        //int m_allocatedItems = 0;

        void* buffer = 0;

        // storage

    };
}

using namespace std;

static coutt cout;

#endif // CETU_H

//======================================
// vector test:
//    int* a = new int(123);
//    vector<int*> v;
//    v.push_back(a);
//    cout << ( (*v[0]) ) << endl;
//
//    vector<int> v;
//
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(3);
//
//    cout << ( v[0] ) << endl;
//    cout << ( v[1] ) << endl;
//    cout << ( v[2] ) << endl;
//
//    cout << ( v.size() ) << endl;
//    v.pop_back(); cout << ( v.size() ) << endl;
//    v.pop_back(); cout << ( v.size() ) << endl;
//    v.pop_back(); cout << ( v.size() ) << endl;
//
//    cout << ( v[0] ) << endl;
//    cout << ( v[1] ) << endl;
//    cout << ( v[2] ) << endl;
//    cout << "TEST" << endl;
//======================================

// =====================================================

//    vector<string> vs;
//
//    vs.push_back("hello");
//    vs.push_back("world");
//
//    for (int i = 0; i < vs.size(); i++) {
//        cout << vs[i] << endl;
//    }
