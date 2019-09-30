#include <iostream>
#include <string>

int main()
{
    int a,b;
    std::string op;
    std::cin >> a >> op >> b;
    if(op == "+") std::cout << a + b;
    else if(op == "-") std::cout << a - b;
    return 0;
}