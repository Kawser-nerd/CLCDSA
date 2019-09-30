#include <iostream>
#include <string>
using namespace std;
int main(){
    char b;
    cin>>b;
    if (b=='A'){
        cout<<'T'<<endl;
    }
    else if(b=='T'){
        cout<<'A'<<endl;
    }
    else if(b=='G'){
        cout<<'C'<<endl;
    }
    else{
        cout<<'G'<<endl;
    }
}