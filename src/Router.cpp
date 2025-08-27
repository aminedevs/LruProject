#include <Router.hpp>
#include <iostream>

Router::Router(int nodes, int capacity) : mSize(nodes)
{
    for (int index = 0; index < mSize; index++)
    {
        mNodes.push_back(LruNode(index, capacity));
    }
}

void Router::Insert(int key, int value)
{
    auto dispatch = key % mSize;
    std::cout << "routing to node " << dispatch << std::endl;
    mNodes[dispatch].Put(key, value);
}

int Router::Request(int key)
{
    auto dispatch = key % mSize;
    std::cout << "routing to node " << dispatch << std::endl;
    return mNodes[dispatch].Get(key);
}