#include <iostream>
#include <string>
using namespace std;
int main(void){
    string a;
    cin >> a;
    int b = 0;
    
    for (int i = 0; i<3; i++){
        if(a[i] == '1') b++;
    }
    cout << b;
}