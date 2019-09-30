#include <iostream>
#include <string>

int main()
{
    int a,b,c,counter = 0;
    std::cin >> a >> b >> c;
    if(a==b) counter++;
    if(a==c) counter++;
    if(b==c) counter++;
    if(a==b&&b==c) counter =2;
    std::cout << 3-counter << std::endl;
    return 0;
}