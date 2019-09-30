#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int t;
int n,w,l;
int r[12345];
double x[12345];
double y[12345];
int X,Y;
double dis;
double DIS(double x,double y,double a,double b){
    return sqrt((x-a)*(x-a) + (y-b)*(y-b));
}
int W,L;
int main(){
    int t,Case = 0;
    int i,j;
    int ok;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&w,&l);
        for(i=0;i<n;++i){
            scanf("%d",&r[i]);
        }
        ok = 0;
        W = w*100;
        L = l*100;
        while(ok==0){
            for(i=0;i<n;++i){
                x[i] = (double)( (rand()%100000) * (rand()%100000) %W)/100;
                y[i] = (double)( (rand()%100000) * (rand()%100000) %L)/100;
            }
            for(i=0,ok=1;i<n&&ok;++i){
                for(j=i+1;j<n&&ok;++j){
                    dis = (int)(DIS(x[i],y[i],x[j],y[j]))+1;
                    if(dis < r[i]+r[j])ok=0;
                }
            }
        }

        printf("Case #%d:",++Case);
        for(i=0;i<n;++i){
            printf(" %.2lf %.2lf",x[i],y[i]);
        }
        puts("");
    }
    return 0;
}
