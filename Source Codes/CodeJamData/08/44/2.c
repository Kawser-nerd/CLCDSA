#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int i,j;
	int K;
	string s;

	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> K;
		cin >> s;
//		cout << K << ' ' << s << endl;
		vector<int> per;
		for(i=0; i<K; i++) per.push_back(i);
		int r = 1000000;
		do{
			string ss = "";
			for(i=0; i<s.size(); i++)
			{
				int a = i/K; int b = i%K;
				ss = ss + s[a*K + per[b]];
			}
//			cout << ss << endl;
			int count = 0;
			for(i=0; i<ss.size(); i++)
			{
				for(j=i+1; j<ss.size(); j++)
					if (ss[j] != ss[i])
						break;
				count++;
				i = j-1;
			}
			if (count < r) r = count;
		}while(next_permutation(per.begin(), per.end()));
		printf("Case #%d: %d\n", cc, r);
	}
}
