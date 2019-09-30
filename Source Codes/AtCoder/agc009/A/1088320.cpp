#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(false);
    for(int N; std::cin >> N; )
    {
        typedef long long T;
        std::vector<std::pair<T,T>> ab(N);
        for(auto&v:ab) std::cin >> v.first >> v.second;
        T c=0;
        for(int i=N-1; i>=0; --i) {
            const auto a=ab[i].first,b=ab[i].second;
            c+=(b-(a+c)%b)%b;
        }
        std::cout << c << std::endl;
    }
}