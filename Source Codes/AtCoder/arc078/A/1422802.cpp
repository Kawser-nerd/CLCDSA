#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;

int main(){
    int N;
    cin>>N;
    vector<int64_t> V(N);
    for(int i=0;i<N;i++){
        cin>>V[i];
        if(i)V[i]+=V[i-1];
    }
    int64_t ans = 1LL<<60;
    for(int i=0;i<N-1;i++){
        ans = min(ans, abs(V[N-1]-2*V[i]));
    }
    cout<<ans<<endl;
    return 0;
}