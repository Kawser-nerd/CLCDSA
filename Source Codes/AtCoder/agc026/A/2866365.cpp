#include<iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int pv=0,v=0;
	int result = 0;
	for(int i=0;i<N;i++)
	{
		pv 	=  v;
		cin >> v;
		if(pv==v)
		{
			result++;
			v=0;
		}
	}
	cout << result << std::endl;
	return 0;
}