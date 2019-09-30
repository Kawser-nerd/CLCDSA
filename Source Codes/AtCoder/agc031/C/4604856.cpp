#include<cstdio>
#include<vector>
using namespace std;
int n,two[18],used[200000],a,b,cnt=0,bit[18];
vector<int> ans,jun,jun2;
bool dfs(int x,int y){
    int z;
    bool res=false;
    used[x]=1;
    ans.push_back(x);
    z=0;
    for(int i=0;i<n;i++){
        if(ans.size()+two[i]>=two[n]){
            z=n-i;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(z!=n&&ans.size()!=two[n]-1&&(x^two[i])!=y&&used[(x^two[i])]==0&&((y&two[jun[z]])^((x^two[i])&two[jun[z]]))){
            res= dfs((x^two[i]),y);
        }
        if(ans.size()==two[n]-1&&(x^two[i])==y){
            ans.push_back(y);
            return true;
        }
        if(res==true){
            return res;
        }
    }
    ans.pop_back();
    used[x]=0;
    return false;
}
int main(){
    scanf("%d %d %d",&n,&a,&b);
    two[0]=1;
    for(int i=1;i<=n;i++){
        two[i]=two[i-1]*2;
    }
    for(int i=0;i<n;i++){
        if(a&two[i]){
            cnt++;
        }
        if(b&two[i]){
            cnt++;
            bit[i]=1;
        }
        if((a&two[i])^(b&two[i])){
            jun.push_back(i);
        }
        else{
            jun2.push_back(i);
        }
    }
    if(cnt%2==0){
        printf("NO\n");
        return 0;
    }
    for(int i=0;i<jun2.size();i++){
        jun.push_back(jun2[i]);
    }
    if(dfs(a,b)){
        printf("YES\n");
        for(int i=0;i<ans.size();i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
    else{
        printf("NO\n");
    }
}