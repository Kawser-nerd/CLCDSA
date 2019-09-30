#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,min=1000;
	cin >> n;
	vector<int> t(n);
	for(int i=0;i<n;i++){
		cin >> t[i];
		if(t[i] <= min){min = t[i];}
	}
	
	cout << min << endl;
	return 0;
}