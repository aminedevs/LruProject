#include <Router.hpp>
#include <iostream>
#include <functional>

Router::Router(int nodes, int capacity) : mSize(nodes)
{
    for (int index = 0; index < mSize; index++)
    {
        mNodes.push_back(LruNode(index, capacity));
    }
}

void Router::Insert(int key, int value)
{
    auto dispatch = GetDispatchId(key);
    std::cout
        << "routing to node " << dispatch << std::endl;
    mNodes[dispatch].Put(key, value);
}

int Router::Request(int key)
{
    auto keyHash = std::hash<int>{}(key);
    auto dispatch = keyHash % mSize;
    std::cout << "routing to node " << dispatch << std::endl;
    return mNodes[dispatch].Get(key);
}

int Router::GetDispatchId(int key) const
{
    auto keyHash = std::hash<int>{}(key);
    return keyHash % mSize;
}