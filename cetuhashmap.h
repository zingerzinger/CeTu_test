#ifndef CETUHASHMAP_H
#define CETUHASHMAP_H

#include <optional>
#include <iostream>
#include <vector>

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
        // duplicate keys are not allowed
        for (int i = 0; i < keys.size(); i++) { if (keys[i] == key) { return; } }
        keys  .push_back(key);
        values.push_back(value);
    }

    // Lookup the given key in the map, if the key is not found return nullptr
    std::optional<V> lookup(K key)
    {
        for (int i = 0; i < keys.size(); i++) {
            if (keys[i] == key) {
                return values[i];
            }
        }

        return std::nullopt;
    }

    // Delete a pair with the key in the hashmap
    void erase(K key)
    {
        // very sloppy implementation, just to make it work for now

        for (int idx = 0; idx < keys.size(); idx++) {
            if (keys[idx] == key) {

                // the std::vector.erase does not compile, implemented the thing my way for now:

                // move everyting from idx to the end one position back
                for (int i = idx; i < keys.size()-1; i++) {
                    keys  [i] = keys  [i+1];
                    values[i] = values[i+1];
                }

                // remove the initial k:v pair
                keys  .pop_back();
                values.pop_back();

                return;
            }
        }
    }

    // debug print, TODO: remove garbage
    void print()
    {
        std::cout << "=== HASHMAP CONTENTS < ===" << std::endl;
        for (int i = 0; i < keys.size(); i++) {
            std::cout << keys[i] << " : " << values[i] << std::endl;
        }
        std::cout << "=== HASHMAP CONTENTS > ===" << std::endl;
    }

private:

    // ok, we need some custom memory management, as always
    std::vector<K> keys;
    std::vector<V> values;

};

#endif // CETUHASHMAP_H
