#include<iostream>
using namespace std;

int main()
{
	int n,j = 0,l = 0;
	cin >> n;
	int* a = new int[n];
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		if(a[i] % 2 == 1)
		j++;
		if(a[i] % 4 == 0)
		l++;
	}
	if(l >= j || l >= n / 2)
	cout << "Yes" << endl;
    else
    cout << "No" <<endl;
    delete []a;
    return 0;
}