#include <stdio.h>
#include <stdlib.h>

int main()
{
     int tcasenum;
     
     int tcaseloop;
     
     int i,j;
     long long A,B,K,hasil;
     
     
     FILE *fin,*fout;
  fin=fopen("data.in","r");
  fout=fopen("data.out","w");

  fscanf(fin,"%d",&tcasenum);
  
  for(tcaseloop=0;tcaseloop<tcasenum;tcaseloop++)
  {
     fscanf(fin,"%lld %lld %lld",&A,&B,&K);
     hasil=A*B;
     for (i=K;i<A;i++)
     for (j=K;j<B;j++)
     if ((i&j)>=K) hasil--;
     fprintf(fout,"Case #%d: %lld\n",tcaseloop+1,hasil);                   
  }

  
  
  fclose(fin);
  fclose(fout);
   
  return 0;
}
