#include<stdio.h>

int main(){
int n,a[100],i,sum=0,ans=0;scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&a[i]);
sum+=a[i];
}
if(sum%n!=0){
ans=-1;
}else{
int tmp=0;
for(i=0;i<n;i++){
tmp+=sum/n-a[i];
if(tmp!=0)ans++;
}
if(tmp!=0)ans++;
}
printf("%d\n",ans);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int n,a[100],i,sum=0,ans=0;scanf("%d",&n);
                            ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&a[i]);
 ^