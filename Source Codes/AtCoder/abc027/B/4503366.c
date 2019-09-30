#include <stdio.h>
int main(void){
    // Your code here!
    int n,s[100],g=0,t=0,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
        g += s[i];
    }
    if(g%n!=0) printf("-1\n");
    else{
        for(int i=0;i<n;i++){
            t += s[i]-g/n;
            if(t!=0) cnt+=1;
        }
        printf("%d\n",cnt);
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&s[i]);
         ^