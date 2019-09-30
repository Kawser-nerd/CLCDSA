#include<stdio.h>
int main()
{
       int A,B,C,D;
        while(~scanf("%d %d %d %d",&A,&B,&C,&D))
       {
                  int min1,min2,min;
                  min1=(A<B)? A:B;
                  min2=(C<D)? C:D;
                  min=min1+min2;
                   printf("%d\n",min);
       }
}