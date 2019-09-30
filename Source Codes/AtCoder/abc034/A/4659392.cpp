#include <iostream>
using namespace std;
int main(){
    int x,y;
    cin >>x >>y;
    if(x<y){
        cout << "Better" << endl; 
    }else if(y<x){
        cout << "Worse" << endl;
    }
    return 0;
}