#include<cstdio>
#include<map>
#include<iostream>
using namespace std;
const int maxn = 1000000000;
map<int,int> peo;
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        int temp;
        cin>>temp;
        if(peo.find(temp) == peo.end()){
            peo[temp] = 1;
        }else{
            if(peo[temp] == 1){
                peo[temp] = 0;
            }else if(peo[temp] == 0){
                peo[temp] = 1;
            }
        }
    }
    int ans = 0;
    for(map<int,int>::iterator it = peo.begin();it != peo.end();it++){
        if(it->second == 1) ans++;
    }
    cout<<ans;
}