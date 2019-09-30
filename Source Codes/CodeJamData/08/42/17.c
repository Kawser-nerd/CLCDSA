#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define F1(i,n) for(i=1;i<=n;i++)

int main()
{
 int tn,tt,m,n,x1,x2,y2,z;
 long a;
 FILE *fi,*fo;
 fi=fopen("B.in","r");
 fo=fopen("B.out","w");
 fscanf(fi,"%d",&tt);
 F1(tn,tt)
 {
  fscanf(fi,"%d %d %d",&n,&m,&a);
//  printf("%d %d %d\n",n,m,a);
  z=1;
  x1=-1;
  do
  {
   x1++;  
//   printf("x1 %d\n",x1);  
   y2=-1;
   do
   {
    y2++;    
//    printf("y2 %d\n",y2);
    x2=x1-1;
    if(x1==0) x2=0;
    do
    {
     x2++;
 //    sleep(600);
     if ((x1*y2+a)%x2==0)
      if ((x1*y2+a)/x2<=m)
       z=0;     
    }   
    while  ((x2<n) && z);   
   }
   while ((y2<m) && z);    
  }
  while ((x1<n) && z);
  fprintf(fo,"Case #%d: ",tn);
  if (z!=0) fprintf(fo,"IMPOSSIBLE\n");
  else
   fprintf(fo,"%d %d %d %d %d %d\n",0,0,x1,(x1*y2+a)/x2,x2,y2);
 }         
 close(fi);
 close(fo);
 return 0;
}
