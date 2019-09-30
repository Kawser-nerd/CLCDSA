#include<stdio.h>

#define max 2025

int main(){
int a,ans[100][2],i,count=0;
scanf("%d",&a);
for(i=1;i<=9;i++){
if((max-a)%i==0){
ans[count][0]=i;
ans[count][1]=(max-a)/i;
count++;
}
}
for(i=0;i<count;i++){
if(ans[i][1]<=9)printf("%d x %d\n",ans[i][0],ans[i][1]);
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&a);
 ^