#include <iostream>
#include <string>

int deg, dis;
int main() {
    std::cin >> deg >> dis;
    
    deg = ((deg * 10) + 1125) % 36000;
    
    std::string d;
    if (deg < 2250) {
        d = "N";
    }else if(deg < 2250 * 2){
        d = "NNE";
    }else if(deg < 2250 * 3){
        d = "NE";
        
    }else if(deg < 2250 * 4){
        d = "ENE";
        
    }else if(deg < 2250 * 5){
        d = "E";
        
    }else if(deg < 2250 * 6){
        d = "ESE";
        
    }else if(deg < 2250 * 7){
        d = "SE";
        
    }else if(deg < 2250 * 8){
        d = "SSE";
        
    }else if(deg < 2250 * 9){
        d = "S";
        
    }else if(deg < 2250 * 10){
        d = "SSW";
        
    }else if(deg < 2250 * 11){
        d = "SW";
        
    }else if(deg < 2250 * 12){
        d = "WSW";
        
    }else if(deg < 2250 * 13){
        d = "W";
        
    }else if(deg < 2250 * 14){
        d = "WNW";
        
    }else if(deg < 2250 * 15){
        d = "NW";
        
    }else if(deg < 2250 * 16){
        d = "NNW";
    }
    
    double dd = double(dis) / 60.;
    
    int W = 0;
    if(dd < 0.25) {
    }else if (dd < 1.55) {
        W = 1;
        
    }else if (dd < 3.35) {
        W = 2;
        
    }else if (dd < 5.45) {
        W = 3;
        
    }else if (dd < 7.95) {
        
        W = 4;
    }else if (dd < 10.75) {
        
        W = 5;
    }else if (dd < 13.85) {
        W = 6;
        
    }else if (dd < 17.15) {
        W = 7;
        
    }else if (dd < 20.75) {
        W = 8;
        
    }else if (dd < 24.45) {
        
        W = 9;
    }else if (dd < 28.45) {
        W = 10;
        
    }else if (dd < 32.65) {
        W = 11;
        
    }else {
        W = 12;
        
    }
    
    if (W == 0) {
           d = "C";
    }
    
    std::cout << d << " " << W << std::endl;
}