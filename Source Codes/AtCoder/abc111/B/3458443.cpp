#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
 
    int n;
     n= N/111;
 if(N%111==0){
    cout <<n*111;
}else{
cout << (n+1)*111;
}
}