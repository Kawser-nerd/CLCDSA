#include <stdio.h>
#include <limits.h>
typedef unsigned int uint;

inline static uint gl(void){
    uint x = 0;
    for(;;){
        uint c = getchar_unlocked() - 48;
        if(c < 10){
            x = x*10 + c;
        }else{
            break;
        }
    }
    return x;
}

#define H 200000
uint v[H+1];
int main(void){
    const uint h = gl();
    gl();
    const uint n = gl();
    for(uint i=1; i<h+1; i++){ v[i] = i+1; }
    for(uint i=0; i<n; i++){
        uint x = gl();
        uint y = gl();
        v[x] = y<v[x] ? y : v[x];
    }
    uint right = 1;
    for(uint x=1; x<h; x++){
        if(v[x+1]<right+1){
            printf("%d\n", x);
            return 0;
        }else if(v[x+1]>right+1){
            right++;
        }
    }
    printf("%d\n", h);
    return 0;
}