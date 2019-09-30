#include <stdio.h>
#include <string.h>

int abs(int a){return a>0?a:-a;}

int main(){
    int t,cas;
    int N;
    scanf("%d",&t);
    for (cas=1;cas<=t;cas++){
        scanf("%d",&N);
        int bt=0,ot=0,bp=1,op=1;
        int t = 0;
        char ts[10];
        int pos;
        while (N--){
            scanf("%s%d",ts,&pos);
            if (ts[0]=='O'){
                int nt = ot+abs(pos-op);
                t = ot = (nt>t)?nt:t;
                t++; ot++; op=pos;
            }else{
                int nt = bt+abs(pos-bp);
                t = bt = (nt>t)?nt:t;
                t++; bt++; bp=pos;
            }
        }
        printf("Case #%d: %d\n",cas,t);
    }
    return 0;
}

