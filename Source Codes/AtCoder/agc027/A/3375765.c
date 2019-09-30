#include <stdio.h>
#include <string.h>

int main()
{
    int num;
    int yen;
    
    int data[100];
    int i,j,k;
    int tmp;
    int cnt = 0;
    
    scanf("%d %d", &num, &yen);
    
    for(i=0; i<num; i++){
        scanf("%d", &data[i]);
    }
    
    for(i=0; i<num; i++){
        for(j=num-1; j>i; j--){
            if(data[j] < data[j-1]){
                tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
            }
        }
    }
    
    for(i=0; i<num; i++){
        if(yen < data[i]){
            break;
        }
        
        if(i==num-1){
            if(yen != data[i]){
                break;
            }
        }
        
        yen -= data[i];
        cnt++;
    }
    
    printf("%d\n", cnt);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &num, &yen);
     ^
./Main.c:17:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &data[i]);
         ^