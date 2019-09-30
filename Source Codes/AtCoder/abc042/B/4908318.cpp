#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


int main()
{
    int N, L;
    std::cin >> N >> L;
    std::vector<std::string> a(N);
    for(int i = 0; i < N; i++){
        std::cin >> a.at(i);
    }
    sort(a.begin(),a.end());
    for(int i = 0; i < N; i++){
        std::cout << a.at(i);
    }
    return 0;
}