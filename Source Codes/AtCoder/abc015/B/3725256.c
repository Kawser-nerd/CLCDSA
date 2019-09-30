#include <stdio.h>
#include <math.h>

int main(void)
{
    int N;
    double parameter;
    int bug, bug_sum = 0;
    int i;
    
    scanf("%d%*c", &N);
    parameter = N * 1.0;
    for(i = 0; i < N; i++){
        scanf("%d%*c", &bug);
        if(bug == 0){
            parameter--;
        }else{
            bug_sum += bug;
        }
    }
    
    printf("%d\n", (int)ceil(bug_sum / parameter));
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%*c", &N);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%*c", &bug);
         ^