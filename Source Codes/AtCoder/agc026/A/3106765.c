#include <stdio.h>

int main(){
    int a[2],n,x,z = 0,an = 0;
    scanf("%d %d",&n,&a[0]);

    for(x=1;x<n;x++){
        scanf("%d",&a[1]);
        if(a[0] == a[1] && z == 0){
            an++;
            z++;
            a[0] = a[1];
            continue;
        }
        a[0] = a[1];
        z = 0;
    }

    printf("%d\n",an);


} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&a[0]);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[1]);
         ^