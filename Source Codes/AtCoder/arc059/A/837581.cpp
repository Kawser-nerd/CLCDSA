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
    vector<int> a;
    cin>>N;
    for(int i=0;i<N;i++){int A;cin>>A;a.push_back(A);}

    int ave=0;
    for(int i=0;i<N;i++) ave+=a[i];
    ave=ave/N;
    int ans=100000000;
    
    for(int j=-1;j<=1;j++){
        int av=ave+j;
        int d=0;
        for(int i=0;i<N;i++) d=d+abs(a[i]-av)*abs(a[i]-av);
        if(ans>d) ans=d;
    }
    cout<<ans<<endl;
    return 0;
};