#include <iostream>
using namespace std;
int main(void){

    int a, i;
    int reslut=0;
    
    cin >>a;
    
    for(i=1; i<=a; i++){
        
        reslut += i;
        
    }
    
    reslut = reslut*10000/a;
    
    cout <<reslut <<endl;
    return 0;
}