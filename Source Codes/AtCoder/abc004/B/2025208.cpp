#include <iostream>
#include <string>
using namespace std;

int main(){
	string c00,c01,c02,c03,c10,c11,c12,c13,c20,c21,c22,c23,c30,c31,c32,c33;
	cin >> c00 >> c01 >> c02 >> c03;
	cin >> c10 >> c11 >> c12 >> c13;
	cin >> c20 >> c21 >> c22 >> c23;
	cin >> c30 >> c31 >> c32 >> c33;
	
	string c0[4] = {c00, c01, c02, c03};
	string c1[4] = {c10, c11, c12, c13};
	string c2[4] = {c20, c21, c22, c23};
	string c3[4] = {c30, c31, c32, c33};

	string tmp;

	// for (int i = 0; i < 4; ++i)
	// {
	tmp = c0[0];
	c0[0] = c3[3];
	c3[3] = tmp;
	tmp = c0[1];
	c0[1] = c3[2];
	c3[2] = tmp;
	tmp = c0[2];
	c0[2] = c3[1];
	c3[1] = tmp;
	tmp = c0[3];
	c0[3] = c3[0];
	c3[0] = tmp;
	
	tmp = c1[0];
	c1[0] = c2[3];
	c2[3] = tmp;
	tmp = c1[1];
	c1[1] = c2[2];
	c2[2] = tmp;
	tmp = c1[2];
	c1[2] = c2[1];
	c2[1] = tmp;
	tmp = c1[3];
	c1[3] = c2[0];
	c2[0] = tmp;

 	for (int i = 0; i < 3; ++i)
 	{
		cout << c0[i] << ' ';
 	}
 	cout << c0[3] << endl;

	for (int i = 0; i < 3; ++i)
 	{
		cout << c1[i] << ' ';
 	}
 	cout << c1[3] << endl;

	for (int i = 0; i < 3; ++i)
 	{
		cout << c2[i] << ' ';
 	}
 	cout << c2[3] << endl;

	for (int i = 0; i < 3; ++i)
 	{
		cout << c3[i] << ' ';
 	}

 	cout << c3[3] << endl;


}