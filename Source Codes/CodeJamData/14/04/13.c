#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void* elem1, const void* elem2)
{
    if(*(const float*)elem1 < *(const float*)elem2)
        return -1;
    return *(const float*)elem1 > *(const float*)elem2;
}
 
void main()
{
    int i, j, k, m, n, p, q, win1, win2;
    float a[1000], b[1000], c[1000], d[1000];
    scanf("%d", &i);
    for(j=1 ; j<=i ; j++)
    {
     win1 = 0;
     win2 = 0;     
     scanf("%d", &k);
     for(m=0 ; m<k ; m++)
     {
             scanf("%f", &a[m]);
     }
     for(m=0 ; m<k ; m++)
     {
             scanf("%f", &b[m]);
     }
     qsort(a, k, sizeof(float), cmpfunc);
     qsort(b, k, sizeof(float), cmpfunc);
     
     memcpy(c, b, 4*k);
     memcpy(d, a, 4*k);
     p = k;
     {//KNOWN
              for(m=0 ; m<k ; m++)
              {
                      for(n=0 ; n<p ; n++)
                      {
                              if(c[n] == 0)
                                      continue;
                                      
                              if(d[m] < c[n])
                              {
                                      c[p-1] = 0;
                                      p--;
                                      break;
                              }
                              else
                              {
                                  win1++;
                                  for(n=0 ; n<p ; n++)
                                  {
                                          if(c[n] == 0)
                                                  continue;
                                          if(d[m] > c[n])
                                                  q = n;
                                  }
                                  c[q] = 0;
                                  break;
                              }
                      }                    
              }
     }
     {//UNKNOWN
              for(m=0 ; m<k ; m++)
              {
                      for(n=0 ; n<k ; n++)
                      {
                              if(a[m] < b[n])
                              {
                                      win2++;
                                      b[n] = 0;
                                      break;
                              }
                      }
                      if(n == k)
                      {
                           for(n=0 ; n<k ; n++)
                                   if(b[n] != 0)
                                           b[n] = 0;
                      }
                                           
              }
     }
                    
     printf("Case #%d: %d %d\n", j, win1, k-win2);
    }
}
