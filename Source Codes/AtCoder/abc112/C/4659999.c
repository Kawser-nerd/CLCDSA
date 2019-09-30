#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
//#define ABS(a) ((a)>(0)?(a):-(a))


SINT32 main() {
    SINT32 a;
    scanf("%d",&a);

    SINT32 xdata[101] = {0};
    SINT32 ydata[101] = {0};
    SINT32 hdata[101] = {0};

    SINT32 hmax = 0;

    SINT32 ansx = 0;
    SINT32 ansy = 0;
    SINT32 temp = 0;

    for (SINT32 i = 0; i < a; i++) {
        scanf("%d%d%d", &xdata[i],&ydata[i],&hdata[i]);
        if (hdata[i] > 0) {
            temp = i;
        }
    }

    int ans = 0;
    int ok = 0;
    for (SINT32 i = 0; i < 101; i++) {
        for (SINT32 j = 0; j < 101; j++) {
            ans = 0;
            ok = 0;
            ans = abs(xdata[temp]-i) + abs(ydata[temp]-j) + hdata[temp];
            
            for (SINT32 k = 0; k < a; k++) {
                if (hdata[k] != MAX(0,ans -abs(xdata[k]-i) - abs(ydata[k]-j))) {
                    ok = 1;
                    break;
                }
            }
            if (ok == 0) {
                ansx = i;
                ansy = j;
                break;
            }
        }
        if (ok == 0) {
            break;
        }
    }

    printf("%d %d %d\n",ansx, ansy, ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
./Main.c:34:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d", &xdata[i],&ydata[i],&hdata[i]);
         ^