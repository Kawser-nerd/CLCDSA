#include <stdio.h>
int LCM(int a,int b){
    int lcm=0;
    while(1){
        lcm+=a;
        if(lcm%b==0) break;
    }
    return lcm;
}
int main(void){
    int a,b,c,v=0,i;
    scanf("%d%d%d",&a,&b,&c);
    v=a;
    for(i=0;i<LCM(a,b);i++){
        if(v%b==c){
            printf("YES\n");
            return 0;
        }
        v+=a;
    }
    printf("NO\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^