#include <iostream>
using namespace std;
int sum(int n){
	int s = 0;
	while(n){
		s+= n%10;
		n/=10;
	}
	return s;
}
int main(){
	int n,min = 100000;
	cin>>n;
	for(int i = n-1,j = 1;i>0;i--,j++){
		int suma = sum(j) +sum(i); 
		if(suma<min) min = suma;
	}
	cout<<min<<endl;
	return 0;
}