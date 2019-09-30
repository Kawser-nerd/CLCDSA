#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int K,M;
    cin>>K>>M;
    vector<uint32_t> A(K),C(K);
    for(int i=0;i<K;i++) cin>>A[i];
    for(int i=0;i<K;i++) cin>>C[i];
    if(M<=K){
        cout<<A[M-1]<<endl;
        return 0;
    }
    uint32_t P[K][K], ANS[K][K];
    fill(P[0],P[K],0); fill(ANS[0],ANS[K],0);
    for(int i=0;i<K;i++) ANS[i][i]=0xFFFFFFFF;
    for(int i=0;i<K;i++) P[0][i]=C[i];
    for(int i=1;i<K;i++) P[i][i-1]=0xFFFFFFFF;

    uint32_t temp[K][K];
    M-=K;
    while(M>0){
        fill(temp[0],temp[K],0);
        if(M&1){//temp=P*ANS
            for(int i=0;i<K;i++){
                for(int j=0;j<K;j++){
                    for(int k=0;k<K;k++){
                        temp[i][j]^=(P[i][k]&ANS[k][j]);
                    }
                }
            }
            for(int i=0;i<K;i++){
                for(int j=0;j<K;j++) ANS[i][j]=temp[i][j];
            }
        }
        fill(temp[0],temp[K],0);
        //temp=P*P
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++){
                for(int k=0;k<K;k++) temp[i][j]^=(P[i][k]&P[k][j]);
            }
        }
        for(int i=0;i<K;i++){
            for(int j=0;j<K;j++) P[i][j]=temp[i][j];
        }

        M>>=1;
    }

    uint32_t ans = 0;
    for(int i=0;i<K;i++) ans^=(ANS[0][i]&A[K-1-i]);
    cout<<ans<<endl;

    return 0;
}