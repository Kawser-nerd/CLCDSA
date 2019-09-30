#include<iostream>
using namespace std;
int main(){
    int m,VV;
    cin>>m;
    if(m<100){
        cout<<"00"<<"\n";
    }else if(m>=100&&m<=5000){
        VV=m/100;
        if(VV<10){
            cout<<0<<VV<<"\n";
        }else{
            cout<<VV<<"\n";
        }
    }else if(m>=6000&&m<=30000){
        cout<<m/1000+50<<"\n";
    }else if(m>=35000,m<=70000){
        cout<<(m/1000-30)/5+80<<"\n";
    }else if(m>=70){
        cout<<89<<"\n";
    }
    return 0;
} ./Main.cpp:17:15: warning: relational comparison result unused [-Wunused-comparison]
    }else if(m>=35000,m<=70000){
             ~^~~~~~~
1 warning generated.