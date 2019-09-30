#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int d,g,q,ans=INT_MAX;
long long score,p[12],c[12];
bool qa[12];

int cnt(int a){
    long long tmp=0;
    int count=0;
    do {
        tmp+=100*(a+1);
        count++;
        if (count==p[a]){
            tmp+=c[a];
        }
    } while(score+tmp<g && count<p[a]);
    
    if (score+tmp>=g){
        if (ans>q+count){
            ans=q+count;
        }
    } else {
        qa[a]=true;
        q+=count;
        score+=tmp;
        for (int i=0; i<d; i++){
            if (qa[i]==false){
                cnt(i);
                qa[i]=false;
            }
        }
        score-=tmp;
        q-=count;
    }
    return 0;
}

int main(void){
    scanf("%d%d",&d,&g);
    for (int i=0; i<d; i++){
        scanf("%lld%lld",&p[i],&c[i]);
        qa[i]=false;
    }
    for (int i=0; i<d; i++){
        cnt(i);
        qa[i]=false;
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:44:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&d,&g);
     ^
./Main.c:46:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld%lld",&p[i],&c[i]);
         ^