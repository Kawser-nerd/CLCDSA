#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){

int N,M;
cin>>N>>M;
bool con[N][N];
if(M ==0){
    cout<<1<<endl;
    return 0;
}
//fill(con,false);
for(int i =0;i<N;i++){
    for(int j =0;j<N;j++){
        con[i][j] = false;
    }
}

int ans = 0;
for(int i =0;i<M;i++){
    int x,y;
    cin>>x>>y;
    con[x-1][y-1] = true;
    con[y-1][x-1] = true;
}
for(int i = 0;i<(1<<N);i++){
    vector<int> v;
    for(int j=0;j<N;j++){
        if(((i>>j)&1)==1){v.push_back(j);}
    }
    bool flag = true;
    //int tmp = 0;
    int j;
    for(j = 0;j<v.size();j++){

        for(int k = j+1;k<v.size();k++){
            if(!con[v[j]][v[k]]){flag = false;j=-1;break;}
        }
        if (!flag){break;}
        
    }
    ans =  j > ans ? j : ans;
}
    cout<<ans<<endl;
    return 0;
}