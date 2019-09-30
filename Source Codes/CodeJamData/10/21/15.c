#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef unsigned char bool;

char exist[220][110], newd[110][110];

/*void stupidSort(int size)
{
   int i, k;
   char temp[110]
   
   for(i = 0; i < n; i++)
      for(k = i+1; k < n; k++)
         if(strcmp(newd[i], newd[k]) > 0)
         {
            strcpy(temp, newd[i]);
            strcpy(newd[i], newd[k]);
            strcpy(newd[k], temp);
         }
}*/

int main()
{
   int T, cont = 0;
   char temp[1000];
   
   gets(temp);
   T = atoi(temp);
   while(T--)
   {
      int n, m, mkdir = 0;
      int i, k, j;
      
      gets(temp);
      sscanf(temp, "%d %d", &n, &m);
      
      for(i = 0; i < n; i++)
      {
         gets(exist[i]);
         strcat(exist[i], "/");
      }
         
      for(i = 0; i < m; i++)
      {
         gets(newd[i]);
         strcat(newd[i], "/");
      }
   
      /*stupidSort(m);*/
      
      for(i = 0; i < m; i++)
      {
         int min = 0, constmin, size = strlen(newd[i]);
         for(j = 1; j < size; j++)
            min += (newd[i][j] != '/') ? 0 : 1;
         constmin = min;
         
         for(k = 0; k < n; k++)
         {
            int m = constmin;
            for(j = 1; j < size && newd[i][j] == exist[k][j]; j++)
               if(newd[i][j] == exist[k][j] && newd[i][j] == '/')
                  m--;
            if(m < min)
               min = m;
         }
         
         mkdir += min;
         strcpy(exist[n++], newd[i]);
      }
      
      printf("Case #%d: %d\n", ++cont, mkdir);
   }
   
return 0;
}
