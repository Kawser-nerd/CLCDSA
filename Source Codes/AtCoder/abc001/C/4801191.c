#include <stdio.h>
#include <string.h>
#include <math.h>

#define NUM 4

char* getDir(int);
int getPower(int);

int
main(){
    int deg, dis, power, status;
    char dir[NUM];
    status = scanf("%d %d", &deg, &dis);
    if( status == EOF || deg < 0 || 3600 <= deg || dis < 0 ||  12000 <= dis ) {
        return 1;
    } 
    
    power = getPower(dis);
    if(power){
        strcpy(dir,getDir(deg));
    } else {
        strcpy(dir,"C");
    }
    
    
    printf("%s %d\n", dir, power);
    return 0;
    
}

char *
getDir(int deg){
    char *directions[17] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW","N"};
    int quotient = ((deg * 10 + 1125)/2250) % 16;
    
    return directions[quotient];
}

int
getPower(int dis){
    int ret;
 
    if( 32.65 * 60 <= dis){
        ret = 12;
    } else if( 28.45 * 60 <= dis ){
        ret = 11;
    } else if( 24.45 * 60 <= dis ){
        ret = 10;
    } else if( 20.75 * 60 <= dis ){
        ret = 9;
    } else if( 17.15 * 60 <= dis ){
        ret = 8; 
    } else if( 13.85 * 60 <= dis ){
        ret = 7;
    } else if( 10.75 * 60 <= dis ){
        ret = 6;
    } else if( 7.95 * 60 <= dis ){
        ret = 5;
    } else if( 5.45 * 60 <= dis ){
        ret = 4;
    } else if( 3.35 * 60 <= dis ){
        ret = 3;
    } else if( 1.55 * 60 <= dis ){
        ret = 2;
    } else if( 0.25 * 60 <= dis ){
        ret = 1;
    } else {
        ret = 0;
    }
    
    return ret;
}