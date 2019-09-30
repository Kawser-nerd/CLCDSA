#include <iostream>
using namespace std;

int main(){
    int vv;
    double  m;
    cin >> m;
    m /= 1000;
    if(m < 0.1){
        vv = 00;
    }else if(m <= 5){
        vv = 10 * m;
    }else if(m <= 30){
        vv = m + 50;
    }else if(m <= 70){
        vv = (m - 30) / 5 + 80;
    }else{
        vv = 89;
    }
    printf("%02d\n", vv);
}