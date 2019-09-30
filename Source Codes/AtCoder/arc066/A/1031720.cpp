#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
int cnt[100000];
int main(){
    int N;
    cin>>N;
    int n=0;
    for(int i=0;i<N;i++){
        int A;
        cin>>A;
        cnt[A]++;
        n=max(n,A);
    }
    bool flag=false;
    if(N%2){
        if(cnt[0]!=1){
            flag=true;
        }else{
            for(int i=2;i<N;i+=2){
                if(cnt[i]!=2){
                    flag=true;
                    break;
                }
            }
        }
    }else{
        for(int i=1;i<N;i+=2){
            if(cnt[i]!=2){
                flag=true;
                break;
            }
        }
    }
    if(flag){
        cout<<0<<endl;
        return 0;
    }

    if(N%2)N--;
    N/=2;
    int ans=1;
    for(int i=0;i<N;i++){
        ans*=2;
        ans%=1000000007;
    }
    cout<<ans<<endl;
    return 0;
}