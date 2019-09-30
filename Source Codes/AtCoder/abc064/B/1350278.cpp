#include <iostream>
#include <array>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
	int N;
	array<int, 1010> a;

	cin >> N;
	for(int i = 0 ; i < N ; ++i)
		cin >> a[i];

	decltype(a.begin()) mn, mx;
	tie(mn, mx) = minmax_element(a.begin(), a.begin() + N);
	cout << (*mx - *mn) << endl;
}