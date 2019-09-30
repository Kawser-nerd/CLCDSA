#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int r,n,m,k;
int v[12345];
int p[12];
int ans[3];
int A,B,C;
int check(){
    int i;
    int a,b,c;
    int win;
    int tmp;
    for(i=0;i<k;++i){
        win = 0;
        for(a=0;a<2&&!win;++a){
            for(b=0;b<2&&!win;++b){
                for(c=0;c<2&&!win;++c){
                    tmp = 1;
                    if(!a)tmp *=ans[0];
                    if(!b)tmp *=ans[1];
                    if(!c)tmp *=ans[2];
                    if(tmp==v[i])win=1;
                }
            }
        }
        if(!win)return 0;
    }
    return 1;
}

int main(){
    int T,t;
    int i,j;
    int win;
    scanf("%d",&T);
    printf("Case #1:\n");
    scanf("%d %d %d %d",&r,&n,&m,&k);
    while(r--){
        for(i=0;i<k;++i){
            scanf("%d",&v[i]);
        }
        win = 0;
        for(ans[0]=2; ans[0]<=m && !win ;ans[0]++){
            for(ans[1]=2 ; ans[1]<=m && !win ;ans[1]++){
                for(ans[2]=2 ;ans[2]<=m&&!win;ans[2]++){
                    if(check()){
                        win=1;
                        printf("%d%d%d\n",ans[0],ans[1],ans[2]);
                    }
                }
            }
        }
        if(!win)printf("222\n");

    }


    return 0;
}

