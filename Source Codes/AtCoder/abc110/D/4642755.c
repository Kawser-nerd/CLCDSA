#include <stdio.h>
#include <stdlib.h>

typedef char                SINT8;
typedef unsigned char       UINT8;
typedef short               SINT16;
typedef unsigned short      UINT16;
typedef int                 SINT32;
typedef unsigned int        UINT32;
typedef long long           SINT64;
typedef unsigned long long  UINT64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define MOD 1000000007

SINT64 combination(SINT64 a, SINT64 b);
SINT64 modpow(SINT64 base, SINT64 exp);

SINT32 main() {
    SINT32 n,m;
    scanf("%d%d",&n,&m);
    SINT64 ans = 1;
    SINT32 m_nokori = m;

    for (UINT64 i = 2; i*i <= m_nokori; i++) {

        if ((m_nokori % i) == 0) {
            SINT32 count = 0;
            while ((m_nokori % i) == 0) {
                count++;
                m_nokori = m_nokori / i;
            }
            ans = ans * combination(n+count-1, n-1);
            ans = ans % MOD;
        }
    }

    if (m_nokori != 1) {
        ans = ans * combination(n+1-1, n-1);
        ans = ans % MOD;       
    }


    printf("%lld\n",ans);
	return 0;
}

//?????
SINT64 combination(SINT64 a, SINT64 b) {
    SINT64 bunshi = 1;
    SINT64 bunbo = 1;

    for (SINT32 i = 0; i < b; i++) {
        bunshi = (bunshi * (a - i)) % MOD;
        bunbo  = (bunbo  * (i + 1)) % MOD;
    }

    return bunshi * modpow(bunbo, MOD-2) % MOD; //??
}

//???
SINT64 modpow(SINT64 base, SINT64 exp) {
    SINT64 half;
  
    if (exp == 0) {
        return 1;
    } else {
        if ((exp % 2) == 0) {
            //??
            half = modpow(base, exp/2);
            return ((half*half) % MOD);
        } else {
            //??
            return (base * modpow(base, exp-1) % MOD);
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^