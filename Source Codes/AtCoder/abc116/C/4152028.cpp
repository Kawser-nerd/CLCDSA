#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>	a;
	a.resize(n);
	int i, j, k;
	int result = 0;

	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	
	for (i = 0; i < n - 1; i++)
	{
		while (true)
		{
			if (a[i] > 0)
			{
				for (j = i + 1; j < n; j++)
				{
					if (a[j] <= 0)
					{
						break;
					}
				}

				for (k = i; k < j; k++)
				{
					a[k]--;
				}

				result++;
			}
          	else
            {
            	break;
            }
		}
	}

	result += a[n - 1];

	printf("%d", result);

	return 0;

}