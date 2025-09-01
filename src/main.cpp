#include <iostream>
#include <Router.hpp>

int main()
{
    auto count = 20;
    Router myRouter(3, 3);

    for (int i = 0; i < count; i++)
    {
        myRouter.Insert(i, i * 100);
    }
}
