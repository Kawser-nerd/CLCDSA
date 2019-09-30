#include<stdio.h>

int main(void){
        int Deg , Dis , W;
        scanf("%d%d" , &Deg , &Dis);

        if(0 <= Dis && Dis < 15){
                W = 0;
                printf("C");
        }else
                {if(15 <= Dis && Dis < 93)W = 1;
                else if(93 <= Dis && Dis < 201)W = 2;
                else if(201 <= Dis && Dis < 327)W = 3;
                else if(327 <= Dis && Dis < 477)W = 4;
                else if(477 <= Dis && Dis < 645)W = 5;
                else if(645 <= Dis && Dis < 831)W = 6;
                else if(831 <= Dis && Dis < 1029)W = 7;
                else if(1029 <= Dis && Dis < 1245)W = 8;
                else if(1245 <= Dis && Dis < 1467)W = 9;
                else if(1467 <= Dis && Dis < 1707)W = 10;
                else if(1707 <= Dis && Dis < 1959)W = 11;
                else W = 12;

                if(112 < Deg && Deg <= 337)printf("NNE");
                else if(337 < Deg && Deg <= 562)printf("NE");
                else if(562 < Deg && Deg <= 787)printf("ENE");
                else if(787 < Deg && Deg <= 1012)printf("E");
                else if(1012 < Deg && Deg <= 1237)printf("ESE");
                else if(1237 < Deg && Deg <= 1462)printf("SE");
                else if(1462 < Deg && Deg <= 1687)printf("SSE");
                else if(1687 < Deg && Deg <= 1912)printf("S");
                else if(1912 < Deg && Deg <= 2137)printf("SSW");
                else if(2137 < Deg && Deg <= 2362)printf("SW");
                else if(2362 < Deg && Deg <= 2587)printf("WSW");
                else if(2587 < Deg && Deg <= 2812)printf("W");
                else if(2812 < Deg && Deg <= 3037)printf("WNW");
                else if(3037 < Deg && Deg <= 3262)printf("NW");
                else if(3262 < Deg && Deg <= 3487)printf("NNW");
                else printf("N");
        }

        printf(" %d\n" , W);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d" , &Deg , &Dis);
         ^