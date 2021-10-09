//Value semantic
#include <variant>
#include <iostream>

#include <functional>
void foo1(int i)
{
    std::cout << "Foo1\n";
}

void foo2(int i)
{
    std::cout << "Foo2\n";
}

int main()
{
    
    std::function<void(int)> f1 = foo1;
    f1(1);
    auto f2 = f1;
    f1 = foo2;

    f1(1);
    f2(1);
}
