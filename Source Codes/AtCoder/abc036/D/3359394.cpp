#include <iostream>
#include<math.h>
#include<algorithm>
#include <stdio.h>
#include<map>
#include<stack>
#include<vector>
typedef long long int ll;
const int p=1000000007;
using namespace std;

stack<int> s,dp;
int n;
int a,b;
bool visited[100000];
vector<int> rinsetu[100000];
ll par[100000],ans[100000][2];
void dfs(void);
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        rinsetu[a-1].push_back(b-1);
        rinsetu[b-1].push_back(a-1);
    }
    for(int i=0;i<n;i++){
        visited[i]=false;
        ans[i][0]=1;
        ans[i][1]=1;
        par[i]=n;
    }

    dfs();
    par[0]=n;

    for(int i=0;i<n;i++){
        a=dp.top();
        dp.pop();
        for(int j=0;j<rinsetu[a].size();j++){
            if(rinsetu[a][j]!=par[a]){
                ans[a][0]=(ans[a][0]*(ans[rinsetu[a][j]][0]+ans[rinsetu[a][j]][1]))%p;
                ans[a][1]=(ans[a][1]*ans[rinsetu[a][j]][0])%p;
            }
        }
    }

    cout<<(ans[0][0]+ans[0][1])%p<<endl;
    

    
}
void dfs(){
    int v=0;
    visited[v]=true;
    s.push(v);
    while(s.size()>0){
        v=s.top();
        s.pop();
        dp.push(v);
        for(int i=0;i<rinsetu[v].size();i++){
            if(!visited[rinsetu[v][i]])s.push(rinsetu[v][i]);
            visited[rinsetu[v][i]]=true;
            if(par[rinsetu[v][i]]==n)par[rinsetu[v][i]]=v;
        }
    }
}