#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
using namespace std;

int A, B;
double probCorrect[100001];

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int CaseID = 1; CaseID <= TestCase; CaseID ++)
	{
		cin >> A >> B;
		for(int i = 1; i <= A; i++)
			cin >> probCorrect[i];
		double ans = 1 + B + 1;
		//cout << "@ " << ans << endl;
		double pCorrect = 1.0;
		for(int i = 0; i <= A; i++)
		{
			if(i > 0)
				pCorrect *= probCorrect[i];
			//cout << "@ " << (A-i) + (B-i) + 1 + (1.0 - pCorrect) * (B+1) << endl;
			ans = min(ans, (A-i) + (B-i) + 1 + (1.0 - pCorrect) * (B+1));
		}
		cout << "Case #" << CaseID << ": " << ans << endl;
	}
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int START_TIME = clock();
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	int RUN_RESULT = MAIN();
	//#ifdef LOCAL_TEST
	//cout << endl;
	//cout << "[Time Used] " << clock() - START_TIME << " ms." << endl;
	//#endif
	return RUN_RESULT;
}
