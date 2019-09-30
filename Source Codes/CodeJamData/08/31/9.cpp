#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main ()
{
	int tests = 0;
	fin >> tests;

	while (tests -- > 0)
	{

		int p, k, l;

		fin >> p >> k >> l;

		vector <pair<int, int> > all;

		for (int i = 0; i < l; ++ i)
		{
			pair<int, int> curr;
			fin >> curr.first;
			curr.second = i;
			all.push_back(curr);
		}

		sort (all.begin(), all.end());

		long long res = 0;
		for (int i = 0; i < l; ++ i)
			res += (long long )((l - i - 1) / k + 1) * (long long ) all[i].first;

		static int caseNum = 0;
		fout << "Case #" <<  (++ caseNum) << ": " << res << endl;
	}

	return 0;
}