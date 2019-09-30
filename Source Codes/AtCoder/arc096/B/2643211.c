#include<stdio.h>
int main()
{
        long long n, c, x,xn,v;
       scanf("%lld",&n);
       scanf("%lld",&c);
       long long p =0;
       long long q = 0;
       long long pans1 = 0;
       long long qans1 = 0;
       long long pans2 =0;
       long long qans2 = 0;
       long long qzn = 0;
       long long pzn = 0;
       x = 0;
       for(int i =0;i<n;i++){
           scanf("%lld",&xn);
           scanf("%lld",&v);
           if(pans1 > (p-(xn-x))){
               pans1 = (p-(xn-x));
           }
           if(qans2 > (q-2*(xn-x))){
               qans2 = (q-2*(xn-x));
           }
           if(qzn-(p-(xn-x))>qans1 - pans1){
               qans1 =qzn ;
               pans1 = p-(xn-x);
           }
            if(pzn-(q-2*(xn-x))>pans2 - qans2){
            pans2 = pzn;
            qans2 = q-2*(xn-x);
        }
            p = p-(xn-x);
           q = q-2*(xn-x);
           
           
           q = q +v;
       
           p = p+v;
           if(qzn<q){
               qzn = q;
           }
           if(pzn<p){
               pzn = p;
           }
           x = xn;
          // printf("%lld %lld %lld %lld\n",pans1,qans1,pans2,qans2);
       }
        if(pans1 > (p-(c-x))){
               pans1 = (p-(c-x));
           }
           if(qans2 > (q-2*(c-x))){
               qans2 = (q-2*(c-x));
           }
       if(q-(p-(c-x))>qans1 - pans1){
               qans1 =q ;
               pans1 = p-(c-x);
           }
            if(p-(q-2*(c-x))>pans2 - qans2){
            pans2 = p;
            qans2 = q-2*(c-x);
        }
        //printf("%lld %lld %lld %lld\n",pans1,qans1,pans2,qans2);
p = p-(c-x);
           q = q-2*(c-x);
       // printf("%lld",p+qans1-pans1);
      // printf("%lld",p-c+pans2-qans2);
     if(p+qans1-pans1>p-c+pans2-qans2){
         printf("%lld",p+qans1-pans1);
     }
     else{
        // printf("%lld\n",p);
         printf("%lld",p-c+pans2-qans2);
     }

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%lld",&n);
        ^
./Main.c:6:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%lld",&c);
        ^
./Main.c:17:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
            scanf("%lld",&xn);
            ^
./Main.c:18:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
            scanf("%lld",&v);
            ^