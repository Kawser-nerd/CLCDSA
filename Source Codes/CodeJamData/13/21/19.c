#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x,y)( (x<y)?x:y )
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int num[1234]={0};
int next[1234] = {0};
int ans;
int a,n;
void DFS(int aa,int now,int sum){
    int j;
    if(now > n){
        if(sum<ans)ans = sum;
        return;
    }
    if(num[now]<aa){
        DFS(aa+num[now],now+1,sum);
        return ;
    }else{
        DFS(aa,now+1,sum+1);
        for(j=0;num[now]>=aa&&aa>1;++j){
            aa += (aa-1);
        }
        if(num[now]<aa){
            DFS(aa+num[now],now+1,sum+j);
        }

    }
}
int main(){
    int T,t;
    int i;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%d %d",&a,&n);

        for(i=1;i<=n;++i){
            scanf("%d",&num[i]);
        }
        qsort(&num[1],n,sizeof(num[0]),cmp);
        ans = 92345678;

        for(i=1;i<=n&&num[i]<a;++i){
            a += num[i];
        }
        DFS(a,i,0);
        printf("Case #%d: %d\n",t,ans);
    }

    return 0;
}
