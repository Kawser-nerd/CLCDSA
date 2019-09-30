#include<iostream>
#include <list>
#include<stack>
#include<queue>
#include <vector>
#include <set>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include <functional>
#include<fstream>

#define FOR(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define LL long long
#define CLR(a) memset((a),0,sizeof(a))
#define SZ(x) (int((x).size()))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl
using namespace std;

const LL MOD = 1000000007;// 10^9+7
const int INF = (1 << 30);


//??
int N;
vector<LL> a;






//????
//??
void input()
{
	cin >> N;
	a.resize(N);
	REP(i, N)cin >> a[i];
}


bool all_not_positive(const vector<LL>& a)
{
	auto positive_itr = find_if(a.begin(), a.end(),
		[](const LL& num) {return num > 0; 
	});
	return positive_itr == a.end();
}

void find_best_set(const vector<LL>& a, vector<int>& bestWay, LL& highScore, int start)
{
	LL s = 0;
	vector<int> way;

	for (; start < N; start += 2) {
		if (a[start] > 0) {
			s += a[start];
			way.push_back(start);
		}

		if (s > highScore) {
			highScore = s;
			bestWay = way;
		}
	}
}

//??
void calc()
{
	LL res = 0;
	vector<int> way, use;

	//exception
	if (all_not_positive(a)) {
		res = *max_element(a.begin(), a.end());
		int id = find(a.begin(), a.end(), res) - a.begin();
		reverse(a.begin(), a.end());
		REP(i, id) {
			way.push_back(0);
			a.pop_back();
		}
		reverse(a.begin(), a.end());

		while(a.size()>1){
			way.push_back(a.size() - 1);
			a.pop_back();
		}
		goto last;
	}
		

	//normal
	REP(i, N)find_best_set(a, use, res, i);


	REP(i, use[0]) {
		way.push_back(0);
		a.pop_back();
	}
	REP(i, use.size() - 1) {
		int del = use[i + 1] - use[i];
		del /= 2;
		del--;
		REP(j, del) {
			way.push_back(2);
			a.pop_back();
			a.pop_back();
		}
		way.push_back(1);
		a.pop_back();
		a.pop_back();
	}
	while (a.size() > 1) {
		way.push_back(a.size() - 1);
		a.pop_back();
	}
	

last:;
	cout << res << endl << way.size() << endl;
	for (auto num : way) {
		cout << num + 1 << endl;
	}
}


//??
void output()
{

}


//????
void debug()
{
	int N;
	cin>>N;
}


//?????
int main()
{
	input();
	calc();
	output();
	debug();
	
	return 0;
}