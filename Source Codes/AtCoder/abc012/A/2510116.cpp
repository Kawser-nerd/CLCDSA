#include <iostream>
using namespace std;
int main(void){
    int a,b;
    int tmp;
    
    cin >>a>>b;
    
    tmp=a;
    a=b;
    b=tmp;
    cout <<a<<" "<<b<<endl;
}