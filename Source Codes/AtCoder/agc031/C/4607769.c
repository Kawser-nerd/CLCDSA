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

int data[1<<17];
char buf[819200];

static void solve(long a, long b, const size_t sp, const size_t ep, long mask, long common){
    if(ep-sp<=2){
        data[sp+0] = common|a;
        data[sp+1] = common|b;
    }else{
        const long t = a^b;
        const long d = t&(-t);
        mask ^= d;
        const long ad = a&d;
        const long bd = b&d;
        a &= mask;
        const long ab = a ^ (mask&(-mask));
        const size_t mp = (sp+ep)/2;
        //printf("%ld %ld %ld\n", aa, ab, bb);
        solve( a,     ab, sp, mp, mask, common|ad);
        solve(ab, b&mask, mp, ep, mask, common|bd);
        //for(size_t i=sp; i<mp; i++){ data[i] |= ad; }
        //for(size_t i=mp; i<ep; i++){ data[i] |= bd; }
    }
}

int main(void){
    long n, a, b;
    scanf("%ld %ld %ld", &n, &a, &b);
    if(__builtin_parity(a) == __builtin_parity(b)){
        puts("NO");
    }else{
        const size_t m = 1<<n;
        solve(a, b, 0, m, 0xFFFFFFFFFFFFFFFF, 0);
        size_t point=0;
        puts_buf("YES");
        for(size_t i=0; i<m-1; i++){
            putlong_buf(data[i]);
            putchar_buf(' ');
        }
        putlong_buf(data[m-1]);
        putchar_buf('\n');
        write(1, buf, point);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:48:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld", &n, &a, &b);
     ^
./Main.c:62:9: warning: ignoring return value of ‘write’, declared with attribute warn_unused_result [-Wunused-result]
         write(1, buf, point);
         ^