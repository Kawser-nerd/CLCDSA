/* Code written by Raphael Henrique Ribas
 * Language: C++
 * Reads input from stdin
 * Writes output to stdout
 * Best compiled with g++
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <vector>
#include <bitset>
#include <cctype>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

#define foreach(it, cont) for(typeof((cont).begin()) it = (cont).begin() ;\
        it != (cont).end(); ++it)

#define debug(x) clog << #x "=" << x << endl

#define two(x) (1ll<<(x))

using namespace std;

template <class T> string to_str(const T& t) {
    stringstream stream; stream << t; return stream.str();
}

int N;

int grafo[20000][16];
int grau[20000];

map<string, int> names;

int table[20000];

int melhor(int v) {
	if(grau[v]==0) return 0;
	if(table[v]!=-1) return table[v];
	int tmp[16];

	int k = 0;
	for(int i=0;i<grau[v];++i) {
		int t = melhor(grafo[v][i]);
		if(t==0) continue;
		tmp[k++] = t;
	}
	sort(tmp, tmp+k);
	reverse(tmp, tmp+k);

	int resp = 1;
	for(int i=0;i<k;++i) {
		resp = max(resp, tmp[i]+i);
	}
	resp = max(resp, k+1);

	return table[v] = resp;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;++t) {

		memset(grau, 0, sizeof(grau));
		memset(table, -1, sizeof(table));


		scanf("%d", &N);

		names.clear();

		int inicial=0;

		for(int i=0;i<N;++i) {
			char tmp1[32], tmp2[32];
			scanf("%s", tmp1);

			int id;
			if(names.count(tmp1)) {
				id = names[tmp1];
			} else {
				id = names.size();
				names[tmp1]=id;
			}

			scanf("%d", &grau[id]);

			for(int j=0;j<grau[id];++j) {
				scanf("%s", tmp2);
				int id2;
				if(names.count(tmp2)) {
					id2 = names[tmp2];
				} else {
					id2 = names.size();
					names[tmp2]=id2;
				}
				grafo[id][j]=id2;

			}


		}



		printf("Case #%d: %d\n", t, melhor(inicial));
		fflush(stdout);
	}
	return 0;
}
