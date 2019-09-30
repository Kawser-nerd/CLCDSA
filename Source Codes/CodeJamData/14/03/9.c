#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int debug= 0;
int t,T;
int R,C,M;
char map[52][52];
void printMap(){
    int i,j;
    map[1][1] = 'c';
    for(i=1;i<=R;++i){
        for(j=1;j<=C;++j){
            putchar(map[i][j]);
        }
        puts("");
    }
}
void Impossible(){
    puts("Impossible");
    if(debug)printMap();
}
void solve(){
    int i,j;
    int ok=R*C-M;
    memset(map,'.',sizeof(map));

    for(i=1;i<=R;++i){
        for(j=1;j<=C;++j){
            map[i][j] = '*';
        }
    }
    if(R==1){
        for(j=1;j<=C && ok>0;++j,--ok){
            map[1][j] = '.';
        }
        printMap();
    }else if(C==1){
        for(i=1;i<=R &&ok>0;++i,--ok){
            map[i][1] = '.';
        }
        printMap();
    }else if(ok == 0){
        Impossible();
        return ;
    }else if(ok == 1){
        printMap();
    }else {
        for(i=1;i<=R&&ok>0;++i){
            for(j=1;j<=2&&ok>0;++j){
                map[i][j]='.';
                --ok;
            }
        }
        if(ok==0 && j==2){
            if(C>=3 && i>=6){
                --i;
                map[i][1] = '*';
                map[i-1][1] = '*';
                map[i-1][2] = '*';
                for(i=1;i<=3;++i){
                    map[i][3] = '.';
                }
                printMap();
                return ;
            }else{
                Impossible();
                return ;
            }
        }
        j=3;
        while(ok>0 && j<=C){
            if(ok==1){
                if(j==3){
                    if(R>=4){
                        map[R][1] = '*';
                        map[R][2] = '*';
                        ok+=2;
                    }else{
                        Impossible();
                        return ;
                    }
                }else {
                    if(R>=3){
                        map[R][j-1] = '*';
                        ++ok;
                    }else{
                        Impossible();
                        return ;
                    }
                }
            }
            for(i=1;i<=R&&ok>0;++i){
                map[i][j]='.';
                --ok;
            }
            ++j;
        }
        if( (map[1][2]!='*'&&map[2][1]!='*'&&map[2][2]!='*' &&ok==0) || R*C-M==1){
            printMap();
        }else {
            Impossible();
            return ;
        }
    }
}

int main(){
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%d %d %d",&R,&C,&M);
        printf("Case #%d:\n",t);
        if(debug)printf("%d %d %d\n",R,C,M);
        solve();
    }

    return 0;
}
