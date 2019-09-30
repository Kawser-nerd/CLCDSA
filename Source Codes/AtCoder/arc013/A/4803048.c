#include <stdio.h>
int main(void){
    int n,m,l,p,q,r,s[6],i,max=0;
    scanf("%d%d%d%d%d%d",&n,&m,&l,&p,&q,&r);
    s[0]=(n/p)*(m/q)*(l/r);
    s[1]=(n/p)*(m/r)*(l/q);
    s[2]=(n/q)*(m/p)*(l/r);
    s[3]=(n/q)*(m/r)*(l/p);
    s[4]=(n/r)*(m/p)*(l/q);
    s[5]=(n/r)*(m/q)*(l/p);
    for(i=0;i<6;i++){
        if(s[i]>max) max=s[i];
    }
    printf("%d\n",max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d%d%d",&n,&m,&l,&p,&q,&r);
     ^