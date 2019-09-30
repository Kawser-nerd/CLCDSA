#include <iostream>

int classify(int x)
{
    switch (x)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:    return 1;
        case 4:
        case 6:
        case 9:
        case 11:    return 2;
        default:    return 3;
    }
}

int main(void)
{
    int x, y;
    std::cin >> x >> y;
    x = classify(x);
    y = classify(y);
    bool flag = (x == y);
    std::cout << (flag ? "Yes" : "No") << std::endl;
    return 0;
}