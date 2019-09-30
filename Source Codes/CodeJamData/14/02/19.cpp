// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#define dibs reserve
#define OVER90000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.rbegin(); LIE != CAKE.rend(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int t =0; t < T; t++) {
		double C,F,X;
		cin >> C >> F >> X;
		double ans =X/2;
		double tt =0, r =2;
		while(tt < ans-soclose) {
			tt +=C/r;
			r +=F;
			ans =min(ans,X/r+tt);}
		cout << "Case #" << t+1 << ": " << fixed << setprecision(9) << ans << "\n";}
	return 0;}
	
// look at my code
// my code is amazing