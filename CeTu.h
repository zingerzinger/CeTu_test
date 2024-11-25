#ifndef CETU_H
#define CETU_H

#include <stdio.h> // might be substituted with ___asm calls for linux kernel calls, nobody asked for this thx God!
#include <string.h>

#include "cetuhashmap.h"

#define std CeTu
#define endl "\r\n"

#define std CeTu

namespace CeTu
{

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
    };

    class string
    {
        // ?
    };

    // === vector container ===

    template<typename T>
    class vector
    {
    public:
        vector() { }

        ~vector() {
            // free the BIG BUFFFFFER
        }

        // we're doing it in the simpliest way possible for now
        void push_back(T val) {

            void* newBuffer = malloc( (sizeof(T)*(m_size+1)) );

            if (m_size) {
                memcpy(newBuffer, buffer, (sizeof(T)*(m_size)));
            }

            free(buffer);
            buffer = newBuffer;

            // put it HERE
            memcpy(newBuffer + (sizeof(T)*(m_size)),
                   (T*)(&val),
                   (sizeof(T)));

            m_size++;
        }

        // we're doing it in the simpliest way possible for now
        void pop_back() {
            // alloc sizeof(T)*(m_size-1)
            // copy old to new
            // free old
            // ...
        }

        void /*T*/ operator[] (int idx)
        {
            //printf("%s", val);
            //return (*this);
        }

        int size() { return m_size; }

    private:

        int m_size = 0;
        //int m_allocatedItems = 0;

        void* buffer;

        // storage

    };
}

using namespace std;

static coutt cout;

#endif // CETU_H
