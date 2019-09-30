#include <stdio.h>

int main(void){
    int n,m,max=1000000007;
    scanf("%d %d",&n,&m);
    int u[m],v[m],l[m],len[320][320],con[320],count=0;
    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
                len[i][j]=max;
        }
    }
    for (int i=0; i<m; i++){
        scanf("%d%d%d",&u[i],&v[i],&l[i]);
        len[u[i]][v[i]]=l[i];
        len[v[i]][u[i]]=l[i];
        if (u[i]==1){
            con[count]=v[i];
            count++;
        }
    }
    for (int k=2; k<=n; k++){
        for (int i=2; i<=n; i++){
            for (int j=2; j<=n; j++){
                if(len[i][j]>len[i][k]+len[k][j]){
                    len[i][j]=len[i][k]+len[k][j];
                }
            }
        }
    }
    
    int ans=max,tmp;
    for (int i=0; i<count; i++){
        for (int j=i+1; j<count; j++){
            tmp=len[1][con[i]]+len[con[i]][con[j]]+len[con[j]][1];
            if (tmp<ans){
                ans=tmp;
            }
        }
    }
    if (ans>=max){
        ans=-1;
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&m);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&u[i],&v[i],&l[i]);
         ^