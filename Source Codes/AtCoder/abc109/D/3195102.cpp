#include<iostream>
#include<vector>
#define pb push_back
using namespace std;
int t[501][501];
vector<int>zm;
int x,y;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>y>>x;
    for(int i=0;i<y;++i){
        for(int j=0;j<x;++j){
            cin>>t[i][j];
        }
    }
    for(int i=0;i<y;++i){
        for(int j=0;j<x-1;++j){
            if(t[i][j]%2!=0){
                zm.pb(i+1);
                zm.pb(j+1);
                zm.pb(i+1);
                zm.pb(j+2);
                t[i][j+1]++;
                t[i][j]--;
            }
        }
    }
    for(int i=0;i<y-1;++i){
        if(t[i][x-1]%2!=0){
            zm.pb(i+1);
            zm.pb(x);
            zm.pb(i+2);
            zm.pb(x);
            t[i+1][x-1]++;
            t[i][x-1]--;
        }
    }
    cout<<zm.size()/4<<"\n";
    for(int i=0;i<zm.size();i+=4){
        cout<<zm[i]<<" "<<zm[i+1]<<" "<<zm[i+2]<<" "<<zm[i+3];
        if(i+4<zm.size())cout<<"\n";

    }

}