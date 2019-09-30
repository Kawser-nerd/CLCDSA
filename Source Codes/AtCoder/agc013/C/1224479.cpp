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
    int64_t L,T;
    cin>>N>>L>>T;
    vector<int64_t> X(N),W(N);
    for(int i=0;i<N;i++){
        cin>>X[i]>>W[i];
    }
    int64_t cnt = 0;
    for(int i=1;i<N;i++){
        if(W[0]==W[i]) continue;
        if(W[0]==1&&W[i]==2){
            if(X[i]-X[0]<=2*T){
                cnt+=1+(2*T-(X[i]-X[0]))/L;
            }
        }
        if(W[0]==2&&W[i]==1){
            if(X[0]+(L-X[i])<=2*T){
                cnt+=1+(2*T-(X[0]+(L-X[i])))/L;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(W[i]==1){
            X[i]=(X[i]+T)%L;
        }else{
            X[i]=(X[i]+L-(T%L))%L;
        }
    }
    int x=X[0],idx;
    sort(X.begin(), X.end());
    if(W[0]==1){
        idx=cnt%N;
    }else{
        idx=(N-(cnt%N))%N;
    }
    for(int i=0;i<N;i++){
        if(x==X[i]){
            if(i+1<N&&X[i+1]==X[i]&&W[0]==1){
                i++;
            }
            for(int j=(N+i-idx)%N;j<N;j++){
                cout<<X[j]<<endl;
            }
            for(int j=0;j<(N+i-idx)%N;j++){
                cout<<X[j]<<endl;
            }
            break;
        }
    }
    return 0;
}