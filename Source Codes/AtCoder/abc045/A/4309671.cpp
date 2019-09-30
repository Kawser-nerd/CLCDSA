#include<iostream>
using namespace std;
int main(void){
    int a[3];
    for(int i=0;i<3;i++){
        cin >> a[i];
    }
        cout<<(a[0]+a[1])*a[2]/2<<endl;
}