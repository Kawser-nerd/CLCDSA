#include <iostream>
#include <string>

#define INC(i, a, b) for(i = a; i < b; ++i)
#define DEC(i, a, b) for(i = a; i > b; --i)
#define REP(i, n) INC(i, 0, n)

typedef unsigned int uint;
typedef unsigned long ul;
typedef long long  ll;
typedef unsigned long long ull;

int abs(int x){
    return x > 0? x : -x;
}

int max(int a, int b){
    return a > b? a : b;
}

int min(int a, int b){
    return a < b? a : b;
}

void TFprint(bool b, std::string T, std::string F){
    if(b){
        std::cout << T;
    }else{
        std::cout << F;
    }
}

long calc(long init, long goal){
    long ret;

    if((init >= 0 && goal >= 0)|| (init < 0 && goal < 0)){
        if(init > goal){
            ret = init - goal + 2;
            if(goal == 0){
                ret--;
            }
        }else{
            ret = goal - init;
        }
    }else{
            ret = abs(init + goal) + 1;
            if(goal == 0){
                ret--;
            }
    }
    return ret;
}

int main(){
    long init, goal;
    std::cin >> init >> goal;
    //std::cout << init << ' ' << goal << std::endl;
    long ans = calc(init, goal);
    std::cout << std::dec << ans << std::endl;
}