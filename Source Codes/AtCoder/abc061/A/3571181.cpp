#include <iostream>
using namespace std;
int main(){
int A,B,C;




cin>>A>>B>>C;


if( A>=-100 && A<=100 && B>=-100 && B<=100 && C>=-100 && C<=100){

if(A<=C && B>=C ){
cout<<"Yes";
}
else cout<<"No";
}
}