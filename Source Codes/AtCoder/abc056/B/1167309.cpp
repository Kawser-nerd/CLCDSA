#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
	int W, a, b;
	cin >> W >> a >> b;

	int c;
	if(b+W < a || a+W < b){
		c = min(abs(a-b+W), abs(b-a+W));
	}else c = 0;

	cout << c << endl;
}