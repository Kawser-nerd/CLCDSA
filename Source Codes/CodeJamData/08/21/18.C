#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <boost/shared_ptr.hpp>

using namespace std;
using namespace boost;

//typedef map<string,string> Map;
//typedef shared_ptr<Map> MapPtr;

void add(long *v, long long x, long long y)
{
	long p = (x % 3)+9*(y%3);
	//cout << x << " " << y << " -> " << p << endl;
	v[p]+=1;
}

#define SIZE 	18+2+1

int main()
{
	long cases;
	cin >> cases;
	for (long i = 0; i<cases; ++i)
	{
		long long n, A, B, C, D, x0, y0, M;
		cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;
		long long X = x0, Y = y0;
		A = A%M;
		B = B%M;
		C = C%M;
		D = D%M;
		long v[SIZE];
		for (long k = 0; k<SIZE; ++k)
		{
			v[k] = 0;
		}
		add(v,X,Y);
		for (long j = 1; j<n; ++j)
		{
			X = (A * X + B) % M;
			Y = (C * Y + D) % M;
			//if (X<0) X+=M;
			//if (Y<0) Y+=M;
			add(v,X,Y);
		}

		long count = 0;

		for (long x = 0; x<SIZE; ++x)
		{
			if (v[x]==0) continue;
			for (long y = x; y<SIZE; ++y)
			{
				if (v[y]==0) continue;
				for (long z = y; z<SIZE; ++z)
				{
					if (v[z]==0) continue;
					long sum = x+y+z;
					if ( ((sum%3) == 0) && (((sum/9)%3)==0) )
					{
						if (x==y)
						{
							if (y==z)
							{
								count += v[x]*(v[x]-1)*(v[x]-2)/6;
							}
							else
							{
								count += v[x]*(v[x]-1)*v[z]/2;
							}
						}
						else
						{
							if (y==z)
							{
								count += v[x]*v[y]*(v[y]-1)/2;
							}
							else
							{
								count += v[x]*v[y]*v[z];
							}
						}
					}
				}
			}
		}
		cout << "Case #" << i+1 << ": " << count << endl;
	}
	return 0;
}
