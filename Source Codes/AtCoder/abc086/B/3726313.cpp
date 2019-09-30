#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b;
	int digib;
	cin >> a >>b;
	if(b/100>0){digib = 3;}
	else if(b/10>0){digib = 2;}
	else{digib = 1;}
	
	
	for(int i=0;i<500;i++)
	{
		if(i*i == a*pow(10,digib)+b)
		{
			cout << "Yes" <<endl;
			return 0;
		}
	}
	
	cout << "No";
	
	return 0;
}