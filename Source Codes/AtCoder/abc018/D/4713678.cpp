#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    priority_queue<int> pq;
    int n,m,p,q,r,g[18][18]={},x,y,z,ans=0,a,bit[18]={},cnt;
    scanf("%d %d %d %d %d",&n,&m,&p,&q,&r);
    for(int i=0;i<r;i++){
        scanf("%d %d %d",&x,&y,&z);
        x--;
        y--;
        g[x][y]=z;
    }
    a=(1<<n);
    for(int i=0;i<a;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                bit[j]=1;
                cnt++;
            }
            else{
                bit[j]=0;
            }
        }
        if(cnt<=p){
            for(int j=0;j<m;j++){
                x=0;
                for(int k=0;k<n;k++){
                    if(bit[k]){
                        x+=g[k][j];
                    }
                }
                pq.push(x);
            }
            y=0;
            for(int j=0;j<q;j++){
                y+=pq.top();
                pq.pop();
            }
            while(!pq.empty()){
                pq.pop();
            }
            ans=max(ans,y);
        }
    }
    printf("%d\n",ans);
}