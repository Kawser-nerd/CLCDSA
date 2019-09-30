#include <iostream>
#include <vector>

int main(void)
{
    int n;
    std::cin >> n;
    std::vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    for (int i = 3; i < n; ++i)
    {
        int a = v[v.size() - 1];
        int b = v[v.size() - 2];
        int c = v[v.size() - 3];
        v.push_back((a + b + c) % 10007);
    }
    std::cout << v[n - 1] << std::endl;
    return 0;
}