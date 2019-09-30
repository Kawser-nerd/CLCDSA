#include<iostream>
#include<math.h>
using namespace std;

int incDeg(int nowTemp, int targetTemp){
    int operation = 0;
    if(abs(targetTemp - nowTemp) <= 3){
        operation = 1;
    }
    else if(abs(targetTemp - nowTemp) <= 7){
        operation = 5;
    }
    else{
        operation = 10;
    }
    return nowTemp + operation;
}

int decDeg(int nowTemp, int targetTemp){
    int operation = 0;
    if(abs(targetTemp - nowTemp) <= 3){
        operation = 1;
    }
    else if(abs(targetTemp - nowTemp) <= 7){
        operation = 5;
    }
    else{
        operation = 10;
    }
    return nowTemp - operation;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, nowTemp, counter = 0;
    cin >> a >> b;

    nowTemp = a;
    while (nowTemp != b){
        if(b - nowTemp > 0){
            counter++;
            nowTemp = incDeg(nowTemp, b);
        }
        else if(b - nowTemp < 0){
            counter++;
            nowTemp = decDeg(nowTemp, b);
        }
    }

    cout << counter << "\n";

    return 0;
}