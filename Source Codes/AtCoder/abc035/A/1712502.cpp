#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  int a,b;
    cin >> a >> b;
    for(int i=0;i<123456;i++){
        if(a==4*i && b==3*i){
            cout << "4:3" << endl;
        }
        else if(a==16*i && b == 9*i){
            cout << "16:9" << endl;
        }
    }
    return 0;
}