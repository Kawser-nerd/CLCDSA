#include <iostream>
using namespace std;
int main(){
    double res,sum=0;
    cin >> res;
    for(int i=1; i<=res;i++){
        sum += 10000*i/res;
    }
    cout << sum<<'\n';
    return 0;
}