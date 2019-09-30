#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define INF 0x7FFFFFFF

typedef unsigned char bool;

int vet[1010];


int main()
{
  int T, cont = 0;
  
  scanf("%d\n", &T);
  while(T--)
  {
    int L, t, n, c, cur, sum = INF;
    int i, k, j;
    
    scanf("%d %d %d %d", &L, &t, &n, &c);
    
    for(i = 0; i < c; i++)
    {
      scanf("%d ", &vet[i]);
      vet[i] *= 2;
      for(k = i; k < n; k += c)
        vet[k] = vet[i];
    }
   
    if(L == 0)
    {
      cur = 0;
      for(j = 0; j < n; j++)
        cur += vet[j];
      sum = cur;
    }
    else if(L == 1)
    {
      for(k = 0; k < n; k++)
      {
        cur = 0;
        for(j = 0; j < n; j++)
            if(j == k)
            {
              if(cur < t)
              {
                if(cur+vet[j] < t)
                  cur += vet[j];
                else
                  cur += (t-cur) + ((cur+vet[j])-t)/2;
              }
              else
              {
                cur += vet[j]/2;
              }
            }
            else
            {
              cur += vet[j];
            }
              
          if(sum > cur)
            sum = cur;
      }
    }
    else
    {
      int lim;
      cur = 0;
      for(j = 0, i = n+1; j < n; j++)
      {
        if(cur >= t)
        {
          i = j;
          lim = i;
          break ;
        }
        cur += vet[j];
      }
      
      for(k = 0; k < n; k++)
      {
        cur = 0;
        for(j = 0; j < n; j++)
            if(j == k || j == i)
            {
              if(cur < t)
              {
                if(cur+vet[j] < t)
                  cur += vet[j];
                else
                  cur += (t-cur) + ((cur+vet[j])-t)/2;
              }
              else
              {
                cur += vet[j]/2;
              }
            }
            else
            {
              cur += vet[j];
            }
              
          if(sum > cur)
            sum = cur;
      }
      
      for(j = lim+2, i = lim+1; j < n; j++)
        if(vet[j] > vet[i])
          i = j;
      
      if(i == lim+1)
      {
        for(j = lim+3, k = lim+2; j < n; j++)
          if(vet[j] > vet[k] && j != i)
            k = j;
      }
      else
      {
        for(j = lim+2, k = lim+1; j < n; j++)
          if(vet[j] > vet[k] && j != i)
            k = j;
      }
      
      cur = 0;
      for(j = 0; j < n; j++)
        if(j == k || j == i)
        {
          if(cur < t)
          {
            if(cur+vet[j] < t)
              cur += vet[j];
            else
              cur += (t-cur) + ((cur+vet[j])-t)/2;
          }
          else
          {
            cur += vet[j]/2;
          }
        }
        else
        {
          cur += vet[j];
        }
          
      if(sum > cur)
        sum = cur;
    }
          
    
    printf("Case #%d: %d\n", ++cont, sum);
  }
  
return 0;
}
