#include <iostream>

int main()
{
	using namespace std;
	int x;

	cout << "";
	cin >> x;

	switch (x) {
	case 3:
	case 5:
	case 7:
		cout << "YES" << endl;
		break;
	default:
		cout << "NO" << endl;
		break;
	}
	
}