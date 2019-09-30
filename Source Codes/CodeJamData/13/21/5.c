#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
  int a,b,c,d,e,j,k,l;
  int h[110],i[110][110];
  FILE *f,*g;
  f=fopen("a.in","r");
  g=fopen("a.out","w");
  fscanf(f,"%d",&a);
  for(b=1;b<=a;b++)
  {
    fscanf(f,"%d%d",&c,&d);
    memset(i,0,sizeof(int)*110*110);
    i[0][0]=c;
    for(e=1;e<=d;e++)fscanf(f,"%d",&(h[e]));
    for(j=1;j<d;j++)
    for(k=j+1;k<=d;k++)
    if(h[j]>h[k]){e=h[j];h[j]=h[k];h[k]=e;}
    for(e=1;e<=d;e++)
    {
      for(j=0;j<=d;j++)
      if(i[e-1][j]!=0)
      {
        k=i[e-1][j];
        if(h[e]<k)
        {
          k=k+h[e];
          if(i[e][j]<k)i[e][j]=k;
        }
        else{
          if(i[e][j+1]<k)i[e][j+1]=k;
          if(k>1)
          {
            l=0;
            while(k<=h[e]){k=k*2-1;l++;}
            k=k+h[e];
            if(i[e][j+l]<k)i[e][j+l]=k;
          }
        }
      }
    }
    e=0;
    while(i[d][e]==0)e++;
    fprintf(g,"Case #%d: ",b);
    fprintf(g,"%d\n",e);
  }
  fclose(f);
  fclose(g);
  return 0;
}