#include <iostream>

int main(void)
{
    int n;
    std::cin >> n;
    if (n <= 59)
    {
        std::cout << "Bad";
    }
    else if (n <= 89)
    {
        std::cout << "Good";
    }
    else if (n <= 99)
    {
        std::cout << "Great";
    }
    else
    {
        std::cout << "Perfect";
    }
    std::cout << std::endl;
    return 0;
}