#include <stdio.h>
   #include <stdlib.h>
   #include <time.h>
    
   int main(){
       int n, ans=0;
       scanf("%d",&n);
       if(n % 10 == 1){
       	ans += 9;
       } else if(n % 10 == 9){
       	ans += 1;
       } else {
       	ans += (n % 10);
       }
       int x = (n / 10) % 10;
       switch(x){
       	case 1: ans += 90; break;
       	case 9: ans += 10; break;
       	default: ans += (x * 10); break;
       }
       x = n / 100;
       switch (x){
       	case 1: ans += 900; break;
       	case 9: ans += 100; break;
       	default: ans += x * 100; break;
       }
       printf("%d", ans);
       return 0;
   } ./Main.c: In function ‘main’:
./Main.c:7:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%d",&n);
        ^