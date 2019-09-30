#include<iostream>
using namespace std;

int main(){

	int A, B, C,i,j,k,x,y;
	cin >> A >> B >> C;

	i = A+B;
	j = A+C;
	k = B+C;

	x = min(i,j);
	y = min(i,k);

	cout << min(x,y) << '\n';

	return 0;

}