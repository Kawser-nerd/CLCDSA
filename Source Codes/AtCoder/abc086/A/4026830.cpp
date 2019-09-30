#include <iostream>
using namespace std;

void devide(int a,int b){
    if(a*b % 2 == 0){
        cout << "Even" << endl;
    }else{cout << "Odd" << endl;
    }
}

int main(){
    int a,b;
    cin >> a >> b;
    devide(a,b);
}