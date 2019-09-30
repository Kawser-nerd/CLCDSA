#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const	int	limitSize	= 1000;
int	n;
long long	A[limitSize];
long long	B[limitSize];

void	init()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> A[i];
	for (int i = 0; i < n; i ++)
		cin >> B[i];
}

void	solve()
{
	sort(A , A + n);
	sort(B , B + n);

	long long	ret = 0;
	for (int i = 0; i < n; i ++)
		ret += A[i] * B[n - 1 - i];

	cout << ret << endl;
}

int	main()
{
	freopen("in.txt" , "r" , stdin);
	freopen("fast.txt" , "w" , stdout);

	int	t , caseNo;
	cin >> caseNo;
	for (t = 1; t <= caseNo; t ++)
	{
		
		init();

		cout << "Case #" << t << ": ";

		cerr << t << endl;

		solve();
	}

	return 0;
}