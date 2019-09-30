#include <stdio.h>

int N,A,B,C;
int l[10];
int ans=114514;

int max(int a,int b){
if(a>b){return a;}
else{return b;}
}

void dfs(int pos,int box1,int box2,int box3,int add){
if(pos>=N){
if(box1!=0&&box2!=0&&box3!=0){
int mp=max(A-box1,box1-A)+max(B-box2,box2-B)+max(C-box3,box3-C)+add;
if(ans>mp){ans=mp;}
}
return;
}

if(box1==0){
dfs(pos+1,box1+l[pos],box2,box3,add);
}
else{
dfs(pos+1,box1+l[pos],box2,box3,add+10);
}
if(box2==0){
dfs(pos+1,box1,box2+l[pos],box3,add);
}
else{
dfs(pos+1,box1,box2+l[pos],box3,add+10);
}
if(box3==0){
dfs(pos+1,box1,box2,box3+l[pos],add);
}
else{
dfs(pos+1,box1,box2,box3+l[pos],add+10);
}
dfs(pos+1,box1,box2,box3,add);

}

int main(){

scanf("%d %d %d %d",&N,&A,&B,&C);

int i;

for(i=0;i<N;i++){
scanf("%d",&l[i]);
}

dfs(0,0,0,0,0);

printf("%d\n",ans);

return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d %d %d",&N,&A,&B,&C);
 ^
./Main.c:50:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&l[i]);
 ^