#include <iostream>
#include <string>

int main()
{
    int n,k;
    std::cin >> n >> k;
    int numbers = 1;
    for(int i = 0; i < n; i++){
        if(i==0) numbers *= k;
        else numbers *= k-1;
    }
    std::cout << numbers << std::endl;
}