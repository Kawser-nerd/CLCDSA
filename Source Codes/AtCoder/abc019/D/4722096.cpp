#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n,p;
    ll dist,l=0;
    cin>>n;
    for(int i=2;i<=n;i++){
        cout<<"? "<<1<<" "<<i<<endl;
        cin>>dist;
        if(l<dist){
            l=dist;
            p=i;
        }
    }
    l=0;
    for(int i=1;i<=n;i++){
        if(i!=p){
            cout<<"? "<<p<<" "<<i<<endl;
            cin>>dist;
            if(l<dist){
                l=dist;
            }
        }
    }
    cout<<"! "<<l<<endl;
}