#include<stdio.h>

int main(){
char s[101];
scanf("%s",s);
int n,lr[100][2],i;
scanf("%d",&n);
for(i=0;i<n;i++)scanf("%d%d",&lr[i][0],&lr[i][1]);
for(i=0;i<n;i++){
int j;
for(j=0;j<=(lr[i][1]-lr[i][0])/2;j++){
char tmp=s[j+lr[i][0]-1];
s[j+lr[i][0]-1]=s[lr[i][1]-j-1];
s[lr[i][1]-j-1]=tmp;
}
//printf("%d:%s\n",i,s);
}
printf("%s\n",s);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s",s);
 ^
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&n);
 ^
./Main.c:8:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 for(i=0;i<n;i++)scanf("%d%d",&lr[i][0],&lr[i][1]);
                 ^