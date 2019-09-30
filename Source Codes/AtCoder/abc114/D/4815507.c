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
    SINT32 max = 100;

    SINT32 n;
    scanf("%d",&n);

    SINT32 sosu[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    SINT32 sosukazu[25] = {0};
    
    for (SINT32 i = 1; i < n+1; i++) {
        SINT32 buf = i;
        for (SINT32 j = 0; j < 25; j++) {

            if (buf == 1) {
                break;
            }

            while (buf%sosu[j] == 0) {
                buf = buf/sosu[j];
                sosukazu[j] = sosukazu[j] + 1;
            }
        }
    }

    SINT32 count2 = 0;
    SINT32 count4 = 0;
    SINT32 count14 = 0;
    SINT32 count24 = 0;
    SINT32 count74 = 0;

    for (SINT32 j = 0; j < 25; j++) {
        if (sosukazu[j] >= 2) {
            count2++;
        }
        if (sosukazu[j] >= 4) {
            count4++;
        }
        if (sosukazu[j] >= 14) {
            count14++;
        }
        if (sosukazu[j] >= 24) {
            count24++;
        }
        if (sosukazu[j] >= 74) {
            count74++;
        }
    }
 /*   for (SINT32 j = 0; j < 25; j++) {
        printf("%d ",sosukazu[j]);
    }
    printf("\n");

    printf("%d %d %d %d %d\n",count2,count4,count14,count24,count74);
*/

    if (count4 == 0) {
        printf("0");
    } else {
        SINT32 ans = count74+count24*(count2-1) + count14*(count4-1) + count4*(count4-1)*(count2-2)/2;
        printf("%d\n",ans);
    }

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^