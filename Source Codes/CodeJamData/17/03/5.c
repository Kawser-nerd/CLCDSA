#include<stdio.h>
#include <stdint.h>

uint64_t calc(uint64_t toaletter, uint64_t personer)
{
    if (personer==1) {
        return toaletter;
    }
    toaletter -= 1;
    personer -= 1;
    if (personer%2 == 1) {
        return calc(toaletter - toaletter/2, personer - personer/2);
    }
    if (toaletter % 2 == 1){
        return calc(toaletter/2,personer/2);
    }
    
    return calc(toaletter/2,personer/2);

}


int main(int argc, char **argv)
{
    size_t q;
    scanf("%d",&q);
    
    for (size_t cas = 1; cas<=q; ++cas){
        uint64_t N;
        uint64_t K;
        scanf("%llu %llu", &N, &K);

        uint64_t tol = calc(N,K);

        printf("Case #%d: %llu %llu\n", cas, tol/2, (tol-1)/2);
    }
}
