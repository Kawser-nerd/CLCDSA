#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<iterator>
#include<stack>
#include<string>
#include<climits>
#include<bitset>
#include<queue>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<sstream>

#define MOD 1000000007
#define ll long long int
#define vi vector<int>
#define vl vector<long long int>
#define vvi vector<vector<int> >
#define vvl vector<vector<long long int> >
#define vp vector<pair<int, int> >
#define sc(n) scanf("%d", &n)
#define ssync ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

vi subtreesize;
bool *visited;

string toBin(long long int a)
{
	return bitset<64>(a).to_string();
}

void printArr(int* a, int n)
{
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

string intToString (ll a)
{
	ostringstream temp;
	temp<<a;
	return temp.str();
}

ll pow(ll base, ll exponent)
{
	ll result = 1;
	while(exponent > 0)
	{
		if (exponent % 2 == 1)
			result *= base;
		exponent = exponent >> 1;
		base *= base;
	}
	return result;
}

ll powerWithMod(ll base, ll exponent, ll modulus)
{
	ll result = 1;
	base %= modulus;
	while(exponent > 0)
	{
		if (exponent % 2 == 1)
			result = (result * base) % modulus;
		exponent = exponent >> 1;
		base = (base * base) % modulus;
	}
	return result;
}

class tree
{
	public:
		int n;
		vvi adjlis;

		tree(int a)
		{
			n = a;
			vi temp;
			for(int i=0; i<n; i++)
				adjlis.push_back(temp);
		}

		void addedge(int node1, int node2)
		{
			adjlis[node1-1].push_back(node2-1);
			adjlis[node2-1].push_back(node1-1);
		}
};

void ssize(tree& a, int curr)
{
	for(int i=0; i < a.adjlis[curr].size(); i++)
	{
		if(!visited[a.adjlis[curr][i]])
		{
			visited[a.adjlis[curr][i]] = true;
			ssize(a, a.adjlis[curr][i]);
			subtreesize[curr] += subtreesize[a.adjlis[curr][i]];
		}
	}
}

int main()
{
	ssync;
	ll n, x;
	cin>>n>>x;
	cout << (ll)3 * (n - __gcd(n, x)) << "\n";
	return 0;
}