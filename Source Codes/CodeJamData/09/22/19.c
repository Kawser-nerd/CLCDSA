#include <stdio.h>
char x[500], aux;
int N, test, n, i, j, gata;

int main()
{
    freopen("a1.in", "rt", stdin);
    freopen("a1.out", "wt", stdout);
    
    scanf("%d", &N);
    
    for (test = 1; test <= N; test++)
    {
        scanf("%s", x);
        n = strlen(x);
        
        printf("Case #%d: ", test);
        gata = 0;
        for (i = n-2; i >= 0 && !gata; i--)
        {
            
            if (x[i] < x[i+1])
            {
                     j = i+1;
                     while (j < n && x[j] > x[i]) j++;
                     j--;
                     
                     aux = x[i];
                     x[i] = x[j];
                     x[j] = aux;
                     
                     for (j = 0; j <= i; j++)
                         printf("%c", x[j]);
                     for (j = n-1; j > i; j--)
                         printf("%c", x[j]);
                     printf("\n");
                     
                     gata = 1;
            }
            }
        if (!gata)
        {
                  i = n-1;
                  while (x[i] == '0') i--; 
                  printf("%c", x[i]);
                  for (j = 1; j <= n-i; j++)
                      printf("0");
                  for (j = i-1; j >= 0; j--)
                      printf("%c", x[j]);
                  printf("\n");
        }
        
    }
}
