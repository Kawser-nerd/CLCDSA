#include<stdio.h>
int t,T,X;
int R,C,r,c,r1,c1;
char grid[128][128];
int ans;
int imp=0;
int imp2=0;
int ok;
int main(){
scanf("%d",&T);

for(t=1;t<=T;t++){
scanf("%d",&R);
scanf("%d",&C);
for(r=0;r<R;r++){
scanf("%s",grid[r]);
}
ans=0;
imp=0;

for(r=0;r<R;r++){
for(c=0;c<C;c++){
imp2=1;
ok=0;
if (grid[r][c]=='.') continue;
if (grid[r][c]=='^') {for (r1=0;r1 < r;r1++)   {if (grid[r1][c]!='.') {ok=1; break;}}}
if (grid[r][c]=='v') {for (r1=r+1;r1 < R;r1++) {if (grid[r1][c]!='.') {ok=1; break;}}}
if (grid[r][c]=='<') {for (c1=0;c1 < c;c1++)   {if (grid[r][c1]!='.') {ok=1; break;}}}
if (grid[r][c]=='>') {for (c1=c+1;c1 < C;c1++) {if (grid[r][c1]!='.') {ok=1; break;}}}
if (ok==1) continue;
ans++;

for (r1=0;r1 < R;r1++){
if (r1==r) continue;
if (grid[r1][c]!='.') {imp2=0; break;}
}

for (c1=0;c1 < C;c1++){
if (c1==c) continue;
if (grid[r][c1]!='.') {imp2=0; break;}
}

if (imp2==1) imp=1;
}
}

if (imp==0) {printf("Case #%d: %d\n",t,ans);}
else {printf("Case #%d: IMPOSSIBLE\n",t);}
}
return 0;
}
