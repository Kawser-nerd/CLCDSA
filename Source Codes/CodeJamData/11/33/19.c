#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef unsigned char bool;

int vet[110];


int main()
{
  int T, cont = 0;
  
  scanf("%d\n", &T);
  while(T--)
  {
    int n, min, max, val;
    int i, k;
    bool possible = false;

    scanf("%d %d %d\n", &n, &min, &max);
    
    for(i = 0; i < n; i++)
      scanf("%d ", &vet[i]);
    
    for(i = min; i <= max; i++)
    {
      bool cur = true;
      for(k = 0; k < n; k++)
        if(i%vet[k] != 0 && vet[k]%i != 0)
        {
          cur = false;
          break ;
        }

      if(cur == true)
      {
        possible = true;
        val = i;
        break ;
      }
    }
    
    if(possible == true)
      printf("Case #%d: %d\n", ++cont, val);
    else
      printf("Case #%d: NO\n", ++cont);
  }
  
return 0;
}
