#include <iostream>
using namespace std;
int main(){
    int a,b,c;
    cin >>a>>b>>c;
    if(a != b && a != c && b != c){
        cout << "3\n";
    }else if(a == b && a == c && b == c){
        cout << "1\n";
    }else{
        cout << "2\n";
    }
    return 0;
}