// another fine solution by misof
// #includes {{{
#include <algorithm>
#include <numeric>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
using namespace std;
// }}}

/////////////////// PRE-WRITTEN CODE FOLLOWS, LOOK DOWN FOR THE SOLUTION ////////////////////////////////

// pre-written code {{{
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
vector<string> SPLIT( const string& s, const string& delim =" " ) { vector<string> res; string t; for ( unsigned int i = 0 ; i != s.size() ; i++ ) { if ( delim.find( s[i] ) != string::npos ) { if ( !t.empty() ) { res.push_back( t ); t = ""; } } else { t += s[i]; } } if ( !t.empty() ) { res.push_back(t); } return res; }
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

template<class T> 
class Maxflow {
  public:
  class edge { 
    public:
      int source, destination;
      T capacity, residue;
      edge(int s, int d, T cap, T res) 
        : source(s), destination(d), capacity(cap), residue(res) { }
  };

  vector< vector<int> > V;
  vector<edge> E;
  void clear();
  void addArc(int source, int destination, T capacity);
  T getFlow(int source, int sink);
};

template<class T> void Maxflow<T>::clear() { V.clear(); E.clear(); }

template<class T> void Maxflow<T>::addArc(int source, int destination, T capacity) {
  int e = E.size();
  if (source >= int(V.size())) V.resize(source+1);
  if (destination >= int(V.size())) V.resize(destination+1);
  V[source].push_back( e );
  V[destination].push_back( e+1 );
  E.push_back(edge(source,destination,capacity,capacity));
  E.push_back(edge(destination,source,capacity,0));
}

template<class T> 
T Maxflow<T>::getFlow(int source, int sink) {
  if (source >= int(V.size())) V.resize(source+1);
  if (sink >= int(V.size())) V.resize(sink+1);

  T flowSize = 0;
  int N = V.size();

  while (1) {
    // use BFS to find augmenting paths
    vector<int> from(N,-1);
    queue<int> Q;
    Q.push(source);
    from[source]=-2;

    while (!Q.empty()) {
      int where = Q.front(); Q.pop();
      int deg = V[where].size();
      for (int i=0; i<deg; i++) {
        int dest = E[ V[where][i] ].destination;
        T res = E[ V[where][i] ].residue;
        if (from[dest] != -1) continue;
        if (res == 0) continue;
        from[dest] = V[where][i]; Q.push(dest);
        if (dest == sink) break;
      }
      if (from[sink] >= 0) break;
    }

    if (from[sink]==-1) return flowSize; // if there is no path, we are done

    // construct a maximum set of augmenting paths in the graph given by from[]
    for (int i=0; i<int(V[sink].size()); i++) {
      int where = E[ V[sink][i] ].destination;
      T res = E[ V[sink][i] ].capacity - E[ V[sink][i] ].residue;
      if (from[where]==-1) continue; // we don't have a path leading here
      if (res == 0) continue; // can't push anything more

      // walk the path and determine the delta
      T canPush = res;
      int curr = where; 
      while (1) { 
        if (from[curr]==-2) break; 
        canPush = min(canPush,E[ from[curr] ].residue);
        curr=E[ from[curr] ].source;
      }

      // walk the path again and update capacities
      flowSize += canPush;
      E[ V[sink][i] ].residue += canPush;
      E[ V[sink][i]^1 ].residue -= canPush;
      curr = where;
      while (1) { 
        if (from[curr]==-2) break; 
        E[ from[curr] ].residue -= canPush;
        E[ from[curr]^1 ].residue += canPush;
        curr=E[ from[curr] ].source;
      }
    }
  }

}

int main() {
    string line;
    getline(cin,line);
    int T;
    stringstream(line) >> T;
    FOR(test,1,T) {
        int N;
        getline(cin,line);
        stringstream(line) >> N;

        vector< vector< string > > data;
        REP(n,N) {
            getline(cin,line);
            data.push_back( SPLIT(line) ); 
        }

        map<string,int> ID;
        int W = 0;
        REP(n,N) for (auto x : data[n]) if (!ID.count(x)) ID[x] = W++;

        vector< vector<int> > words(N);
        REP(n,N) for (auto x : data[n]) words[n].push_back( ID[x] );

        Maxflow<int> MF;

        for (auto x : words[0]) MF.addArc( 0, 2*x+2, 123456789 );
        for (auto x : words[1]) MF.addArc( 2*x+3, 1, 123456789 );

        for (int w=0; w<W; ++w) MF.addArc( 2*w+2, 2*w+3, 1 );

        for (int n=2; n<N; ++n) {
            for (auto x : words[n]) MF.addArc( 2*x+3, 2*W+n, 123456789 );
            for (auto x : words[n]) MF.addArc( 2*W+n, 2*x+2, 123456789 );
        }

        cout << "Case #" << test << ": " << MF.getFlow(0,1) << endl;
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
