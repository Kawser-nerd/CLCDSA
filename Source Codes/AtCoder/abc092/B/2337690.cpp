#include<iostream>

int n,d,x;
int a[100], count = 0, s;

int main()
{
	std::cin >> n;
	std:: cin >> d >> x;
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i];
		for(int j = 0; j < 100; j++)
		{
			if(a[i] * j + 1 <= d)
			{
				count++;
			}
		}
	}
	std::cout << count + x << std::endl;
	return 0;
}