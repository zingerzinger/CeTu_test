#ifndef CETUHASHMAP_H
#define CETUHASHMAP_H

#include <optional>

template<typename K, typename V>
class CeTuHashMap
{
public:
    CeTuHashMap()
    {

    }

    // Insert a new pair into the hashmap
    void insert(K key, V value)
    {

    }

    // Lookup the given key in the map, if the key is not found return nullptr
    std::optional<V> lookup(K key)
    {
        return std::nullopt; // implement CeTu::nullopt ?

        //if ( 0 /* ~ key exists */ ) {
        //    return {};
        //} else {
        //    //return nullptr /*std::nullopt_t*/;
        //    return nullptr;
        //}
    }

    // Delete a pair with the key in the hashmap
    void erase(K key)
    {

    }

private:

    // TODO

};

#endif // CETUHASHMAP_H
