#include<iostream>
#include<algorithm>
using namespace std;
int main(void){
    int a[3];
    for(int i=0;i<3;i++){
        cin >>a[i];
    }
    sort(a,a+3);
    if(a[0]==5&&a[1]==5&&a[2]==7){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}