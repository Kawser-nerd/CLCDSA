#include <stdio.h>
#define MAX 200
#define INF (30*60)

int avail_a[INF], avail_b[INF];
int dep_a[MAX], arr_b[MAX];
int dep_b[MAX], arr_a[MAX];
int n, na, nb, t;
int sola, solb;

int main()
{
    int cs = 0;
    int hr, min;
    int i, j, nxt_t, nxt_s, nxt_p;
    scanf("%d",&n);
    
    while(n--)
    {
     cs++;
     scanf("%d",&t);
     scanf("%d%d",&na,&nb);
     for(i=0; i<na; i++)
     {
      scanf("%02d:%02d",&hr,&min);
      dep_a[i] = hr*60+min;
      scanf("%02d:%02d",&hr,&min);
      arr_b[i] = hr*60+min;
     }
     for(i=0; i<nb; i++)
     {
      scanf("%02d:%02d",&hr,&min);
      dep_b[i] = hr*60+min;
      scanf("%02d:%02d",&hr,&min);
      arr_a[i] = hr*60+min;
     }
     /*for(i=0; i<na; i++)
     printf("%d->%d\n", dep_a[i], arr_b[i]);
     for(i=0; i<nb; i++)
     printf("%d->%d\n", dep_b[i], arr_a[i]);*/
     sola = 0;
     solb = 0;
     for(i=0; i<INF; i++)
     {
      avail_a[i] = avail_b[i] = 0;
     }
     for(i=0; i<(na+nb); i++)
     {
      nxt_t = INF;
      nxt_s = 0;
      nxt_p = 0;
      /* find next train   */
      for(j=0; j<na; j++)
      {
       if(dep_a[j] < nxt_t)
       {
        nxt_t = dep_a[j];
        nxt_s = 0;
        nxt_p = j;
       }
      }
      for(j=0; j<nb; j++)
      {
       if(dep_b[j] < nxt_t)
       {
        nxt_t = dep_b[j];
        nxt_s = 1;
        nxt_p = j;
       }
      }
      /* check if train available */
      for(j=nxt_t; j>=0; j--)
      {
       if(nxt_s == 0)
       {
        if(avail_a[j] > 0)
        {
         avail_a[j]--;
         break;
        }
       }
       else
       {
        if(avail_b[j] > 0)
        {
         avail_b[j]--;
         break;
        }
       }
      }
      if(j<0)
      {
       if(nxt_s == 0)
       sola++;
       else
       solb++;
      }
      /* make it available        */
      if(nxt_s == 0)
      {
       avail_b[arr_b[nxt_p]+t]++;
      }
      else
      {
       avail_a[arr_a[nxt_p]+t]++;
      }
      /* remove train    */
      if(nxt_s == 0)
      {
       dep_a[nxt_p] = INF;
      }
      else
      {
       dep_b[nxt_p] = INF;
      }      
     }
     printf("Case #%d: %d %d\n", cs, sola, solb);
    }
    return 0;
}
