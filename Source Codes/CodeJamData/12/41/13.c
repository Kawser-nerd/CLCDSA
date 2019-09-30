#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX(x,y)(((x)>(y))?(x):(y))
#define MIN(x,y)(((x)<(y))?(x):(y))
int n;
struct V{
    int d,l;
    int c;
}v[10001];
int d;

int main(){
    int t,Case = 0;
    int i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;++i){
            scanf(" %d %d",&v[i].d,&v[i].l);
            v[i].c = 0;
        }
        scanf("%d",&d);
        v[0].c = v[0].d;
        for(i=1;i<n;++i){
            for(j=0;j<i;++j){
                if(v[j].d +v[j].c >=v[i].d && MIN(v[i].d-v[j].d,v[i].l) > v[i].c){
                    v[i].c = MIN(v[i].d-v[j].d,v[i].l);
                }
            }
        }
        for(i=0;i<n;++i){
            //printf("%d %d %d\n",i,v[i].d,v[i].c);
            if(v[i].d + v[i].c >= d)break;
        }
        printf("Case #%d: ",++Case);
        if(i<n)puts("YES");
        else puts("NO");

    }
    return 0;
}
