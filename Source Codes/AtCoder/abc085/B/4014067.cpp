#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N ;
    std::cin >> N ;
    int tmp;
    std::vector<int> d;
    for(int i=0; i<N; ++i){
        std::cin >> tmp ;
        d.push_back(tmp) ;
    }

    std::sort(d.begin(), d.end()) ;
    std::reverse(d.begin(), d.end()) ;
    int max=1000;
    int cnt=0;
    for(auto x: d)
    {
        if(x<max)
            cnt++ ;
        max = x ;
    }
    std::cout << cnt << std::endl ;
}