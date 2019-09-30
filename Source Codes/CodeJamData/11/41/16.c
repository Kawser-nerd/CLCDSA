#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Walk{
    double b,e,w;
    double len;
}walk[1234];
int cmp(const void* a,const void*b){
    struct Walk c = *(struct Walk*)a;
    struct Walk d = *(struct Walk*)b;
    if(c.w > d.w)return 1;
    if(c.w < d.w)return -1;
    return 0;
}
int main(){
    int i,j,t,Case;
    double x,s,r;
    int n;
    double rT;
    double time,temp;
    scanf(" %d",&Case);
    for(t=1;t<=Case;++t){
        scanf(" %lf %lf %lf %lf %d",&x,&s,&r,&rT,&n);
        for(i=0;i<n;++i){
            scanf(" %lf %lf %lf",&walk[i].b,&walk[i].e,&walk[i].w);
            walk[i].len = walk[i].e - walk[i].b;
            x -= (walk[i].e - walk[i].b);
        }
        qsort(walk,n,sizeof(struct Walk),cmp);
        time = 0;
        if(x >= rT*r){
            time += rT;
            x -= rT*r;
            time += (x)/(s);
            rT = 0;
        }else {
            time += (x)/(r);
            rT -= (x)/(r);
        }
        for(i=0;i<n;++i){
            if(rT > 0.0){
                if(walk[i].len >= (walk[i].w+r)*rT ){
                    time += rT;
                    walk[i].len -= (walk[i].w+r)*rT;
                    time += walk[i].len/(walk[i].w+s);
                    rT = 0;
                }else {
                    time += walk[i].len/(walk[i].w+r);
                    rT -= walk[i].len/(walk[i].w+r);
                }
            }else {
                time += (double)(walk[i].len)/(double)(walk[i].w+s);
            }
        }
        printf("Case #%d: %lf\n",t,time);

    }


    return 0;
}
