#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

int main()
{
	std::string s;
	cin >> s;
	int num = 0;
	auto iter1 = s.find_first_of('A');
	auto iter2 = s.find_last_of('Z');

	cout << iter2 - iter1 + 1 << endl;
	return 0;
}