#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> V(N,0);
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        V[a]++;
    }
    int ans=1;
    if(N%2){
        if(V[0]!=1){
            ans=0;
        }
        for(int i=2;i<N;i+=2){
            if(V[i]==2){
                ans*=2;
                ans%=1000000007;
            }else{
                ans=0;
            }
        }
    }else{
        for(int i=1;i<N;i+=2){
            if(V[i]==2){
                ans*=2;
                ans%=1000000007;
            }else{
                ans=0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}