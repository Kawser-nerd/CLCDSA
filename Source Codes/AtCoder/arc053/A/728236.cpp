#include<iostream>
//#include<string>

using namespace std;

int h,w;

int main(){
	cin >> h >> w;

	
	cout << ((w-1)*h)+((h-1)*w) <<endl;

	return 0;
}