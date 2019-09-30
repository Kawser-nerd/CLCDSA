#include <iostream>                                                 //Include Libraries
#include <string>                                                   //Include Libraries
#include <vector>                                                   //Include Libraries
using namespace std;                                                //Bad practice


int main(int argc, char const *argv[]) {
	

	string Data;
	cin >> Data;

	bool IsPossible = true;

	if (Data.find("N") != string::npos and Data.find("S") == string::npos)
		IsPossible = false;

	if (Data.find("S") != string::npos and Data.find("N") == string::npos)
		IsPossible = false;

	if (Data.find("E") != string::npos and Data.find("W") == string::npos)
		IsPossible = false;

	if (Data.find("W") != string::npos and Data.find("E") == string::npos)
		IsPossible = false;

	if (IsPossible) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}