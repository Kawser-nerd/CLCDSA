#include <stdio.h>
#include <string.h>
#define MAX_LEN   200
#define MAX_S     100
#define MAX_Q     1000
#define INF       2000
char se[MAX_S][MAX_LEN];
char query[MAX_LEN];

int sol[MAX_S][MAX_Q];
int n, s, q;
int computeOptimal(int pos, char *q)
{
    int i, j;
    if(pos == 0)
    {
          for(i=0; i<s; i++)
          {
                   if(!strcmp(q, &se[i][0]))
                   {
                    /* Use any other and switch */
                    sol[i][pos] = 1;
                   }
                   else
                   {
                    sol[i][pos] = 0;
                   }
          } 
          return 0;
    }
    
    for(i=0; i<s; i++)
    {
            if(!strcmp(q, &se[i][0]))
            {
             sol[i][pos] = INF;
             for(j=0; j<s; j++)
             {
              if(j == i)
              {
                  if((sol[j][pos-1]+2)<sol[i][pos])
                  {
                   sol[i][pos] = sol[j][pos-1]+2;
                  }
              }
              else
              {
                  if((sol[j][pos-1]+1)<sol[i][pos])
                  {
                   sol[i][pos] = sol[j][pos-1]+1;
                  }
              }
             }
            }
            else
            {
             /* Previous move is the min    */    
             sol[i][pos] = sol[i][pos-1];
            } 
    }
}
int main()
{
 int i, j, minpos, cs = 0;
 
 scanf("%d",&n);
 while(n--)
 {
  cs++;
  scanf("%d",&s);
  getchar();
  for(i=0; i<s; i++)
  {
   scanf("%[^\n]", &se[i][0]);
   getchar();
  }
  scanf("%d", &q);
  getchar();
  for(i=0; i<q; i++)
  {
   scanf("%[^\n]",query);
   getchar();
   computeOptimal(i, query);
  }
  minpos = 0;
  for(i=0; i<s; i++)
  {
   if(sol[i][q-1] < sol[minpos][q-1])
   minpos = i;
  }
 /* for(i=0; i<s; i++)
  {
  for(j=0; j<q; j++)
  printf("%d ", sol[i][j]);
  printf("\n");
  }*/
  //printf("Case #%d: %d (%d %s)\n", cs, sol[minpos][q-1], minpos, &se[minpos][0]);
  printf("Case #%d: %d\n", cs, sol[minpos][q-1]);
 }
 getchar();
 return 0;
}
