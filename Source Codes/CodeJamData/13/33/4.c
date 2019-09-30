#include<stdio.h>
#define MAX 16
#define OFFSET 1024
int T,t,N;
long long d[MAX], n[MAX], w[MAX], e[MAX], s[MAX], delta_d[MAX], delta_p[MAX], delta_s[MAX];
long long wall[OFFSET*2];
int a,i;
long long attack_day;
int successful_attacks;

int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&N);

for(i=0;i<N;i++){
scanf("%lld",&d[i]);
scanf("%lld",&n[i]);
scanf("%lld",&w[i]);
scanf("%lld",&e[i]);
scanf("%lld",&s[i]);
scanf("%lld",&delta_d[i]);
scanf("%lld",&delta_p[i]);
scanf("%lld",&delta_s[i]);
}

for(i=0;i<OFFSET*2;i++) wall[i]=0;
successful_attacks=0;

while(1){
/*Find attack day*/
attack_day=6760601;
for(i=0;i<N;i++) if ((n[i]>0)&&(d[i]<attack_day)) attack_day=d[i];
if (attack_day==6760601) break;

/*Do attacks*/
for(i=0;i<N;i++) if ((n[i]>0)&&(d[i] == attack_day)) {
for(a=w[i];a<e[i];a++) {
if (wall[a+OFFSET]<s[i]) {successful_attacks++; break;}
}
}

/*Rebuild wall*/
for(i=0;i<N;i++) if ((n[i]>0)&&(d[i] == attack_day)) {
for(a=w[i];a<e[i];a++) {
if (wall[a+OFFSET]<s[i]) {wall[a+OFFSET]=s[i];}
}
/*Update variables*/
s[i]+=delta_s[i];
e[i]+=delta_p[i];
w[i]+=delta_p[i];
d[i]+=delta_d[i];
n[i]--;
}
}

printf("Case #%d: %d\n",t, successful_attacks);

}

return 0;
}


