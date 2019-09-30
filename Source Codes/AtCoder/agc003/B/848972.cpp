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
    int N;
    long long A[100001];
    cin>>N;
    for(int i=0;i<N;i++) scanf("%lli", &A[i]);
    long long ans=0;
    long long sum=0;
    for(int i=0;i<N;i++){
        if(A[i]!=0){
            sum+=A[i];
        }
        if(A[i]==0){ans+=sum/2;sum=0;}
    }        
    ans+=sum/2;
    cout<<ans<<endl;
    return 0;
};