#include <iostream>
#include <string>
#include <vector>

#define INC(i, a, b) for(int i = a; i < b; ++i)
#define DEC(i, a, b) for(int i = a; i > b; --i)
#define REP(i, n) INC(i, 0, n)

typedef unsigned int uint;
typedef unsigned long ul;
typedef long long  ll;
typedef unsigned long long ull;

void TFprint(bool b, std::string T, std::string F){
    if(b){
        std::cout << T << std::endl;
    }else{
        std::cout << F << std::endl;
    }
}

int main(){
    int n; std::cin >> n;
    std::vector<ull> a;
    ull temp;
    ull ans = 0;

    REP(i, 3 * n){
        std::cin >> temp;
        a.push_back(temp);
    }
    std::sort(a.begin(), a.end(), std::greater<ull>());

    REP(i, n){
        //std::cout << a[2 * i + 1] << ' ';
        ans += a[2 * i + 1];
    }
    std::cout << std::endl;
    std::cout << ans << std::endl;
    return 0;
}