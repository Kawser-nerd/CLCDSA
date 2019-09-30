#include<stdio.h>

int main(){
int a,b,c,d,e,ans[10];
scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
ans[0]=a+b+c;
ans[1]=a+b+d;
ans[2]=a+b+e;
ans[3]=a+c+d;
ans[4]=a+c+e;
ans[5]=a+d+e;
ans[6]=b+c+d;
ans[7]=b+c+e;
ans[8]=b+d+e;
ans[9]=c+d+e;
int i,j;
for(i=0;i<10;i++){
for(j=0;j<i;j++){
if(ans[i]>ans[j]){
int tmp=ans[i];
ans[i]=ans[j];
ans[j]=tmp;
}
}
}
int tmp=ans[0],count=0;
for(i=1;i<10;i++){
if(tmp!=ans[i]){
tmp=ans[i];
count++;
}
if(count==2){
printf("%d\n",tmp);
return 0;
}
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
 ^