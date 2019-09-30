#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define MOD 1000000007

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		map<string,int> seen;
		int flag[300], flagin[300];
		for(i='a'; i<='z'; i++)
			flag[i] = flagin[i] = 0;
		int N;
		cin >> N;
		int fail = 0;
		for(i=0; i<N; i++)
		{
			string s;
			cin >> s;
//			cout << s << ' ';
			if (s.size() > 2)
			{
				string ss = "";
				for(j=0; j<s.size(); j++)
				{
					for(k=j+1; k<s.size(); k++)
						if (s[k] != s[j])
							break;
					ss += s[j];
					j = k-1;
				}
				s = ss;
			}
			if (s.size() == 1)
			{
				if (flagin[s[0]])
					fail = 1;
				seen[s+s]++;
			}
			else if (s.size() == 2)
			{
				if (flagin[s[0]] || flagin[s[1]])
					fail = 1;
				seen[s]++;
			}
			else
			{
				if (flagin[s[0]] || flagin[s[s.size()-1]])
					fail = 1;
				if (s[0] == s[s.size()-1])
					fail = 1;
				flag[s[0]] = 1;
				flag[s[s.size()-1]] = 1;
				for(j=1; j<s.size()-1; j++)
				{
					if (flag[s[j]])
						fail = 1;
					flag[s[j]] = 1;
				}
				string ss = "";
				ss.push_back(s[0]);
				ss.push_back(s[s.size()-1]);
				seen[ss]++;
			}
			for(j=0; j<s.size(); j++)
			{
				flag[s[j]] = 1;
				if (j != 0 && j != s.size()-1)
					flagin[s[j]] = 1;
			}
		}
//		cout << endl;
		if (fail)
		{
			printf("Case #%d: 0\n", cc);
			continue;
		}
		long long r = 1;
		vector<string> vv;
		for(map<string,int>::iterator p = seen.begin(); p != seen.end(); p++)
		{
			string s = p->first;
			if (s[0] == s[1])
			{
				int n = p->second;
				for(i=1; i<=n; i++)
					r = (r*i)%MOD;
				vv.push_back(s);
			}
			else
			{
				if (p->second > 1)
				{
					goto fail;
				}
				vv.push_back(s);
			}
		}
//			for(i=0; i<vv.size(); i++)
//				cout << vv[i] << ' ';
//			cout << endl;


		for(i=0; i<vv.size(); i++)
		{
			if (vv[i][0] == vv[i][1])
				continue;
			int c = 0;
			for(j=0; j<vv.size(); j++)
			{
				if (j == i) continue;
				if (vv[j][0] == vv[i][1] && vv[j][0] != vv[j][1])
					c++;
			}
			if (c > 1) goto fail;
			c = 0;
			for(j=0; j<vv.size(); j++)
			{
				if (j == i) continue;
				if (vv[j][1] == vv[i][0] && vv[j][0] != vv[j][1])
					c++;
			}
			if (c > 1) goto fail;
		}

		while(1)
		{
//			for(i=0; i<vv.size(); i++)
//				cout << vv[i] << ' ';
//			cout << endl;
			string a,b;
			int f = 0;
			for(i=0; i<vv.size(); i++) for(j=i+1; j<vv.size(); j++)
			{
				if (!(vv[i][0] == vv[i][vv[i].size()-1] || vv[j][0] == vv[j][vv[j].size()-1]))
					continue;
				if (vv[i][0] == vv[j][vv[j].size()-1])
				{
					a = vv[j]; b = vv[i];
					f = 1;
				}
				if (vv[i][vv[i].size()-1] == vv[j][0])
				{
					a = vv[i]; b = vv[j];
					f = 1;
				}
			}
			if (!f) break;
			vector<string> t;
			for(i=0; i<vv.size(); i++)
				if (!(vv[i] == a || vv[i] == b))
					t.push_back(vv[i]);
			t.push_back(a+b);
			vv = t;
		}

		while(1)
		{
//			for(i=0; i<vv.size(); i++)
//				cout << vv[i] << ' ';
//			cout << endl;
			string a,b;
			int f = 0;
			for(i=0; i<vv.size(); i++) for(j=i+1; j<vv.size(); j++)
			{
				if (vv[i][0] == vv[j][vv[j].size()-1])
				{
					a = vv[j]; b = vv[i];
					f = 1;
				}
				if (vv[i][vv[i].size()-1] == vv[j][0])
				{
					a = vv[i]; b = vv[j];
					f = 1;
				}
			}
			if (!f) break;
			vector<string> t;
			for(i=0; i<vv.size(); i++)
				if (!(vv[i] == a || vv[i] == b))
					t.push_back(vv[i]);
			t.push_back(a+b);
			vv = t;
		}
		int flag2[300];
		for(i='a'; i<='z'; i++) flag2[i] = 0;

//		for(i=0; i<vv.size(); i++)
//				cout << vv[i] << ' ';
//			cout << endl;

		for(i=0; i<vv.size(); i++)
		{
			string s = vv[i];
			for(j=0; j<s.size(); j++)
			{
				if (flag2[s[j]]) goto fail;
				for(k=j+1; k<s.size(); k++)
					if (s[j] != s[k])
						break;
				flag2[s[j]] = 1;
				j = k-1;
			}
		}

		{
				int n = vv.size();
		for(i=1; i<=n; i++)
			r = (r*i)%MOD;
		printf("Case #%d: %lld\n", cc, r);
		continue;
		}
fail:
		printf("Case #%d: 0\n", cc);
		continue;
	}
}
