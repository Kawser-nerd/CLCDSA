#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MOD 1000000007LL
int t,T,n,N;
long long frac[128];
long long C;
char s[128][128];
long long ans;
char start[128];/*First Letter*/
char end[128];/*Last Letter*/
char blocked[256]; /*Internal characters*/
int first;
int tmp;
int c;
int only_start[256];
int only_end[256];
int loops[256];
int done[256];
int num_frag;
char tmp2;
char tmp3;

int main(){
scanf("%d",&T);

frac[0]=1;
for(C=1;C<120;C++) frac[C]=(frac[C-1]*C)%MOD;

for(t=1;t<=T;t++){
scanf("%d",&N);
for(n=1;n<=N;n++){scanf("%s",&s[n][0]);}

for(c=0;c<256;c++) {
 blocked[c]=0;
 only_start[c]=0;
 only_end[c]=0;
 loops[c]=0;
}
ans=1;
for(n=1;n<=N;n++) {
 tmp=strlen(s[n]);
 first=1;
 start[n]=s[n][0];
 end[n]=s[n][tmp-1];
 for(c=1;c<tmp;c++) {
  if (s[n][c]!=s[n][c-1]) {
   if (blocked[s[n][c]]==1) ans=0;
   if (first==0) {
    blocked[s[n][c-1]]=1;
    }
   first=0;
  }
 }
 if ((start[n]==end[n])&&(first==0)) ans=0;
}

if (ans==1) {
for(n=1;n<=N;n++) {
if (blocked[start[n]]==1) ans=0;
if (blocked[end[n]]==1) ans=0;
}
}

if (ans==1) {
for(n=1;n<=N;n++) {
if (start[n]==end[n]) {loops[start[n]]++;}
else {
only_start[start[n]]++;
only_end[end[n]]++;
}
}

for(tmp2='a';tmp2<='z';tmp2++){
if (only_start[tmp2]>1) ans=0;
if (only_end[tmp2]>1) ans=0;
}
}

if (ans==1) {
num_frag=0;
for(tmp2='a';tmp2<='z';tmp2++){
if ((only_start[tmp2]==1)&&(only_end[tmp2]==0)) num_frag++;
if ((only_start[tmp2]==0)&&(only_end[tmp2]==0)&&(loops[tmp2]>0)) num_frag++;
ans*=frac[loops[tmp2]];
ans%=MOD;
}
ans*=frac[num_frag];
ans%=MOD;
}

/*Detect cycles*/
if (ans!=0) {

for(c=0;c<256;c++) done[c]=0;

for(tmp2='a';tmp2<='z';tmp2++){
if ((only_start[tmp2]==1)&&(only_end[tmp2]==0)) {
  tmp3=tmp2;
 do{
  for(n=1;n<=N;n++) {
  if ((start[n]==tmp3)&&(start[n]!=end[n])) break;
  }
  done[n]=1;
  tmp3=end[n];
 } while (only_start[tmp3]==1);
}
}

for(n=1;n<=N;n++) {
if ((done[n]==0)&&(start[n]!=end[n])) ans=0;
}
}

printf("Case #%d: ",t);
printf("%lld\n",ans);
}
return 0;
}
