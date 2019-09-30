#include<iostream>
using namespace std;
int main(void){
    int a[5];
    a[4]=0;
    for(int i=0;i<4;i++){
        cin >> a[i];
    }
    for(int i=0;i<a[0];i++){
        if(i>=a[1]){
            a[4]=a[4]+a[3];
        }else{
            a[4]=a[4]+a[2];
        }
    }
        cout<<a[4]<<endl;
}