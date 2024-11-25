#ifndef CETU_H
#define CETU_H

// ===============

/* TODO:
 * cout
 * string
 */

#include <stdio.h>

#define std CeTu // hacking this
#define endl "\r\n" // hacking that

#define std CeTu

namespace CeTu
{
    //template<typename T>
    class cout
    {
    public:
//        cout()
//        {
//            // keep state, if we're have been created alredy
//        }

        // we need to return ourself for chain processing
        cout& operator << (int val/*cout& is, T& obj */)
        {
            printf("%d", val);
            return (*instance);
        }

        // we need to return ourself for chain processing
        //static cout& operator << (int val/*cout& is, T& obj */);

        // we need to return ourself for chain processing
        cout& operator << (const char* val)
        {
            printf("%s", val);
            return (*instance);
        }

    private:

        cout* instance = NULL;

    };

    //static cout cout::operator <<() { ; }

//    static cout::operator << (int val/*cout& is, T& obj */);

//    X operator--(int)
//    {
//        X old = *this; // copy old value
//        operator--();  // prefix decrement
//        return old;    // return old value
//    }

}

// we need to return ourself for chain processing
///*static*/ /*cout&*/void operator << (int val/*cout& is, T& obj */)
// {
//     printf("%d", val);
// }
//
// static /*cout&*/void operator << (int val/*cout& is, T& obj */)
// {
//     printf("%d", val);
// }
// =========================================

#endif // CETU_H
