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
    string S;
    cin>>S;
    int L = S.size();
    int64_t ans = 0;
    for(int i=0;i<L;i++){
        if(S[i]=='U'){
            ans+=L-i-1;
            ans+=2*i;
        }else{
            ans+=2*(L-i-1);
            ans+=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}