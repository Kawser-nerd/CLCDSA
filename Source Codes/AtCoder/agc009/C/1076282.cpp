#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100000
#define MOD 1000000007
int64_t S[MAX_N+1];
int64_t DPA[MAX_N+1];
int64_t DPB[MAX_N+1];

int main(){
    int N;
    int64_t A,B;
    cin>>N>>A>>B;
    S[0]=INT64_MIN;
    for(int i=1;i<=N;i++){
        cin>>S[i];
    }
    DPA[0]=DPB[0]=1;
    int Azero=-1,Bzero=-1;
    for(int i=2;i<=N;i++){
        int KB = min((int)(upper_bound(S,S+i,S[i]-B)-S)-1,i-2);
        //DPB[i-1]=(KB>Azero?DPA[KB]-(Azero>=0?DPA[Azero]:0):0)+DPB[i-2];
        if(KB>Azero){
            if(Azero>=0){
                DPB[i-1]=(DPA[KB]+MOD-DPA[Azero])%MOD;
            }else{
                DPB[i-1]=DPA[KB];
            }
        }
        DPB[i-1]=(DPB[i-1]+DPB[i-2])%MOD;

        int KA = min((int)(upper_bound(S,S+i,S[i]-A)-S)-1,i-2);
        //DPA[i-1]=(KA>Bzero?DPB[KA]-(Bzero>=0?DPB[Bzero]:0):0)+DPA[i-2];
        if(KA>Bzero){
            if(Bzero>=0){
                DPA[i-1]=(DPB[KA]+MOD-DPB[Bzero])%MOD;
            }else{
                DPA[i-1]=DPB[KA];
            }
        }
        DPA[i-1]=(DPA[i-1]+DPA[i-2])%MOD;

        if(S[i]<S[i-1]+A){
            Azero=max(Azero,i-2); //..Azero]????0
        }
        if(S[i]<S[i-1]+B){
            Bzero=max(Bzero,i-2);
        }
    }
    int64_t ans=0;
    ans=(ans+DPA[N-1]+MOD-DPA[Azero])%MOD;
    ans=(ans+DPB[N-1]+MOD-DPB[Bzero])%MOD;
    cout<<ans<<endl;
    return 0;
}