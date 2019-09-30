#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;
typedef pair<int,int> P;
typedef tuple<int,vector<int64_t>,int,vector<int64_t>> T; //sum,L,M,R;

int64_t rec(int l, int r, vector<int> &A){
    if(r<=l) return 0;
    if(r-l==1){
        if(A[l]>=0) return 1;
        else return 0;
    }else{
        int d = (l+r)/2;
        int64_t cnt = 0;
        int64_t sum=0;
        vector<int64_t> V;
        for(int i=d-1;i>=l;i--){
            sum+=A[i];
            V.push_back(sum);
        }
        sort(V.begin(), V.end());
        sum=0;
        for(int i=d;i<r;i++){
            sum+=A[i];
            cnt+=(V.end()-lower_bound(V.begin(), V.end(),-sum));
        }
        return cnt+rec(l,d,A)+rec(d,r,A);
    }
}

int main(){
    int N,K;
    cin>>N>>K;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
        A[i]-=K;
    }
    cout<<rec(0,N,A)<<endl;

    return 0;
}