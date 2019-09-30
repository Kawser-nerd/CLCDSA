#include <iostream>
#include <string>

#define INC(i, a, b) for(int i = a; i < b; ++i)
#define DEC(i, a, b) for(int i = a; i >= b; --i)
#define REP(i, n) INC(i, 0, n)

typedef unsigned int uint;
typedef unsigned long ul;
typedef long long  ll;
typedef unsigned long long ull;

void TFprint(bool b, std::string T, std::string F){
    if(b){
        std::cout << T;
    }else{
        std::cout << F;
    }
}

int main(){
    int n; std::cin >> n;
    ull a[n];
    ull b[n];

    REP(i, n){
        std::cin >> a[i];
        std::cin >> b[i];
    }

    ull count = 0;

    DEC(i, n - 1, 0){
        a[i] += count;
        ull goal = a[i] / b[i];
        if(a[i] % b[i] > 0){
            goal++;
        }
            
        count += goal * b[i] - a[i];
    }

    std::cout << count << std::endl;
    return 0;
}