#include <stdio.h>
#include <math.h>
int main(void){
    // Your code here!
    char s[5];
    int n,a,b,x,g=0;
    scanf("%d%d%d",&n,&a,&b);
    for(int i=0;i<n;i++){
        scanf("%s%d",s,&x);
        if (x<a) x=a;
        if (x>b) x=b;
        if (s[0]=='W') x*=(-1);
        g+=x;
    }
    if(g==0)
        printf("0\n");
    else if(g<0)
        printf("West %d\n",g*-1);
    else
        printf("East %d\n",g);
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s%d",s,&x);
         ^