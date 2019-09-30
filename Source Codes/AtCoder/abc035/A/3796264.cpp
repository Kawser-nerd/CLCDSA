#include <iostream>
using namespace std;

int main()
{
	int w, h; cin >> w >> h;
	if(w/4 == h/3) {
		cout << "4:3\n";
	} else {
		cout << "16:9\n";
	}
}