//-----------------------------------------------------------------------------
// >>Code Template<< (for Visual C++)

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <complex>
#include <cmath>
#include <cassert>
#define  cout os
using namespace std;
typedef long long LL;
void END_OF_INPUT_FOR_THIS_TEST_CASE(); // stub for multi-threading

//-----------------------------------------------------------------------------
// >>Main<<

int calcsat(int p, int q)
{
	int sat = 0;

	p<<=1, q<<=1;
	for(int i=2,s=1; i<=q; i<<=1,++s)
		if( q & i )
			sat += 4 - ((p&i)>>s<<1) - ((q&(i>>1))>>(s-1)) - ((q&(i<<1))>>(s+1));
	return sat;
}

void case_main( ostream& os )
{
	int N,M; cin>>N>>M;
	vector<string> d(N);
	for(int y=0; y<N; ++y)
		cin >> d[y];
	END_OF_INPUT_FOR_THIS_TEST_CASE();

	set< pair<int,int> > s; // (sat, mask)
	s.insert( make_pair(0, 0) );

	for(int y=0; y<N; ++y)
	{
		typedef set< pair<int,int> > spii;
		set< pair<int,int> > s2;

		int Must=0, May=0;
		for(int x=0; x<M; ++x)
			if( d[y][x]=='#' )
				Must |= (1<<x);
			else if( d[y][x]=='?' )
				May |= (1<<x);

		for(int m=0; m<(1<<M); ++m)
			if( (m&Must)==Must && (m&(Must|May))==m )
			{
				for(spii::iterator it=s.begin(); it!=s.end(); ++it)
				{
					int sat = calcsat(it->second, m) + it->first;

					spii::iterator jt = s2.lower_bound( make_pair(sat, 0) );
					for(; jt!=s2.end(); ++jt)
						if( (jt->second & m) == jt->second )
							goto next;
					s2.insert( make_pair(sat, m) );
				next:;
				}
			}

		s.swap(s2);
	}

	os <<  s.rbegin()->first << endl;
}

//-----------------------------------------------------------------------------
// >>Code Template<< (Multi-Thread Solver)

#undef cout
#include <windows.h>
#include <process.h>

static const int THREAD_NUM = 4;
volatile int     g_id;
int              g_nCase;
CRITICAL_SECTION g_cs;
vector<string>   g_output;

unsigned __stdcall thread_main( void* t_id ) {
	for(;;) {
		EnterCriticalSection(&g_cs);
		const int id = ++g_id;
		if(id>g_nCase) { LeaveCriticalSection(&g_cs); break; }
		cerr << setw(4) << id << " @ " << (int)t_id << " start" << endl;

		ostringstream ss;
		ss << "Case #" << id << ": ";
		case_main( ss );

		EnterCriticalSection(&g_cs);
		if(g_output.size()<id) g_output.resize(id);
		g_output[id-1] = ss.str();
		cerr << setw(4) << id << " @ " << (int)t_id << " end" << endl;
		LeaveCriticalSection(&g_cs);
	}
	return 0;
}

void END_OF_INPUT_FOR_THIS_TEST_CASE() { LeaveCriticalSection(&g_cs); }

int main() {
	cin >> g_nCase;

	InitializeCriticalSection(&g_cs);
	vector<HANDLE> thread;
	for(int i=0; i<THREAD_NUM; ++i)
		thread.push_back( (HANDLE)_beginthreadex(0, 0, &thread_main, (void*)i, 0, 0) );
	WaitForMultipleObjects( thread.size(), &thread[0], TRUE, INFINITE );
	DeleteCriticalSection(&g_cs);

	copy( g_output.begin(), g_output.end(), ostream_iterator<string>(cout) );
}
