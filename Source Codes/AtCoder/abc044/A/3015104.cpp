#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

int main(void) {
    cout << std::fixed << std::setprecision(10);
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    int result=0;
    if(n<=k){
        result=n*x;
    }else{
        result=k*x+(n-k)*y;
    }
    cout<<result<<endl;

    return 0;
}