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

double odds[32][4];

template <class T> string to_str(const T& t) {
    stringstream stream; stream << t; return stream.str();
}

int M, Q;

double table[32][10000];
int conta[32];

double tmp[10000*4];
void most_like(int q) {
	if(q==Q) {
		table[q][0] = 1.0;
		conta[q]=1;
		return;
	}

	int k = 0;
	most_like(q+1);
	for(int i=0;i<conta[q+1];++i) {
		for(int j=0;j<4;++j) {
			tmp[k++]=odds[q][j]*table[q+1][i];
		}
	}
	sort(tmp, tmp+k);
	reverse(tmp, tmp+k);

	if(k>M) k=M;
	conta[q]=k;
	for(int i=0;i<k;++i)
		table[q][i]=tmp[i];

}

int main(void) {
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;++t) {


		scanf("%d%d", &M, &Q);
	
		for(int i=0;i<Q;++i) {
			for(int j=0;j<4;++j) {
				scanf("%lf", &odds[i][j]);
			}
		}

		long long p = 1ll<<(2*Q);

		most_like(0);

		double resp = 0.0;
		for(int i=0;i<min((long long)M, (long long)p);++i) {
			resp += table[0][i];
		}

        printf("Case #%d: %.7f\n", t, resp);
        fflush(stdout);
    }
    return 0;
}
