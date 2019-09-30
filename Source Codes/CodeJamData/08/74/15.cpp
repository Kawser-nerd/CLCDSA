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

bool burned[8][8];


template <class T> string to_str(const T& t) {
    stringstream stream; stream << t; return stream.str();
}

int dl[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dc[] = {1, 1, 1, 0, -1, -1, -1, 0};

int R, C;
bool ganha(int l, int c) {

	bool resp = false;
	burned[l][c]=true;
	for(int i=0;i<8;++i) {
		int l2 = l + dl[i];
		int c2 = c + dc[i];
		if(l2<0 or c2 <0 or l2>=R or c2>=C)
			continue;
		if(burned[l2][c2]) continue;
		if(not ganha(l2, c2)) {
			resp=true;
			break;
		}
	}
	burned[l][c]=false;
	return resp;
}


int main(void) {
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;++t) {


		memset(burned, 0, sizeof(burned));


		scanf("%d%d", &R, &C);

		int l, c;
		for(int i=0;i<R;++i) {
			char tmp[8];
			scanf("%s", tmp);
			for(int j=0;j<C;++j) {
				burned[i][j] = (tmp[j]=='#');
				if(tmp[j]=='K') {
					l=i; c=j;
				}
			}
		}


        printf("Case #%d: %s\n", t, ganha(l, c)?"A":"B");
        fflush(stdout);
    }
    return 0;
}
