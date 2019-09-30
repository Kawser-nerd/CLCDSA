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


SINT32 main() {
    SINT32 a,b;
    SINT32 ans = 1001;
    scanf("%d%d",&a,&b);


    SINT32 dataA,dataB;
    
    for (SINT32 i = 0; i < a; i++) {
        scanf("%d%d", &dataA,&dataB);
        if (dataB <= b) {
            if (ans >= dataA) {
                ans = dataA;
            }
        }

    }


    if (ans == 1001) {
        printf("TLE");
    } else {
        printf("%d\n",ans);
    }
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&a,&b);
     ^
./Main.c:27:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &dataA,&dataB);
         ^