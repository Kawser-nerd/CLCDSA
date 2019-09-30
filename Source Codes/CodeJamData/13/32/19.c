#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
void process(long long int i)
{
printf("Case #%lld: ",i+1);
long long int p,q;
scanf("%lld %lld",&p,&q);
long long int m=0;
long int x=0,k,z;
if(p>=0)
{
    while((p-x)>=m+1)
    {
        printf("E");
        m++;
        x=x+m;
    }
   // getch();

    z=p-x;
    for(k=0;k<z;k++)
    {
        printf("WE");
        m=m+2;
    }

//printf("\n%lld",m);
  //////////////////////////
  x=0;
  if(q>0)
{
    while((q-x)>=m+1)
    {
        printf("N");
        m++;
        x=x+m;
    }

    z=q-x;
    for(k=0;k<z;k++)
    {
        printf("SN");
        m=m+2;
    }
}

  /////////////
  x=0;
 if(q<0)
{
    q= -q;
    while((q-x)>=m+1)
    {
        printf("S");
        m++;
        x=x+m;
    }

    z=q-x;
    for(k=0;k<z;k++)
    {
        printf("NS");
        m=m+2;
    }
}


}
if(p<0)
{
p= -p;
while((p-x)>=m+1)
    {
        printf("W");
        m++;
        x=x+m;
    }
   // getch();

    z=p-x;
    for(k=0;k<z;k++)
    {
        printf("EW");
        m=m+2;
    }

//printf("\n%lld",m);
  //////////////////////////
  x=0;
  if(q>0)
{
    while((q-x)>=m+1)
    {
        printf("N");
        m++;
        x=x+m;
    }

    z=q-x;
    for(k=0;k<z;k++)
    {
        printf("SN");
        m=m+2;
    }
}

  /////////////
  x=0;
  if(q<0)
{
    q= -q;
    while((q-x)>=m+1)
    {
        printf("S");
        m++;
        x=x+m;
    }

    z=q-x;
    for(k=0;k<z;k++)
    {
        printf("NS");
        m=m+2;
    }
}

}


printf("\n");
}



int main()
{

long long int t,i;
scanf("%lld",&t);

for(i=0;i<t;i++)
process(i);
return 0;
}
