#include <stdio.h>

int main()
{
   int i,n,even=0,odd=0;
   scanf("%d",&n);
   for(i=1; i<=n; i++){
       if(i%2==0){
           even++;
       }
       else odd++;
   }
   printf("%d",even*odd);

    return 0;
}