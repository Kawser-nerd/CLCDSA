#include <string>
#include <stdio.h>
#include <iostream>

int main() {
    double deg, dis;
    std::string str1, str2;
    
    scanf("%lf%lf",&deg, &dis);
    
    deg /= 10.0;
    dis /= 60.0;
    
    //printf("%lf %2.20lf\n", deg, dis);

    //for deg
    if (11.25 <= deg && deg < 33.75) {
        //printf("NNE ");
        str1 = "NNE";
    } else if (33.75 <= deg && deg < 56.25) {
        //printf("NE ");
        str1 = "NE";
    } else if (56.25 <= deg && deg < 78.75) {
        //printf("ENE ");
        str1 = "ENE";
    } else if (78.75 <= deg && deg < 101.25) {
        //printf("E ");
        str1 = "E";
    } else if (101.25 <= deg && deg < 123.75) {
        //printf("ESE ");
        str1 = "ESE";
    } else if (123.75 <= deg && deg < 146.25) {
        //printf("SE ");
        str1 = "SE";
    } else if (146.25 <= deg && deg < 168.75) {
        //printf("SSE ");
        str1 = "SSE";
    } else if (168.75 <= deg && deg < 191.25) {
        //printf("S ");
        str1 = "S";
    } else if (191.25 <= deg && deg < 213.75) {
        //printf("SSW ");
        str1 = "SSW";
    } else if (213.75 <= deg && deg < 236.25) {
        //printf("SW ");
        str1 = "SW";
    } else if (236.25 <= deg && deg < 258.75) {
        //printf("WSW ");
        str1 = "WSW";
    } else if (258.75 <= deg && deg < 281.25) {
        //printf("W ");
        str1 = "W";
    } else if (281.25 <= deg && deg < 303.75) {
        //printf("WNW ");
        str1 = "WNW";
    } else if (303.75 <= deg && deg < 326.25) {
        //printf("NW ");
        str1 = "NW";
    } else if (326.25 <= deg && deg < 348.75) {
        //printf("NNW ");
        str1 = "NNW";
    } else {
        //printf("N ");
        str1 = "N";
    }
    
    //for dis
    if (0.0 <= dis && dis < 0.245) {
        //printf("0\n");
        str1 = "C";
        str2 = "0";
    } else if (0.245 <= dis && dis < 1.55) {
        //printf("1\n");
        str2 = "1";
    } else if (1.55 <= dis && dis < 3.35) {
        //printf("2\n");
        str2 = "2"; 
    } else if (3.35 <= dis && dis < 5.45) {
        //printf("3\n");
        str2 = "3";
    } else if (5.45 <= dis && dis < 7.95) {
        //printf("4\n");
        str2 = "4";
    } else if (7.95 <= dis && dis < 10.75) {
        //printf("5\n");
        str2 = "5";
    } else if (10.75 <= dis && dis < 13.85) {
        //printf("6\n");
        str2 = "6";
    } else if (13.85 <= dis && dis < 17.15) {
        //printf("7\n");
        str2 = "7";
    } else if (17.15 <= dis && dis < 20.75) {
        //printf("8\n");
        str2 = "8";
    } else if (20.75 <= dis && dis < 24.45) {
        //printf("9\n");
        str2 = "9";
    } else if (24.45 <= dis && dis < 28.45) {
        //printf("10\n");
        str2 = "10";
    } else if (28.45 <= dis && dis < 32.65) {
        //printf("11\n");
        str2 = "11";
    } else if (32.65 <= dis) {
        //printf("12\n");
        str2 = "12";
    }
    
    //printf("%s %s\n", str1, str2); 
    std::cout << str1 << " " << str2 << "\n";
    
    return 0;
}