#include <iostream>
#include <string>
using namespace std;
int main(){
    char s;
    int ss;
    cin >> s;
    string a = "ACGT";
    for(int i = 0;i<4;i++){
        if(s == a[i]){
            ss = i;
            break;
        }
    }
    cout << a[3-ss] << endl;
}