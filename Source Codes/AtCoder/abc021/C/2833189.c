#include <stdio.h>
 
int main(void){
    int n,a,b,city[110],len[110][110],shortest,m,x,y,visited[110]={},ans[110]={};
    scanf ("%d%d%d%d",&n,&a,&b,&m);
    for (int i=1; i<=n; i++){
        city[i]=1e9;
    }
    city[a]=0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            len[i][j]=1e9;
        }
    }
    for (int i=0; i<m; i++){
        scanf("%d%d",&x,&y);
        len[x][y]=1;
        len[y][x]=1;
    }
    while (1){
        int min=1e9,next;
        for (int i=1; i<=n; i++){
            if(visited[i]==0 && min>city[i]){
                min=city[i];
                next=i;
            }
        }
        if (next==b){
            shortest=city[b];
            break;
        }
        
        for (int i=1; i<=n; i++){
            if(city[i]>len[i][next]+city[next]){
                city[i]=len[i][next]+city[next];
            }
        }
        visited[next]=1;
    }
    for (int i=shortest; i>=0; i--){
        if (i==shortest){
            for (int j=0; j<=n; j++){
                if (city[j]==i-1 && len[j][b]==1){
                    ans[j]=1;
                }
            }
        } else {
            for (int j=1; j<=n; j++){
                if(city[j]==i){
                    for (int k=0; k<=n; k++){
                        if(city[k]==i+1 && len[j][k]==1){
                            ans[j]=(ans[j]+ans[k])%1000000007;
                        }
                    }
                }
            }    
        }
    }
    printf ("%d\n",ans[a]);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%d%d%d%d",&n,&a,&b,&m);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&x,&y);
         ^