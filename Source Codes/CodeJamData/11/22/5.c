#include <stdio.h>
#include <stdlib.h>

struct Node{
    long long int x;
    long long int num;
}node[300];
long long int d,c;
int check(long long int l);
int main(){
    int t,Case;
    int i,j;
    long long int cc;
    long long int l,m,r,OK;
    scanf("%d",&Case);
    for(t=1;t<=Case;++t){
        scanf("%I64d %I64d",&c,&d);
        d = d<<1;
        for(i=0;i<c;++i){
            scanf("%I64d %I64d",&node[i].x ,&node[i].num);
            node[i].x *= 2;
        }
        l = 0,r = OK = 1000000000000LL;
        while(l<=r){
            m = (l+r)/2;
            cc = check(m);
            if(cc){
                l = m+1;
              //  puts(" NotOK");
            }else {
                if(OK > m)OK = m;
                r = m-1;
               // puts(" OK");
            }

        }
        printf("Case #%d: %.1lf\n",t,(double)(OK)/2);
    }
    return 0;
}
int check(long long int l){
    //printf("%.1lf %d:",(double)(l)/2,d/2);
    int i,j;
    long long int left = node[0].x - l + d;
    //printf(" %.1lf",(double)(left-d)/2);
    for(i=1;i<node[0].num;++i){
        if(node[0].x - l >left){
            left = node[0].x - l + d;
        }else if(node[0].x - l <= left){
            if(left - node[0].x > l)return 1;
            left = left + d;
        }else {
            return 1;
        }
      //  printf(" (%d,%.1lf)",node[0].x/2,(double)(left-d)/2);
    }
    for(i=1;i<c;++i){
        for(j=0;j<node[i].num;++j){
             if(node[i].x - l >left){
                left = node[i].x - l + d;
            }else if(node[i].x - l <= left){
                if(left - node[i].x > l)return 1;
                left = left + d;
            }else {
                return 1;
            }
        //    printf(" (%d,%.1lf)",node[i].x/2,(double)(left-d)/2);
        }
    }
    return 0;
}
