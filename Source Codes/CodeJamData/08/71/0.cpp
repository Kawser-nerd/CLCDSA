#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct mixture
{
	string name;
	int numBowl;
	int numIng;
	string ings[20];
};

int numTest, numMix;
mixture mixs[2000];

int getMix(int index)
{
	int i, j;
	vector<int> results;
	for (i = 0; i < mixs[index].numIng; i++)
	{
		string toSearch = mixs[index].ings[i];
		if (toSearch[0] >= 'a' && toSearch[0] <= 'z')
			continue;
		else
		{
			for (j = 0; j < numMix; j++)
			{
				if (mixs[j].name.compare(toSearch) == 0)
				{
					results.push_back(getMix(j));
					break;
				}					
			}
		}
	}
	sort(results.begin(), results.end(), greater<int>());
	int max = 0;
	for (i = 0; i < results.size(); i++)
	{
		if (max < i + results[i])
			max = i + results[i];
	}
	if (max < results.size() + 1)
		max = results.size() + 1;
//	cout << mixs[index].name << " " << max << endl;
	return max;
}

int main()
{
	cin >> numTest;
	int i, j, k;
	for (i = 0; i < numTest; i++)
	{
		cin >> numMix;
		for (j = 0; j < numMix; j++)
		{
			cin >> mixs[j].name;
			cin >> mixs[j].numIng;
		
			for (k = 0; k < mixs[j].numIng; k++)
				cin >> mixs[j].ings[k];
		}
		
		printf("Case #%d: %d\n", i+1, getMix(0));
	}
	return 0;
}
