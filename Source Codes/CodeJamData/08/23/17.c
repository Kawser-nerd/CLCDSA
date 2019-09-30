#include <stdio.h>

int main()
{
 FILE *f,*f1;
 int N,za;
 unsigned long *a,k,i,j,z,n;
 f=fopen("Mousetrap.in","r");
 f1=fopen("Mousetrap.out","w");
 fscanf(f,"%d",&N);
 a=malloc(4*1000001);
 for (za=1;za<=N;za++)
 {
  fscanf(f,"%ld",&k);
  
  for (i=1;i<=k;i++)
   a[i]=0x200000;
  z=0; 
  for (i=1;i<=k;i++)
  {
//   printf("%d %d\n",i,k);   
   j=i%(k-i+1);
   if (j==0)
    while (a[z]< 0x200000)
    {
     z--;
     if (z==0) 
      z=k;
    }  
   while (j)
   {
    
    z++;
    if (z>k) 
     z=1;
    if (a[z] & 0x200000)
     j--;
 //   printf("%d %d %ld a[2]%ld\n",j,z,a[z],a[2]);      
//    sleep(200); 
   }
   a[z]=a[z]^0x200000;
   a[z]=i | a[z];
  } 
  fscanf(f,"%ld",&n);
//   for (i=1;i<=k;i++)
//   printf("%ld ",a[i]);
  printf("%d %d\n",za,N); 
  fprintf(f1,"Case #%d:",za);
  
  for (i=0;i<n;i++)
  {
   fscanf(f,"%ld",&j);   
   fprintf(f1," %d",a[j]);
  }
  fprintf(f1,"\n");
 }
 fclose(f);
 fclose(f1);   
}
