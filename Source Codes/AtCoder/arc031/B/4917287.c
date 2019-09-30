#include <stdio.h>
#include <string.h>
#define rep(i,l,r) for((i)=(l);(i)<(r);(i)++)
char c[10][11],buf[10][11];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void dfs(int x,int y){
    int nx,ny,i;
    c[x][y]='x';
    rep(i,0,4){
        nx=x+dx[i],ny=y+dy[i];
        if(nx>=0&&nx<10&&ny>=0&&ny<10&&c[nx][ny]=='o')dfs(nx,ny);
    }
}
int check(){
    int i,j,cnt=0;
    rep(i,0,10) strcpy(c[i],buf[i]);
    rep(i,0,10){
        rep(j,0,10){
            if(c[i][j]=='o'){
                cnt++;
                dfs(i,j);
            }
        }
    }
    return cnt==1;
}
int main(){
    int i,j;
    rep(i,0,10)scanf("%s",buf[i]);
    rep(i,0,10){
       rep(j,0,10){
           if(buf[i][j]=='x'){
               buf[i][j]='o';
               if(check()){
                   printf("YES\n");
                   return 0;
               }
               buf[i][j]='x';
           }
       } 
    }
    printf("NO\n");
} ./Main.c: In function ‘main’:
./Main.c:29:16: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     rep(i,0,10)scanf("%s",buf[i]);
                ^