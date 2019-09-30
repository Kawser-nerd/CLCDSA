#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Trip
{
	int dir;
	int start;
	int end;
	bool done;
	bool operator<(const Trip& o) const
	{
		return start<o.start;
	}
};
Trip trips[200];
int TRIPS;

int getnexttime()
{
	string t;
	cin >> t;
	return ((t[0]-'0')*10+t[1]-'0')*60+(t[3]-'0')*10+t[4]-'0';
}
int main()
{
	int i;
	int T;
	scanf("%d", &T);
	for(int t = 0; t<T; t++)
	{
		int turnaround;
		scanf("%d", &turnaround);
		int NA, NB;
		scanf("%d%d", &NA, &NB);
		TRIPS = 0;
		for(i = 0; i<NA; i++)
		{
			trips[TRIPS].start = getnexttime();
			trips[TRIPS].end = getnexttime();
			trips[TRIPS].done = false;
			trips[TRIPS].dir = 1;
			TRIPS++;
		}
		for(i = 0; i<NB; i++)
		{
			trips[TRIPS].start = getnexttime();
			trips[TRIPS].end = getnexttime();
			trips[TRIPS].done = false;
			trips[TRIPS].dir = 0;
			TRIPS++;
		}
		sort(trips, trips+TRIPS);
		int A = 0;
		int B = 0;
		for(i = 0; i<TRIPS; i++)
		{
			if(trips[i].done)
				continue;
			trips[i].done = true;
			if(trips[i].dir)
				A++;
			else
				B++;
			int curdir = trips[i].dir;
			int curtime = trips[i].end + turnaround;
			for(int j = i+1; j<TRIPS; j++)
			{
				if(trips[j].done)
					continue;
				if(trips[j].dir!=curdir && trips[j].start>=curtime)
				{
					curdir = !curdir;
					curtime = trips[j].end+turnaround;
					trips[j].done = true;
				}
			}
		}
		printf("Case #%d: %d %d\n", t+1, A, B);
	}
	return 0;
}
