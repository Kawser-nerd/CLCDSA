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
    long long A,B,C;
    cin>>A>>B>>C;
    vector<long long> N;
    N.push_back(A);
    N.push_back(B);
    N.push_back(C);
    sort(N.begin(),N.end());
    long long ans= N[0]*N[1];
    ans=min(ans,N[1]*N[2]);
    ans=min(ans,N[0]*N[2]);
    if(N[0]%2==0 or N[1]%2==0 or N[2]%2==0) cout<<"0"<<endl;
    else cout<<ans<<endl;
    return 0;
};