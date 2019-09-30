#include<stdio.h>

int main(void){
int a[1000000];

int i,k;
int m=0;
int answer;

scanf("%d",&a[0]);

for(i=1;m<1;i++){
if(a[i-1]%2==0){a[i]=(a[i-1]/2);}
else{a[i]=(3*a[i-1])+1;}
for(k=0;k<i;k++){
if(a[i]==a[k]){answer=i+1;m=1;}
}
}

printf("%d",answer);
return 0;} ./Main.c: In function ‘main’:
./Main.c:10:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&a[0]);
 ^