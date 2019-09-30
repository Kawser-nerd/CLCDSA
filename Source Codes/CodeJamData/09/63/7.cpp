#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

#define fi first
#define se second

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)

#define MP make_pair
#define pb push_back

#define sqr(x) ((x)*(x))

const int MOD = 10007;

char a[15][15];
int m, n, finish;
int ma[26][15][200000];
int next[200000][15];
int len[200000][15];

void viet(vector<int> v) {
	cout << "[";
	for(int i=0;i<v.size();++i) cout << v[i] << " ";	
	cout << "]" << endl;
}

int solve(char pos, int last, int v) {
	// cout << (char)(pos + 'a') << " " << last << " "; viet(v);
	if(v == finish) return 1;
	if(pos >= 26) return 0;
	if(ma[pos][last][v] != -1) return ma[pos][last][v];
	int res = 0;
	res = solve( pos + 1, 0, v);
	// add pos
	for(int i=0;i<m;++i) if(next[v][i] != -1) {
		if(last <= i) {
			char c = a[i][len[v][i]];
			if(c == '.' || c == (pos + 'a')) {
				res = (res + solve( pos, i, next[v][i])) % MOD;
			}	
		}
	}
	ma[pos][last][v] = res;
	return res;
}


int* list[200000];
int nlist;
int aa[15];

bool cmp(const int *a, const int *b) {
	for(int i=0;i<m;++i) {
		if(a[i] < b[i]) return true;
		else if(a[i] > b[i]) return false;
	}
	return false;
}

void duyet(int i, int last) {
	assert(0 <= last && last <= n);
	if(i == m) {
		memmove( list[nlist], aa, sizeof(int) * m);
		nlist++;
		return;
	}
	for(int t=last;t>=0;--t) {
		aa[i] = t;
		duyet( i + 1, t);
	}
}

int main() {
	FILE * fo = fopen("out2.txt", "wt");
	int ntest;
	scanf("%d", &ntest);
	for(int i=0;i<200000;++i) list[i] = new int[13];
	
	for(int test=1;test<=ntest;++test) {
		cout << "test = " << test << endl;
		scanf("%d%d", &m, &n);
		// generate
		int tbegin = clock();
		{
			nlist = 0;
			memset( next, -1, sizeof(next));
			duyet(0, n);
			sort( list, list + nlist, cmp);
			for(int t=0;t<nlist;++t) {
				for(int i=0;i<m;++i) len[t][i] = list[t][i];
				for(int i=0;i<m;++i) {
					if((i == 0 || list[t][i] < list[t][i-1]) && list[t][i] < n) {
						int v[15];
						memmove( v, list[t], sizeof(int) * m);
						v[i]++;
						if(!binary_search( list, list + nlist, v, cmp)) {
							cout << "WRONG" << endl;	
						}
						next[t][i] = lower_bound( list, list + nlist, v, cmp) - list;
					}
				}
			}
			//cout << nlist << endl;
		}
		cout << clock() - tbegin << endl;
		// end
		
		gets(a[0]);
		for(int i=0;i<m;++i) gets(a[i]);
		
		memset( ma, -1, sizeof(ma));
		
		int cur[15];
		int endstate[15];
		for(int i=0;i<m;++i) {
			cur[i] = 0;
			endstate[i] = n;
		}
		if(!binary_search(list, list + nlist, endstate, cmp)) cout << "WRONG" << endl;
		finish = lower_bound( list, list + nlist, endstate, cmp) - list;
		int start = lower_bound( list, list + nlist, cur, cmp) - list;
		int res = solve(0, 0, start);
		
		fprintf( fo, "Case #%d: %d\n", test, res);
		fflush(fo);
		// cout << "Case #" << test << ": " << res << endl;
	}
	fclose(fo);
	return 0;
}

