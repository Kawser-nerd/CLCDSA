#include <stdio.h>
#include <unistd.h>
#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#define BUF_SIZE ((size_t)(16*1024))
char buf[BUF_SIZE];
size_t len;

inline void flush_buf(void){
    write(1, buf, len);
    len = 0;
}

inline void check_buf(size_t n){
    if(unlikely(len+n>=BUF_SIZE)){
        flush_buf();
    }
}

inline void putchar_buf(char c){
    buf[len] = c;
    len++;
}

inline void puts_buf(const char* s){
    size_t i;
    for(i=0; s[i]!='\0'; i++){
        buf[len+i]=s[i];
    }
    buf[len+i]='\n';
    len+=i+1;
}

static inline void print_int(int n){
#define BASE ((int)10)
#define MAX_LEN ((size_t)11)
    static char c[MAX_LEN];
    size_t i=MAX_LEN-1;
    do{
        c[i]=n%BASE+'0';
        n/=BASE;
        i--;
    }while(n>0);
    len+=MAX_LEN-1-i;
    do{
        ++i;
        buf[len+i-MAX_LEN] = c[i];
    }while(i<MAX_LEN-1);
#undef MAX_LEN
#undef BASE
}

static void solve(const int n, const int a, const int b, int mask, const int common){
    const int t = a^b;
    const int d = t&(-t);
    mask ^= d;
    const int aa = a & mask, ab = aa ^ (mask&(-mask));
    if(n==2){
        check_buf(4*7);
        print_int(common|a); putchar_buf(' ');
        print_int(common|ab|(a&d)); putchar_buf(' ');
        print_int(common|ab|(b&d)); putchar_buf(' ');
        print_int(common|b); putchar_buf(' ');
    }else{
        solve(n-1, aa, ab, mask, common|(a&d));
        solve(n-1, ab, b&mask, mask, common|(b&d));
    }
}

int main(void){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if(unlikely(__builtin_parity(a)==__builtin_parity(b))){
        puts_buf("NO");
    }else{
        puts_buf("YES");
        if(unlikely(n==1)){
            print_int(a);
            putchar_buf(' ');
            print_int(b);
            putchar_buf('\n');
        }else{
            solve(n, a, b, -1, 0);
        }
    }
    flush_buf();
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:72:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &a, &b);
     ^
./Main.c: In function ‘flush_buf’:
./Main.c:10:5: warning: ignoring return value of ‘write’, declared with attribute warn_unused_result [-Wunused-result]
     write(1, buf, len);
     ^