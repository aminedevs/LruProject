#include <LruCache.hpp>

Lru::Lru(int capacity) : mCapacity(capacity)
{
}
int Lru::get(int key)
{
    auto it = mMap.find(key);
    if (it == mMap.end())
        return -1;
    mKeys.splice(mKeys.begin(), mKeys, it->second.second);
    return it->second.first;
}

void Lru::put(int key, int value)
{
    auto it = mMap.find(key);
    if (it != mMap.end())
    {
        // the key exists already, update value
        it->second.first = value;
        // move the key to the top
        mKeys.splice(mKeys.begin(), mKeys, it->second.second);
    }
    else
    {
        if (mMap.size() >= mCapacity)
        {
            // remove the last key (from the list and the map)
            auto keyToRemove = mKeys.back();
            mKeys.pop_back();
            mMap.erase(keyToRemove);
        }
        // add the new key at the top
        mKeys.push_front(key);
        // add the key, value and it to the map
        mMap[key] = {value, mKeys.begin()};
    }
}