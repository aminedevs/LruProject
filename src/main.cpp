#include <iostream>
#include <LruCache.hpp>

int main()
{
    Lru lru(2);
    lru.put(1, 110);
    lru.put(2, 220);
    std::cout << "Get 1: " << lru.get(1) << std::endl;
    lru.put(3, 300);
    std::cout << "Get 2: " << lru.get(2) << std::endl; // -1
}
