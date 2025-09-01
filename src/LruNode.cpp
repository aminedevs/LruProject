#include <LruNode.hpp>

LruNode::LruNode(int id, int capacity) : mId(id), mCache(capacity)
{
}
void LruNode::Put(int key, int value)
{
    mCache.put(key, value);
}

int LruNode::Get(int key)
{
    return mCache.get(key);
}