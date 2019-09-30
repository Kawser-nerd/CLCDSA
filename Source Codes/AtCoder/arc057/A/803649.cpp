//C++14 (Clang 3.8.0)

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main(){
    
    long long A,K;
    cin>>A>>K;
    long long tyo=2*1000000000000,d=0;
    if (K==0){
        cout << tyo - A << endl;
        return 0;
    }
    while(A<tyo){
        A=1+K*A+A;
        d=d+1;
        
    }
    cout<<d<<endl;
    return 0;
};