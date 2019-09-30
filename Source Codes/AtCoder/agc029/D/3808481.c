#include <stdio.h>
typedef unsigned int uint;

inline static uint gl(void){
    uint x = 0;
    for(;;){
        const uint c = getchar_unlocked() - 48;
        if(c < 10){
            x = x*10 + c;
        }else{
            break;
        }
    }
    return x;
}
#define H 200000
uint v[H] __attribute__((aligned(64)));
int main(void){
    const uint h = gl();
    gl();
    const uint n = gl();
    for(uint i=0; i<H; i++){ v[i] = 0x33333333; }
    for(uint i=0; i<n; i++){
        const uint x = gl()-1;
        const uint y = gl()-1;
        v[x] = y<v[x] ? y : v[x];
    }
    uint right = 0;
    for(uint x=1; x<h; x++){
        const auto b = v[x];
        const auto r = right+1;
        if(b<r){
            printf("%d\n", x);
            return 0;
        }else if(b>r){
            right=r;
        }
    }
    printf("%d\n", h);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:20: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
         const auto b = v[x];
                    ^
./Main.c:31:20: warning: type defaults to ‘int’ in declaration of ‘r’ [-Wimplicit-int]
         const auto r = right+1;
                    ^