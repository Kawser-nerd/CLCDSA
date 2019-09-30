#include<iostream>
using namespace std;
bool T[100000];

int main(void){
int N;
cin >> N ;
int cnt=0;
int k=0;
for (int i=0; i<N; i++){
int j;
cin >>j; 
if (T[j]) k++;
else{T[j]=true; cnt++;}
}
cout << (k%2 == 0 ? cnt : cnt-1) << endl;
return 0 ;
}