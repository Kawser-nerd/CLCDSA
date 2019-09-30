#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//=================================================================
// Begginer Contest 115 D

uint64_t getpattynum(vector<uint64_t>& layer, vector<uint64_t>& patty, uint64_t N, uint64_t X){
    if(N==0){
        return (X>0 ? 1 : 0);
    }else if(X<=1+layer[N-1]){
        return getpattynum(layer, patty, N-1, (X>=1 ? X-1 : 0));
    }else{
        return patty[N-1]+1+getpattynum(layer, patty, N-1, X-layer[N-1]-2);
    }
}

int main(){
    uint64_t N,X;
    cin >> N >> X;
    vector<uint64_t> layer(N+1,1);
    vector<uint64_t> patty(N+1,1);
    uint64_t ans;

    for(int i=1;i<N+1;i++){
        layer[i] = layer[i-1]*2+3;
        patty[i] = patty[i-1]*2+1;
    }

    cout << getpattynum(layer,patty,N,X) << endl;

    return 0;
}