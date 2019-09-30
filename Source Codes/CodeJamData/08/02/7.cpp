#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <boost/foreach.hpp>  // Available at: http://www.boost.org/
#define foreach BOOST_FOREACH
using namespace std;

typedef pair<int,int> Trip;   // depart, arrive
typedef pair<int,int> Result; // needed at A, needed at B
typedef pair<int,int> Event;  // time, (+1|-1)

Result solve(int T, const vector<Trip>& a2b, const vector<Trip>& b2a)
{
	vector<Event> eventA, eventB;
	foreach(Trip t, a2b)
	{
		eventA.push_back( Event(t.first,    +1) );
		eventB.push_back( Event(t.second+T, -1) );
	}
	foreach(Trip t, b2a)
	{
		eventB.push_back( Event(t.first,    +1) );
		eventA.push_back( Event(t.second+T, -1) );
	}
	sort( eventA.begin(), eventA.end() );
	sort( eventB.begin(), eventB.end() );

	int acc_a=0, max_a=0;
	foreach(Event e, eventA)
	{
		acc_a += e.second;
		max_a = max(max_a, acc_a);
	}

	int acc_b=0, max_b=0;
	foreach(Event e, eventB)
	{
		acc_b += e.second;
		max_b = max(max_b, acc_b);
	}

	return Result(max_a, max_b);
}

int main()
{
	int N; cin >> N;
	for(int pid=1; pid<=N; ++pid)
	{
		char SEMICOLON; // dummy

		int T; cin >> T;
		int NA, NB; cin >> NA >> NB;

		vector<Trip> a2b;
		while(NA--)
		{
			int dh, dm, ah, am;
			cin >> dh >> SEMICOLON >> dm >> ah >> SEMICOLON >> am;
			a2b.push_back( Trip(dh*60+dm, ah*60+am) );
		}
		vector<Trip> b2a;
		while(NB--)
		{
			int dh, dm, ah, am;
			cin >> dh >> SEMICOLON >> dm >> ah >> SEMICOLON >> am;
			b2a.push_back( Trip(dh*60+dm, ah*60+am) );
		}

		Result ab = solve(T, a2b, b2a);
		cout << "Case #" << pid << ": " << ab.first << " " << ab.second << endl;
	}
}
