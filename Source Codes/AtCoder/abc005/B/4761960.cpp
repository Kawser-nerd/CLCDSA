#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>

int main(void) {
	int n,min,tmp;
	std::cin >> n;

	min = 1000;
	for (int i = 0; i < n; i++)
	{
		std::cin >> tmp;
		min = std::min(min, tmp);
	}

	std::cout << min << std::endl;

	system("pause");

	return 0;
}