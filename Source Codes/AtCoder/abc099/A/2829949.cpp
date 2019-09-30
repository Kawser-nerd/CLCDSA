#include<iostream>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	if (N < 1000)cout << "ABC" << endl;
	else if (N >= 1000)cout << "ABD" << endl;

}