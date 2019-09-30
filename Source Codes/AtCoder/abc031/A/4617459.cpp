#include <iostream>
using namespace std;

int main(){
    int a,d;
    cin >> a >> d;
    if((a+1)*d>a*(d+1) && (a+1)*d>a*(d+1)){
        cout << (a+1)*d <<'\n';
    }else{
        cout << a*(d+1) << '\n';
    }

    return 0;
}