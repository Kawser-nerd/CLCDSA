#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main()
{
  int a,b,c,d,e,k,l,m,o;
  uint64_t n;
  int h[1010][3],i[1010][2],j[1010][2];
  FILE *f,*g;
  f=fopen("a.in","r");
  g=fopen("a.out","w");
  fscanf(f,"%d",&a);
  for(b=1;b<=a;b++)
  {
    fscanf(f,"%d%d",&c,&d);
    n=0;
    for(e=0;e<d;e++)
    {
      fscanf(f,"%d%d%d",&h[e][0],&h[e][1],&h[e][2]);
      l=h[e][1]-h[e][0];
      if(l>0)
      {
        if(l%2==0)n=(n+(((((2*c+1-l)%1000002013)*(l/2))%1000002013)*h[e][2])%1000002013)%1000002013;
        else n=(n+((((((2*c+1-l)/2)%1000002013)*(l))%1000002013)*h[e][2])%1000002013)%1000002013;
      }
      k=e;
      while((k>0)&&(h[k][0]<h[k-1][0]))
      {
        o=h[k][0];h[k][0]=h[k-1][0];h[k-1][0]=o;
        o=h[k][1];h[k][1]=h[k-1][1];h[k-1][1]=o;
        o=h[k][2];h[k][2]=h[k-1][2];h[k-1][2]=o;
        k--;
      }
    }
printf("%d : %d\n",b,n);
    n=(1000002013-n)%1000002013;
    e=0;
    k=0;
    l=0;
    while(e<d)
    {
      while((k>0)&&(i[k][0]<h[e][0]))
      {
        m=i[k][1];
        while(m>0)
        {
          if(j[l][1]>m)
          {
            j[l][1]=j[l][1]-m;
            o=i[k][0]-j[l][0];
            if(o>0)
            {
              if(o%2==0)n=(n+(((((2*c+1-o)%1000002013)*(o/2))%1000002013)*m)%1000002013)%1000002013;
              else n=(n+((((((2*c+1-o)/2)%1000002013)*(o))%1000002013)*m)%1000002013)%1000002013;
            }
            m=0;
          }
          else{
            m=m-j[l][1];
            o=i[k][0]-j[l][0];
            if(o>0)
            {
              if(o%2==0)n=(n+(((((2*c+1-o)%1000002013)*(o/2))%1000002013)*j[l][1])%1000002013)%1000002013;
              else n=(n+((((((2*c+1-o)/2)%1000002013)*(o))%1000002013)*j[l][1])%1000002013)%1000002013;
            }
            l--;
          }
printf("A %d\n",1000002013-n);
        }
        k--;
      }
      k++;
      i[k][0]=h[e][1];
      i[k][1]=h[e][2];
      m=k;
      while((k>1)&&(i[k][0]>i[k-1][0]))
      {
        o=i[k][0];i[k][0]=i[k-1][0];i[k-1][0]=o;
        o=i[k][1];i[k][1]=i[k-1][1];i[k-1][1]=o;
        k--;
      }
      k=m;
      l++;
      j[l][0]=h[e][0];
      j[l][1]=h[e][2];
      e++;
    }
printf("mid : %d\n",1000002013-n);
      while(k>0)
      {
        m=i[k][1];
        while(m>0)
        {
//printf("ml  %d %d %d %d\n",m,l,j[l][1],j[l][0]);
          if(j[l][1]>m)
          {
            j[l][1]=j[l][1]-m;
            o=i[k][0]-j[l][0];
            if(o>0)
            {
              if(o%2==0)n=(n+(((((2*c+1-o)%1000002013)*(o/2))%1000002013)*m)%1000002013)%1000002013;
              else n=(n+((((((2*c+1-o)/2)%1000002013)*(o))%1000002013)*m)%1000002013)%1000002013;
            }
            m=0;
          }
          else{
            m=m-j[l][1];
            o=i[k][0]-j[l][0];
            if(o>0)
            {
              if(o%2==0)n=(n+(((((2*c+1-o)%1000002013)*(o/2))%1000002013)*j[l][1])%1000002013)%1000002013;
              else n=(n+((((((2*c+1-o)/2)%1000002013)*(o))%1000002013)*j[l][1])%1000002013)%1000002013;
            }
            l--;
          }
printf("B %d\n",1000002013-n);
        }
        k--;
      }
    n=(1000002013-n)%1000002013;
    fprintf(g,"Case #%d: ",b);
    fprintf(g,"%d\n",n);
  }
  fclose(f);
  fclose(g);
  return 0;
}