#include <iostream>
using namespace std;
int main(){
    int a,b,n;
    cin >> a;
    cin >> b;
    cin >> n;
    for(int i=n;n<=20000;i++){
        if(a==b && i%a==0){
            cout << i <<'\n';
            break;
        }
        else if(a!=b && i%a == 0 && i%b == 0){
            cout << i << '\n';
            break;
        }
    }
    return 0;
}