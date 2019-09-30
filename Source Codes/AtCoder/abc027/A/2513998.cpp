#include <iostream>
using namespace std;
int main(void){
    int a,b,c,d;
    cin >>a>>b>>c;
    if(a==b) d=c;
    else if(b==c) d=a;
    else if(a==c) d=b;
    
    cout <<d<<endl;
    
    return 0;
}