#include <iostream>
using namespace std;
int main(void){
    int n,n1,n2,n3;
    cin >> n;
    n1=n%100%10;
    n2=n/10%10;
    n3=n/100;

    if(n1==1){
        n1=9;
    }else{
        n1=1;
    }
    if(n2==1){
        n2=9;
    }else{
        n2=1;
    }
    if(n3==1){
        n3=9;
    }else{
        n3=1;
    }
    cout <<n3<<n2<<n1<<endl;
}