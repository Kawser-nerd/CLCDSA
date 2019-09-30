#include <iostream>
using namespace std;
int main()
{
	int w, a, b;
	cin >> w >> a >> b;
	if (b - (a + w)>0)
    cout<< b - (a + w);
	else if ((b + w) >= a) cout << "0";
	else cout <<a - (b + w);
	cout << endl;
	return 0;
}