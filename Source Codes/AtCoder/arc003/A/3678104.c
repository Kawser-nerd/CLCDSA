#include <stdio.h>

int main()
{
    int N, i;
    long double gpa, sum = 0.00000000000000000000000000000000000;

    scanf("%d", &N);

    char r[N + 1]; 

    scanf("%s", r); 
//  r[N] = '\0';
    
    for (i = 0; i < N; i++) {
        if (r[i] == 'A') {
            sum += 4.0000000000000000000000000000000000000;
        } else if (r[i] == 'B') {
            sum += 3.0000000000000000000000000000000000000;
        } else if (r[i] == 'C') {
            sum += 2.0000000000000000000000000000000000000;
        } else if (r[i] == 'D') {
            sum += 1.0000000000000000000000000000000000000;
        }
    }   

    gpa = sum /(long double)N;

    printf("%12.10Lf\n", gpa);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", r); 
     ^