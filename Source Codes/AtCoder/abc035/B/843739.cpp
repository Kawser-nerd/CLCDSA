#include <iostream>
#include <climits>
#include <array>
#include <cmath>
#include <vector>
#include <complex>

using namespace std;

#define MODULE 1000000007
#define MP make_pair

typedef pair<int, int> P;
typedef long long LL;
const int MAXWH = 1000;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

//-----Template---------
string s;
int t;
int i,j,q;

int main()
{
	std::cin >> s;
	std::cin >> t;
	i = 0, j = 0, q = 0;

	for(auto itr=s.begin();itr!=s.end();++itr) {
		switch (*itr)
		{
		case 'L':
			i--;
			break;
		case 'R':
			i++;
			break;
		case 'U':
			j++;
			break;
		case 'D':
			j--;
			break;
		case '?':
			q++;
			default:
			break;
		}
	}

	int resTmp = abs(i) + abs(j);
	if(t==1)
	{
		cout << resTmp + q << endl;
	}
	else
	{
		resTmp -= q;
		if(resTmp>=0)
		{
			cout << resTmp << endl;
		}else
		{
			cout << abs(resTmp) % 2 << endl;
		}
	}

	
	return 0;
}