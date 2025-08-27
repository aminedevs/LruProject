#include <LruCache.hpp>

class LruNode
{
public:
    LruNode(int id, int capacity);

    void Put(int key, int value);
    int Get(int key);

private:
    Lru mCache;
    int mId;
};