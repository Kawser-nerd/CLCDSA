#include <iostream>
using namespace std;
int main(void){
    string a,b;
    cin >>a>>b;
    
    if(a.size()<b.size()) cout <<b<<endl;
    else cout <<a<<endl;
    
    return 0;
}