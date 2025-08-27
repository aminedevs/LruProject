#include <LruNode.hpp>
#include <vector>
class Router
{
public:
    Router(int nodes, int capacity);

    void Insert(int key, int value);
    int Request(int key);

private:
    std::vector<LruNode> mNodes;
    int mSize;
};