#include<stdio.h>
#include<string.h>
void foo(int a, int cost);
int c,t,T,m,n,M,N;
char S[1024][128];
int pref[1024][1024];
int foob[1024];
int fooc[128];
int max,number;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&M);
scanf("%d",&N);

for(m=1;m<=M;m++){
scanf("%s",&S[m][0]);
pref[0][m]=strlen(&S[m][0]);
}

for(m=1;m<=M;m++){
for(n=1;n<m;n++){
for(c=0;S[m][c]==S[n][c];c++) {}
/*FIXME: Chekc this*/
pref[m][n]=pref[0][n]-c;
pref[n][m]=pref[0][m]-c;

}
}
/*printf("%d %d %d\n",pref[0][0],pref[0][1],pref[0][2]);
printf("%d %d %d\n",pref[1][0],pref[1][1],pref[1][2]);
printf("%d %d %d\n",pref[2][0],pref[2][1],pref[2][2]);*/

max=0;number=0;
foo(1,0);


 printf("Case #%d: %d %d\n",t,max+N, number);
}
return 0;
}

void foo(int a, int cost){
int p,min_cost;
if (a<=M) {
for(foob[a]=0;foob[a]<N;foob[a]++){
fooc[foob[a]]++;
min_cost=pref[0][a];
 for(p=1;p<a;p++) {
  if (foob[p]==foob[a])
   if (min_cost>pref[p][a]) {min_cost=pref[p][a];}
 }
foo(a+1,cost+min_cost);
fooc[foob[a]]--;
}
}
else{
for(p=0;p<N;p++) {if (fooc[p]==0) return;}
if (cost>max) {max=cost; number=0;}
if (cost==max) {number++;}
}

}

