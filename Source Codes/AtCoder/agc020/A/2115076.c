#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, pos_of_Alice, pos_of_Borys;
    scanf("%d%d%d", &N, &pos_of_Alice, &pos_of_Borys);
    
    if (N < 2 || 100 < N){
        fprintf(stderr, "Error: 2 <= N <= 100)\n");
        exit(1);
    }
    if (pos_of_Alice < 1 || N < pos_of_Borys || pos_of_Alice >= pos_of_Borys){
        fprintf(stderr, "Error: 1 <= A < B <= N\n");
        exit(2);
    }
    
    if ((pos_of_Alice - pos_of_Borys) % 2 == 0){
        printf("Alice\n");
    }else {
        printf("Borys\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &N, &pos_of_Alice, &pos_of_Borys);
     ^