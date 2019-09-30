#include <stdio.h>
#include <stdlib.h>

#define SIZE 200010

int main(){
    int i,j,k;
    char array[SIZE];
    long long sum=0;

    scanf("%s",array);

    j = 0;
    for(i=0;array[i]!='\0';i++){
        if(array[i]=='W'){
            sum += (i-j);
            j++;
        }
    }
    
    printf("%lld",sum);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",array);
     ^