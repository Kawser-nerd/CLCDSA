#include <iostream>
#include <math.h>
using namespace std;

int convertDis(double dis){
    if(0.0<=dis && dis<=0.2){
        return 0;
    }else if(0.3<=dis && dis<=1.5){
        return 1;
    }else if(1.6<=dis && dis<=3.3){
        return 2;
    }else if(3.4<=dis && dis<=5.4){
        return 3;
    }else if(5.5<=dis && dis<=7.9){
        return 4;
    }else if(8.0<=dis && dis<=10.7){
        return 5;
    }else if(10.8<=dis && dis<=13.8){
        return 6;
    }else if(13.9<=dis && dis<=17.1){
        return 7;
    }else if(17.2<=dis && dis<=20.7){
        return 8;
    }else if(20.8<=dis && dis<=24.4){
        return 9;
    }else if(24.5<=dis && dis<=28.4){
        return 10;
    }else if(28.5<=dis && dis<=32.6){
        return 11;
    }else if(32.7<=dis){
        return 12;
    }
    return -1;
}

string convertDeg(double deg){
    if(11.25<=deg && deg<33.75){
        return "NNE";
    }else if(33.75<=deg && deg<56.25){
        return "NE";
    }else if(56.25<=deg && deg<78.75){
        return "ENE";
    }else if(78.75<=deg && deg<101.25){
        return "E";
    }else if(101.25<=deg && deg<123.75){
        return "ESE";
    }else if(123.75<=deg && deg<146.25){
        return "SE";
    }else if(146.25<=deg && deg<168.75){
        return "SSE";
    }else if(168.75<=deg && deg<191.25){
        return "S";
    }else if(191.25<=deg && deg<213.75){
        return "SSW";
    }else if(213.75<=deg && deg<236.25){
        return "SW";
    }else if(236.25<=deg && deg<258.75){
        return "WSW";
    }else if(258.75<=deg && deg<281.25){
        return "W";
    }else if(281.25<=deg && deg<303.75){
        return "WNW";
    }else if(303.75<=deg && deg<326.25){
        return "NW";
    }else if(326.25<=deg && deg<348.75){
        return "NNW";
    }else{
        return "N";
    }
}

int main(void){
    // Your code here!
    double deg, dis;
    
    cin >> deg >> dis;
    
    int W = convertDis(round(dis/6.0f)/10);
    
    string Dir;
    if(W==0){
        Dir = "C";
    }else{
        Dir = convertDeg(deg/10.0f);
    }
    
    cout << Dir << " " << W << endl;
    
    //cout << round(dis/6.0f)/10 << endl;
}