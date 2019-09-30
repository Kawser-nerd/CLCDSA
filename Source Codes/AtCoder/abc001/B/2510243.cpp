#include <iostream>
using namespace std;
int main(void){
    int a;
    cin >>a;
    if(a<100)cout <<"00"<<endl;
    else if(a<1000)cout <<"0"<<a/100<<endl;
    else if(a<=5000)cout <<a/100<<endl;
    else if(a<=30000)cout <<a/1000+50<<endl;
    else if(a<=70000)cout <<(a/1000-30)/5+80<<endl;
    else cout <<"89"<<endl;
}