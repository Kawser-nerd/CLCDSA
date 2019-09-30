#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define ll long long

int main(void){
int N;
scanf("%d",&N);
int *a=(int*)malloc(sizeof(int)*N);
int i;
for(i=0;i<N;i++) scanf("%d",&a[i]);
int max=0;
for(i=0;i<N;i++)
if(max<a[i]) max=a[i];

for(i=0;i<N;i++)
if(a[i]!=max&&a[i]!=max-1) {printf("No\n");
return 0;
}

int count=0;
for(i=0;i<N;i++)
 if(a[i]!=max) count++;

if(count==0&&max+1==N){
printf("Yes\n");
return 0;
}

if((N-count)>=2*(max-count)&&(max-count)>0){
printf("Yes\n");
return 0;
}

printf("No\n");
return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&N);
 ^
./Main.c:13:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 for(i=0;i<N;i++) scanf("%d",&a[i]);
                  ^