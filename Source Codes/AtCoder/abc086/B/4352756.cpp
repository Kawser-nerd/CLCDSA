#include<iostream>
#include<cmath>

using namespace std;

int  main(){
    int a,b;
    int tmp;
    cin >> a >> b;
    if(b < 10){
        tmp = a * 10 + b;
    }else if(b < 100){
        tmp = a * 100 + b;
    }else{
        tmp = a * 1000 + b;
    }
    for(int i = 1; i < 1000; i++){
        if(tmp == i * i){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}