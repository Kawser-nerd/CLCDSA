#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

int main(void)
{
	long int n, ice[4], ans;
	cin >> ice[0] >> ice[1] >> ice[2] >> ice[3] >> n;
	cout << n / 2 * min({ 8 * ice[0],4 * ice[1],2 * ice[2],ice[3] }) + n % 2 * min({ 4 * ice[0],2 * ice[1], ice[2] }) << endl;
	return 0;
}