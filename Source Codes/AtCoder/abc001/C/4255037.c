#include <stdio.h>

int main()
{
    int deg;
    int dis;
    int w;
    char *dir;

    scanf("%d %d", &deg, &dis);

    dis = ((dis * 100) / 60 + 5) / 10;

    if(dis <= 2) {
        w = 0;
    } else if(dis <= 15) {
        w = 1;
    } else if(dis <= 33) {
        w = 2;
    } else if(dis <= 54) {
        w = 3;
    } else if(dis <= 79) {
        w = 4;
    } else if(dis <= 107) {
        w = 5;
    } else if(dis <= 138) {
        w = 6;
    } else if(dis <= 171) {
        w = 7;
    } else if(dis <= 207) {
        w = 8;
    } else if(dis <= 244) {
        w = 9;
    } else if(dis <= 284) {
        w = 10;
    } else if(dis <= 326) {
        w = 11;
    } else {
        w = 12;
    }

    if(w == 0) {
        printf("C 0\n");
        return 0;
    }

    if(deg < 113) {
        dir = "N";
    } else if(deg < 338) {
        dir = "NNE";
    } else if(deg < 563) {
        dir = "NE";
    } else if(deg < 788) {
        dir = "ENE";
    } else if(deg < 1013) {
        dir = "E";
    } else if(deg < 1238) {
        dir = "ESE";
    } else if(deg < 1463) {
        dir = "SE";
    } else if(deg < 1688) {
        dir = "SSE";
    } else if(deg < 1913) {
        dir = "S";
    } else if(deg < 2138) {
        dir = "SSW";
    } else if(deg < 2363) {
        dir = "SW";
    } else if(deg < 2588) {
        dir = "WSW";
    } else if(deg < 2813) {
        dir = "W";
    } else if(deg < 3038) {
        dir = "WNW";
    } else if(deg < 3263) {
        dir = "NW";
    } else if(deg < 3488) {
        dir = "NNW";
    } else {
        dir = "N";
    }

    printf("%s %d\n", dir, w);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &deg, &dis);
     ^