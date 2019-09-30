#include <iostream>
using namespace std;
int main(void){
    int a,b;
    cin >>a>>b;
    
    if(a%b!=0){
        cout <<b-a%b<<endl;
    }else{
        cout <<"0"<<endl;
    }
}