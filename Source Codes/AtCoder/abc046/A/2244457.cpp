#include <iostream>
#include <set>

int main(void)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    std::set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    std::cout << s.size() << std::endl;
    return 0;
}