#include<stdio.h>

long sijo(int a){
int r=1,i;
for(i=0;i<4;i++)r*=a;
return r;
}

int main(){
long n;
int i;scanf("%ld",&n);
for(i=0;i<=n;i++){
if(sijo(i)==n){
printf("%d\n",i);
break;
}
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 int i;scanf("%ld",&n);
       ^