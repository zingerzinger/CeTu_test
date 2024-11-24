#ifndef CETUHASHMAP_H
#define CETUHASHMAP_H

#include <optional>

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
        for (int i = 0; i < keys.size(); i++) {
            if (keys[i] == key) { return; }
        }

        keys  .push_back(key);
        values.push_back(value);
    }

    // Lookup the given key in the map, if the key is not found return nullptr
    std::optional<V> lookup(K key)
    {
        return std::nullopt;
    }

    // Delete a pair with the key in the hashmap
    void erase(K key)
    {

    }

private:

    // ok, we need some custom memory management, as always
    std::vector<K> keys;
    std::vector<V> values;



};

#endif // CETUHASHMAP_H
