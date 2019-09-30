#include<stdio.h>
int main()
{
    char day[50];
    scanf("%s", day);
    int ans;
    if (day[0] == 'S')ans = 0;
    else if (day[0] == 'M')ans = 5;
    else if (day[0] == 'W')ans = 3;
    else if (day[0] == 'F')ans = 1;
    else if (day[1] == 'u')ans = 4;
    else ans = 2;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", day);
     ^