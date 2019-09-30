#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> V(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        V[a]++; V[b]++;
    }
    for(auto &v:V){
        if(v%2){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}