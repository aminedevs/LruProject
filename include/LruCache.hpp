#pragma once
#include <unordered_map>
#include <list>

class Lru
{
public:
    Lru(int capacity);
    int get(int key);
    void put(int key, int value);

private:
    int mCapacity;
    std::list<int> mKeys;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> mMap;
};
