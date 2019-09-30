#include <stdio.h>
#include <unistd.h>

#define L 6
#define putchar_buf(X) do{ buf[point] = X; point++; }while(0)
#define putlong_buf(X) \
    do{ \
        long n=X; \
        char c[L]; \
        long i=L-1; \
        do{ c[i]=n%10+'0'; n/=10; i--; }while(n>0); \
        for(i++;i<L;i++){ putchar_buf(c[i]); } \
    }while(0)
#define puts_buf(X) \
    do { \
        for(size_t i=0; X[i]!='\0'; i++){ \
            putchar_buf(X[i]); \
        } \
        putchar_buf('\n'); \
    }while(0)

char buf[819200];
size_t point;

static void solve(const long a, const long b, const size_t sp, const size_t ep, long mask, const long common){
    if(ep-sp<=2){
        putlong_buf(common|a);
        putchar_buf(' ');
        putlong_buf(common|b);
        putchar_buf(' ');
    }else{
        const long t = a^b;
        const long d = t&(-t);
        mask ^= d;
        const long aa = a & mask;
        const long ab = aa ^ (mask&(-mask));
        const size_t mp = (sp+ep)/2;
        solve(aa,     ab, sp, mp, mask, common|(a&d));
        solve(ab, b&mask, mp, ep, mask, common|(b&d));
    }
}

int main(void){
    long n, a, b;
    scanf("%ld %ld %ld", &n, &a, &b);
    if(__builtin_parity(a) == __builtin_parity(b)){
        puts("NO");
    }else{
        const size_t m = 1<<n;
        puts_buf("YES");
        solve(a, b, 0, m, 0xFFFFFFFFFFFFFFFF, 0);
        write(1, buf, point);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld", &n, &a, &b);
     ^
./Main.c:52:9: warning: ignoring return value of ‘write’, declared with attribute warn_unused_result [-Wunused-result]
         write(1, buf, point);
         ^