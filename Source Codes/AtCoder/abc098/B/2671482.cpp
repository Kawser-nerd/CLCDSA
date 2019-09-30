#include <iostream>
#include <string>
#include <algorithm>
#define REF(n, m) for(int j = n; j < m; j++)

int main()
{
	int a, count, max = 0;
	std::string b;
	std::cin >> a >> b;
	for(int i = 1; i < a; i++)
	{
		count = 0;		
		for(char c = 'a'; c <= 'z'; c++)
		{
			bool left = false, right = false;
			REF(0, i)
			{
				if(b[j] == c)
					left = true;
			}
			REF(i, a)
			{
				if(b[j] == c)
					right = true;
			}
			if(left && right)
				count++;
		}
		if(max < count)
			max = count;
	}
	std::cout << max << std::endl;
}