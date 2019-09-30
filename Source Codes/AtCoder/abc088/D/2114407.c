#include <stdio.h>
#include <stdlib.h>
int h,w;
char s[50][51];
int d[4][2]={{1,0},{0,-1},{-1,0},{0,1}};

int bfs(int a,int b){
    int q[2500][3];
    memset(q,-1,sizeof(q));
    q[0][0]=a;q[0][1]=b;q[0][2]=1;
    int visit[50][50]={0};
    visit[a][b]=1;
    int l=0,m=1;
    while(q[l][0]!=-1){
        int i;
        for(i=0;i<4;i++){
            int y=q[l][0]+d[i][0];
            int x=q[l][1]+d[i][1];
            if(0<=y&&y<h&&0<=x&&x<w&&!visit[y][x]&&s[y][x]=='.'){
                //printf("%d %d\n",y,x);
                if(y==h-1&&x==w-1)return q[l][2]+1;
                visit[y][x]=1;
                q[m][0]=y;
                q[m][1]=x;
                q[m++][2]=q[l][2]+1;
            }
        }
        l++;
    }
    return -1;
}

int main(){
    scanf("%d %d",&h,&w);
    int i,j;
    int cnt=0;
    for(i=0;i<h;i++){
        scanf("%s",&s[i]);
        for(j=0;j<w;j++){
            if(s[i][j]=='.')cnt++;
        }
    }
    int dis = bfs(0,0);
    if(dis==-1){
        puts("-1");
    }else{
        printf("%d\n",cnt-dis);
    }
} ./Main.c: In function ‘bfs’:
./Main.c:9:5: warning: implicit declaration of function ‘memset’ [-Wimplicit-function-declaration]
     memset(q,-1,sizeof(q));
     ^
./Main.c:9:5: warning: incompatible implicit declaration of built-in function ‘memset’
./Main.c:9:5: note: include ‘<string.h>’ or provide a declaration of ‘memset’
./Main.c: In function ‘main’:
./Main.c:38:15: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[51]’ [-Wformat=]
         scanf("%s",&s[i]);
               ^
./Main.c:34:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&h,&w);
     ^
./Main.c:38:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",&s[i]);
         ^