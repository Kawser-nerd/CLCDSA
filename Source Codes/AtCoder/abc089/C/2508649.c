#include <stdio.h>
int main()
{
    int N;
    int i;
    scanf("%d", &N);
    char name[N+1][100];
    for(i=1;i<=N;i++) scanf("%s", &name[i][0]);
    long countM = 0, countA = 0, countR = 0, countC = 0, countH = 0;
    for(i=1;i<=N;i++){
        if(name[i][0] == 'M') countM += 1;
        if(name[i][0] == 'A') countA += 1;
        if(name[i][0] == 'R') countR += 1;
        if(name[i][0] == 'C') countC += 1;
        if(name[i][0] == 'H') countH += 1;
    }
    long result = 0;
    result += (countM*countA*(countR+countC+countH));
    result += (countM*countR*(countC+countH));
    result += (countM*countC*countH);
    result += (countA*countR*(countC+countH));
    result += (countA*countC*countH);
    result += (countR*countC*countH);
    printf("%ld", result);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:8:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=1;i<=N;i++) scanf("%s", &name[i][0]);
                       ^