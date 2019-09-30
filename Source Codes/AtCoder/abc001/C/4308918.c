#include <stdio.h>
#include <math.h>

int main(){
    int deg,dis;
    double beaufort[]={0.2, 1.5, 3.3, 5.4, 7.9, 10.7, 13.8, 17.1, 20.7, 24.4, 28.4, 32.6};
    double v;
    char* deg16[]={"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};
    char* dir;
    int w;
    scanf("%d %d", &deg, &dis);
    dir = deg16[((int)((deg+112.5)/225))%16];
    v = (int)((dis / 6.0)+0.5)/10.0;
    for (w = 0; w < 12; w++)
        if (v <= beaufort[w])
            break;
    if(w == 0)dir="C";
    printf("%s %d\n", dir, w);
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &deg, &dis);
     ^