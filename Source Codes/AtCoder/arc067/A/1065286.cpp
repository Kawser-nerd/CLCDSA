#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
bool isprime[1001];
int cnt[1001];

int main(){
    fill(isprime,isprime+1001,true);
    int N;
    cin>>N;
    isprime[0]=isprime[1]=false;
    for(int i=0;i<=1000;i++){
        if(isprime[i]){
            for(int k=2;k*i<=1000;k++){
                isprime[k*i]=false;
            }
        }
    }

    for(int i=1;i<=N;i++){
        int n=i;
        while(n>1){
            for(int j=0;j<=n;j++){
                if(isprime[j]&&n%j==0){
                    n/=j;
                    cnt[j]++;
                    break;
                }
            }
        }
    }
    int64_t ans=1;
    for(int i=1;i<=1000;i++){
        ans*=(cnt[i]+1);
        ans%=1000000007;
    }
    cout<<ans<<endl;
    return 0;
}