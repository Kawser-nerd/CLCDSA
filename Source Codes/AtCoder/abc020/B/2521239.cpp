#include <iostream>
using namespace std;
int main(void){
    int a,b;
    cin >>a>>b;
    
    if(b<10) cout <<(a*10+b)*2<<endl;
    else if(b<100) cout <<(a*100+b)*2<<endl;
    else if(b<1000) cout <<(a*1000+b)*2<<endl;
    return 0;
}