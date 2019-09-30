#include<iostream>
using namespace std;
int main(){
	long long sum,num1,num2;
	cin>>sum>>num1>>num2;
	if(num1>num2){
		cout<<"0";
		return 0;
	}
	if(num1!=num2 && sum==1){
		cout<<"0";
		return 0;
	}
	long long max,min;
	min=(sum-1)*num1+num2;
	max=(sum-1)*num2+num1;
	cout<<max-min+1;
	return 0;
}