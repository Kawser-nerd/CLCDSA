#include <iostream>

int main()
{
    long long a,b,x;
    std::cin >> a >> b >> x;
    long long suma,sumb;
    if(a == 0){
        suma = -1;
    }
    else{
        suma = (a-1)/x;
    }
    sumb = b/x;

    std::cout << sumb - suma;
    return 0;
}