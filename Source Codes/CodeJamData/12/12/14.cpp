#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int ai[1010],bi[1010];
int u[1010];
int main(){
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        int i;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d%d",&ai[i],&bi[i]);
        memset(u,0,sizeof(u));
        int ns=0,c=0;
        while(ns<2*n){
            c++;
            for(i=0;i<n;i++){
                if(u[i]==2)continue;
                if(bi[i]<=ns){
                    if(u[i]==0)ns+=2;
                    else ns+=1;
                    u[i]=2;
                    break;
                }
            }
            if(i<n)continue;
            int mt=-1,mp;
            for(i=0;i<n;i++){
                if(u[i]==0&&ai[i]<=ns){
                    if(bi[i]>mt){
                        mt=bi[i];
                        mp=i;
                    }
                }
            }
            if(mt==-1){
                break;
            }
            u[mp]=1;
            ns++;
        }
        printf("Case #%d: ",cas++);
        if(ns==2*n)printf("%d\n",c);
        else puts("Too Bad");
    }
}

