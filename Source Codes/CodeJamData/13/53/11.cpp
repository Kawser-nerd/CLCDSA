/* Opgave: C */
// 7+8+7=22 includes
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>
#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm>

using namespace std;


int N,M, P;
long long A[2000];
long long B[2000];
bool inPath[2000];
int U[2000];
int V[2000];
int p[1000];
long long mat[1][1000];
long long mat2[1000][1000];


typedef pair<long long, unsigned> halfpijl; // gewicht en bestemming

vector<halfpijl> buren[1000];
vector<halfpijl> buren2[1000];
long long dist[1000];

const long long INF = 1000000000000000000LL;
bool dijkstra (unsigned s, long long d) {
        priority_queue <halfpijl,
                        vector <halfpijl>,
                        greater <halfpijl> > q;
        halfpijl cur;

        // misschien is MAX_NODES een beetje overdreven
        for (unsigned i = 0; i < N; i++) {
                dist[i] = INF;
        }

        dist[s] = d;
        q.push (make_pair (dist[s], s));

        while (!q.empty ()) {
                cur = q.top ();
                q.pop ();

                if (dist[cur.second] < cur.first) { continue; }
		if(cur.first > mat[0][cur.second]) continue;
                if (cur.second == 1) {
                        return true;
                }

                for (vector<halfpijl>::iterator it = buren[cur.second].begin ();
                     it != buren[cur.second].end ();
                     ++it) {
                        if (cur.first + it->first < dist[it->second]) {
                                dist[it->second] = cur.first + it->first;
                                q.push (make_pair (dist[it->second], it->second));
                        }
                }
        }
        return false;
}


void dijkstra2 () {
        priority_queue <halfpijl,
                        vector <halfpijl>,
                        greater <halfpijl> > q;
        halfpijl cur;

        // misschien is MAX_NODES een beetje overdreven
        for (unsigned i = 0; i < N; i++) {
                dist[i] = INF;
        }

        dist[0] = 0;
        q.push (make_pair (dist[0], 0));

        while (!q.empty ()) {
                cur = q.top ();
                q.pop ();

                if (dist[cur.second] < cur.first) { continue; }
		mat[0][cur.second] = cur.first;

                for (vector<halfpijl>::iterator it = buren2[cur.second].begin ();
                     it != buren2[cur.second].end ();
                     ++it) {
                        if (cur.first + it->first < dist[it->second]) {
                                dist[it->second] = cur.first + it->first;
                                q.push (make_pair (dist[it->second], it->second));
                        }
                }
        }
}



void doit (int t) {
  cin >> N >> M >> P;
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      mat2[i][j] = INF;
  for(int i = 0; i < N; ++i) {
    buren[i].clear();
    buren2[i].clear();
  }
  for(int i = 0; i < M; ++i) {
    long long a,b, u, v;
    cin >> u >> v >> a >> b; u--; v--;
    mat2[u][v] = min(mat2[u][v], a);
    A[i]  = a;
    B[i] = b;
    U[i] = u;
    V[i] = v;
    buren[u].push_back(make_pair(a, v));
    inPath[i] = false;
  }
  for(int j = 0; j < P; ++j) {
    cin >> p[j]; p[j]--; inPath[p[j]] = true;
  }
  for(int j = 0; j < M; ++j) {
    //if(inPath[j])
    //  buren2[U[j]].push_back(make_pair(A[j], V[j]));
    //else
      buren2[U[j]].push_back(make_pair(B[j], V[j]));
  }

  /*for(int k = 0; k < N; ++k) {
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j)
	mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
	}*/
  //cout << "dist: " << mat[0][1] << endl;


  long long d = 0;
  for(int i = 0; i < P; ++i) {
    d += A[p[i]];
    //cerr << "Try edge " << i << endl;
    buren2[U[p[i]]].push_back(make_pair(A[p[i]], V[p[i]]));
    dijkstra2();
    if(!dijkstra(V[p[i]], d)) {
      cout << "Case #" << t << ": " << (p[i] + 1) << endl;
      return;
    }
  }
  cout << "Case #" << t << ": Looks Good To Me" << endl;
}

int main () {
	int t;
	cin >> t; //scanf ("%d ", &t);
	for (int i = 0; i < t; i++) {
		doit (i+1);
	}
	return 0;
}
/* Opgave: C */
