#include <iostream>
#include <string>
using namespace std;
int main()
{
	string w;
	cin >> w;
	for(int i=0;i<w.size();i++){
		if(w[i] != 'a' && w[i] != 'i' && w[i] != 'u' && w[i] != 'e' && w[i] != 'o')
		{cout << w[i];}
	}
	cout << endl;
	return 0;
}