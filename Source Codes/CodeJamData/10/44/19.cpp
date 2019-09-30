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
#include <functional>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <cstring>
#define  cout os
using namespace std;
typedef long long LL;
typedef complex<double> CMP;
void END_OF_INPUT_FOR_THIS_TEST_CASE(); // stub for multi-threading

//-----------------------------------------------------------------------------
// >>Main<<

static const double PI = atan(1.0)*4;

double solve( vector<CMP>& P, CMP Q )
{
	CMP c1 = P[0];
	CMP c2 = P[1];
	Q -= c1;
	CMP rot = (c2-c1)/abs(c2-c1);
	c2 = CMP(abs(c2-c1), 0);
	Q /= rot;

	double r1 = abs(Q);
	double r2 = abs(Q-c2);
	if(r1>r2) swap(r1,r2);
	double R = abs(c2);

	R /= r1;
	r2 /= r1;


	double cost = (r2*r2 - 1 - R*R) / (-2 * R);
	double t = abs(acos(cost));

	double sm = 1*1*t;
	double sms = -cos(t)*sin(t);

	double a = abs(arg( CMP(R-cos(t), sin(t)) ));
	double lg = r2*r2*a;
	double lgs = -r2*r2*cos(a)*sin(a);

	return (sm+sms+lg+lgs)*r1*r1;
}

void case_main( ostream& os )
{
	int N, M;
	cin >> N >> M;

	vector<CMP> P(N);
	for(int i=0; i<N; ++i)
	{
		double x, y;
		cin >> x >> y;
		P[i] = CMP(x,y);
	}
	vector<CMP> Q(M);
	for(int i=0; i<M; ++i)
	{
		double x, y;
		cin >> x >> y;
		Q[i] = CMP(x,y);
	}

	END_OF_INPUT_FOR_THIS_TEST_CASE();

	for(int i=0; i<M; ++i)
		cout << (i>0 ? " " : "") << setiosflags(ios::fixed) << setprecision(9) << solve(P, Q[i]);
	cout << endl;
}

//-----------------------------------------------------------------------------
// >>Code Template<< (Multi-Thread Solver)

#if 0
#undef cout
#include <windows.h>
#include <process.h>

static const int THREAD_NUM = 2;
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
	string dummy; getline(cin, dummy);

	InitializeCriticalSection(&g_cs);
	vector<HANDLE> thread;
	for(int i=0; i<THREAD_NUM; ++i)
		thread.push_back( (HANDLE)_beginthreadex(0, 0, &thread_main, (void*)i, 0, 0) );
	WaitForMultipleObjects( thread.size(), &thread[0], TRUE, INFINITE );
	DeleteCriticalSection(&g_cs);

	copy( g_output.begin(), g_output.end(), ostream_iterator<string>(cout) );
}

//-----------------------------------------------------------------------------
// >>Code Template<< (Single-Thread Solver)

#else
#undef cout
void END_OF_INPUT_FOR_THIS_TEST_CASE() {}
int main() {
	int nCase; cin >> nCase;
	string dummy; getline(cin, dummy);

	for(int id=1; id<=nCase; ++id) {
		cout << "Case #" << id << ": ";
		case_main( cout );
	}
}
#endif
