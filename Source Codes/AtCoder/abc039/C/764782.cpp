#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char ** argv) {

	string S;
	cin >> S;


	while (1) {

		string pa = "WBWWBWBWB";
		size_t Bh = S.find(pa);
		if (Bh == string::npos) break;
		S.erase(S.begin() + Bh, S.begin() + S.length());
	}

	int count = 0;
	while (1) {

		size_t Wn = S.find('W');
		if (Wn == string::npos) break;
		S.erase(S.begin() + Wn, S.begin() + Wn + 1);
		count++;
	}

	switch (count) {
	case 1:
		cout << "Do" << endl;
		break;
	case 2:
		cout << "Si" << endl;
		break; 
	case 3:
		cout << "La" << endl;
		break;
	case 4:
		cout << "So" << endl;
		break;
	case 5:
		cout << "Fa" << endl;
		break;
	case 6:
		cout << "Mi" << endl;
		break;
	case 0:
		cout << "Re" << endl;
		break;
	}
}