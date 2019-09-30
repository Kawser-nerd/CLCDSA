#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	string str;
	cin >> str;
		
	set<char> s;
	bool isdup = false;
	for( char c : str ) {
		auto r = s.insert( c );
		isdup = !r.second;
		if( isdup ) {
			break;
		}
	}

	cout << ( !isdup ? "yes" : "no" ) << endl;
	return 0;
}