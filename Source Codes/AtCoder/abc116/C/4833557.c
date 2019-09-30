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
#define ABS(a) ((a)>(0)?(a):-(a))


SINT32 main() {
    SINT32 ans = 0;
    SINT32 max = 10;

    scanf("%d",&max);


    
    SINT32 *data = malloc(sizeof(SINT32)*max);
    for (SINT32 i = 0; i < max; i++) {
        scanf("%d", &data[i]);
    }

    
    
    while(1) {
        SINT32 buf = 0;
        SINT32 buf2 = 1;
        for (SINT32 i = 0; i < max; i++) {
            if (data[i] == 0) {
                if (buf == 1) {
                    ans = ans + 1;
                    buf = 0;
                }
            } else {
                data[i] = data[i] - 1;
                buf = 1;
                buf2 = 0;
            }
        }
        if (buf==1) {
            ans = ans + 1;
        }
        if (buf2 == 1) {
            break;
        }
    }


    printf("%d\n",ans);
    free(data);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&max);
     ^
./Main.c:29:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &data[i]);
         ^