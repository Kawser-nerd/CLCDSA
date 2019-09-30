#include <cstdio>

int main(){
    int T;
    scanf("%d", &T);
    for(int c=1; c<=T; c++){
        long long r, t;
        scanf("%lld %lld", &r, &t);
        long long res=0;
        while(t/1000 > 2*r+1999){
            t-=2*r*1000 + 1999000;
            r+=2000;
            res+=1000;
        }
        while(t >= 2*r+1){
            t-=2*r+1;
            r+=2;
            res++;
        }
        printf("Case #%d: %lld\n", c, res);
    }
}
