#include<iostream>
using namespace std;
int main()
{
	int lh, lw;
	cin >> lh >> lw;

	int sh, sw;
	cin >> sh >> sw;

	int h;
	h = ( lh - sh );
	
	int w;
	w = ( lw - sw );

	cout << ( h * w ) << endl;
	return 0;
}