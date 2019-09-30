#include <stdio.h>
int Min2(int a,int b){
    return a<b?a:b;
}

int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    int d[30][30];
    int cnt[3][30]={0};
    int i,j,k;
    for(i=0;i<c;i++){
        for(j=0;j<c;j++){
            scanf("%d",&d[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            int tmp;
            scanf("%d",&tmp);
            cnt[(i+j)%3][tmp-1]++;
        }
    }
/*
    puts("");
    for(i=0;i<3;i++){
        for(j=0;j<c;j++){
            printf("%d ",cnt[i][j]);
        }
        puts("");
    }
*/
    int iwa[3][30]={0};
    for(i=0;i<3;i++){
        for(j=0;j<c;j++){
            for(k=0;k<c;k++){
                iwa[i][j]+=d[k][j]*cnt[i][k];
            }
        }
    }
/*
    puts("");
    for(i=0;i<3;i++){
        for(j=0;j<c;j++){
            printf("%d ",iwa[i][j]);
        }
        puts("");
    }
*/
    int ans=1000000000;
    for(i=0;i<c;i++){
        for(j=0;j<c;j++){
            if(i==j)continue;
            for(k=0;k<c;k++){
                if(i==k||j==k)continue;
                //printf("%d %d %d:%d %d %d %d\n",i,j,k,ans,iwa[0][i],iwa[1][j],iwa[k]);
                ans=Min2(ans,iwa[0][i]+iwa[1][j]+iwa[2][k]);
                //printf("%d %d %d:%d\n",i,j,k,ans);
            }
        }
    }
    printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&c);
     ^
./Main.c:14:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&d[i][j]);
             ^
./Main.c:20:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&tmp);
             ^