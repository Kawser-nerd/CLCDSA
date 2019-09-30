#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N;
    cin>>N;
    vector<int> V(N+1);
    for(int i=0;i<N;i++) cin>>V[i];
    int64_t ans=0;
    for(int i=0;i<N;i++){
        if(V[i+1]-V[i]>1||V[0]){
            ans=-1;
            break;
        }else if(V[i+1]<=V[i]){
            ans+=V[i];
        }
    }
    cout<<ans<<endl;

    return 0;
}