#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int counter;
    counter = 0;
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
        if(a[i]%6 == 2||a[i]%6 == 4){
            counter++;
        }
        else if(a[i]%6 == 5){
            counter += 2;
        }
        else if(a[i]%6 == 0){
            counter += 3;
        }
    }
    printf("%d\n",counter);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",a+i);
         ^