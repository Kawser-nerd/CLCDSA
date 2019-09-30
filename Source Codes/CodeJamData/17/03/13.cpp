#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)
#define LOOP(i, v) for(int i = 0; i < v.size(); i++)
#define EPS 1e-9
#define INF 1e12
#define debug(x) cerr << "DEBUG : " << (#x) << " => " << (x) << endl

int main()
{
	int T;
	long long int N, K;
	
	scanf("%d\n", &T);

	REP(t, 1, T)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);
		
		cin >> N >> K;
		
		K--;
		
		long long int pow2 = 1;
		int p = 0;
		while(pow2*2 - 1 <= K)
		{
			pow2 *= 2;
			p++;
		}
		long long int M = N-(pow2-1);
		long long int a = M/pow2;
		long long int na, nb, b;
		b = a+1;
		nb = M-pow2*a;
		na = pow2-nb;
		//fprintf(stderr, "pow2 = %lld, (a, b) = (%lld, %lld), (na, nb) = (%lld, %lld)\n", pow2, a, b, na, nb);
		long long int rest = K-(pow2-1)+1;
		long long int last;
		if(rest <= nb) last = b;
		else last = a;
		if(last % 2 == 1)
		{
			cerr << last/2 << " " << last/2 << endl;
			cout << last/2 << " " << last/2 << endl;
		}
		else
		{
			cerr << last/2 << " " << last/2-1 << endl;
			cout << last/2 << " " << last/2-1 << endl;
		}
	}
	
	return 0;
}
