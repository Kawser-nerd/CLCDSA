#include <iostream>

using namespace std;


int main(void)
{
	int N;

	cin >> N;
	if(N % 2)
	{
		cout << "Hello World" << endl;
	}
	else
	{
		int A, B;
		cin >> A >> B;
		cout << A + B << endl;
	}

	return 0;
}