#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
template <class... T> void printd(T&&...){ }
#endif

int visited[100][100];
int memo[100][100];
bool solve(int x, int y){
    if(visited[x][y]){ return memo[x][y]; }
    visited[x][y] = 1;
    if(x <= 1 && y <= 1){
        return false;
    }
    bool win = false;
    for(int i=1;i<=x/2;i++){
        win |= !solve(x - i * 2, y + i);
    }
    for(int i=1;i<=y/2;i++){
        win |= !solve(x + i, y - i * 2);
    }
    return memo[x][y] = win;
}

int main(){
    ll x, y;
    cin >> x >> y;
    if(abs(x - y) <= 1){
        cout << "Brown" << '\n';
    }else{
        cout << "Alice" << '\n';
    }
    return 0;
    int i = 8;
    for(int j=0;j<50;j++){
        prints(i, j, solve(i, j) ? 'A' : 'B');
    }
    return 0;
}