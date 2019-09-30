#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x,y;
int main(){
    int t,T;
    int i;
    int f;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%d %d",&x,&y);
        printf("Case #%d: ",t);
        f = 0;
        if(x>0){
            for(i=0;i<x;++i){
                if(!f)printf("E");
                else printf("WE");
                f = 1;
            }
        }else if(x<0){
            for(i=0;i>x;--i){
                if(!f)printf("W");
                else printf("EW");
                f = 1;
            }
        }
        if(y>0){
            for(i=0;i<y;++i){
                if(!f)printf("N");
                else printf("SN");
                f = 1;
            }
        }else if(y<0){
            for(i=0;i>y;--i){
                if(!f)printf("S");
                else printf("NS");
                f = 1;
            }
        }
        puts("");
    }
    return 0;
}
