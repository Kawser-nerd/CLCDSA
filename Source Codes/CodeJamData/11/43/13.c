#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int p[12345];
int pNum;
int np[12345]={0,0,1};
struct Nan{
    int p[1111];
}node[1234],now;
int n;
int main(){
    int t,i,j,Case;

    int temp,key;
    int minTime,maxTime;
    for(i=4;i<1234;i+=2) np[i] = 1;
    for(i=9;i<1234;i+=6) np[i] = 1;
    for(i=6;i<50;i+=6){
        if(!np[i-1]){
            for(j=(i-1)*(i-1);j<1234;j+=(i-1)+(i-1)){
                np[j] = 1;
            }
        }
        if(!np[i+1]){
            for(j=(i+1)*(i+1);j<1234;j+=(i+1)+(i+1)){
                np[j] = 1;
            }
        }
    }
    p[0] = 2;
    pNum =1;
    for(i=3;i<1234;++i){
        if(!np[i])p[pNum++] = i;
    }
    memset(node,0,sizeof(node));
    for(i=2;i<1001;++i){
        temp = i;
        for(j=0;j<pNum && temp > 1;++j){
            while(temp%p[j] == 0){
                temp/=p[j];
                node[i].p[j]++;
            }
        }
    }
    scanf("%d",&Case);
    for(t=1;t<=Case;++t){
        scanf("%d",&n);
        minTime = 1;
        for(i=0;i<pNum;++i){
            now.p[i] = 0;
        }
        for(i=2;i<=n;++i){
            key = 0;
            for(j=0;j<pNum;++j){
                if(node[i].p[j] > now.p[j]){
                    key = 1;
                    now.p[j] = node[i].p[j];
                }
            }
            minTime += key;
        }
        for(i=0;i<pNum;++i){
            now.p[i] = node[n].p[i];
        }
        maxTime = 1;
        for(i=n-1;i>1;--i){
            for(j=0;j<pNum;++j){
                if(node[i].p[j] > now.p[j]){
                    now.p[j] = node[i].p[j];
                }
            }
        }
        maxTime = 0;
        for(i=0;i<pNum;++i){
            if(now.p[i] > 0)maxTime++;
        }
        if(maxTime ==0)maxTime = 1;
        printf("Case #%d: %d\n",t,minTime-maxTime);

    }
    return 0;
}
