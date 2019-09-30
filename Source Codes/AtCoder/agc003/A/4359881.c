#include<stdio.h>
#include<string.h>
int main()
{
    char s[1003];
    scanf("%s", s);
    int i;
    int N, W, S, E;
    N = W = S = E = 0;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'N')N++;
        else if (s[i] == 'W')W++;
        else if (s[i] == 'S')S++;
        else E++;
    }
    if ((N > 0 && S == 0) || (N == 0 && S > 0))
        printf("No\n");
    else if ((W > 0 && E == 0) || (W == 0 && E > 0))
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^