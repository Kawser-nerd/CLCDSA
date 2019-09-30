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
// BEGIN CUT HERE
#define DEBUG(var) { cout << #var << ": " << (var) << endl; }
template <class T> ostream& operator << (ostream &os, const vector<T> &temp) { os << "[ "; for (unsigned int i=0; i<temp.size(); ++i) os << (i?", ":"") << temp[i]; os << " ]"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const set<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class T> ostream& operator << (ostream &os, const multiset<T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (*it); os << " }"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const pair<S,T> &a) { os << "(" << a.first << "," << a.second << ")"; return os; } // DEBUG
template <class S, class T> ostream& operator << (ostream &os, const map<S,T> &temp) { os << "{ "; for(__typeof((temp).begin()) it=(temp).begin();it!=(temp).end();++it) os << ((it==(temp).begin())?"":", ") << (it->first) << "->" << it->second; os << " }"; return os; } // DEBUG
// END CUT HERE
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define FOREACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
// }}}

/////////////////// CODE WRITTEN DURING THE COMPETITION FOLLOWS ////////////////////////////////

char images[26][3] = {
"a4",
"b8",
"c",
"d",
"e3",
"f",
"g9",
"h",
"i1",
"j",
"k",
"l",
"m",
"n",
"o0",
"p",
"q",
"r",
"s5",
"t7",
"u",
"v",
"w",
"x",
"y",
"z" };

long long transition_cost(const string &A, const string &B) {
    for (int n=1; n<=int(A.size()); ++n) if (string(A.begin()+n,A.end()) == string(B.begin(),B.end()-n)) return n;
}

template<class T, class U> 
class MincostMaxflow {
  public:
  class edge { 
    public:
      int source, destination;
      T capacity, residue;
      U cost;
      edge(int s, int d, T cap, T res, U cost) 
        : source(s), destination(d), capacity(cap), residue(res), cost(cost) { }
  };

  vector< vector<int> > V;
  vector<edge> E;
  void clear();
  void addArc(int source, int destination, T capacity, U cost);
  pair<T,U> getFlow(int source, int sink);
};

template<class T, class U> void MincostMaxflow<T,U>::clear() { V.clear(); E.clear(); }

template<class T, class U> 
void MincostMaxflow<T,U>::addArc(int source, int destination, T capacity, U cost) {
    // cout << "addArc " << source << " " << destination << " " << capacity << " " << cost << endl;
  int e = E.size();
  if (source >= int(V.size())) V.resize(source+1);
  if (destination >= int(V.size())) V.resize(destination+1);
  V[source].push_back( e );
  V[destination].push_back( e+1 );
  E.push_back(edge(source,destination,capacity,capacity,cost));
  E.push_back(edge(destination,source,capacity,0,-cost));
}

template<class T, class U> 
pair<T,U> MincostMaxflow<T,U>::getFlow(int source, int sink) {
  if (source >= int(V.size())) V.resize(source+1);
  if (sink >= int(V.size())) V.resize(sink+1);

  int N = V.size(), M = E.size();
  T flowSize = 0;
  U flowCost = 0;
  T Tinfinity = 1; while (2*Tinfinity > Tinfinity) Tinfinity *= 2; 
  U Uinfinity = 1; while (2*Uinfinity > Uinfinity) Uinfinity *= 2;
  U Uepsilon = 1; for (int i=0; i<30; i++) Uepsilon /= 2;
  vector<T> flow(M,0);
  vector<U> potential(N,0);
  while (1) {
    // use dijkstra to find an augmenting path
    vector<int> from(N,-1);
    vector<U> dist(N,Uinfinity);
    
    priority_queue< pair<U,int>, vector<pair<U,int> >, greater<pair<U,int> > > Q;
    Q.push(make_pair(0,source));
    from[source]=-2; 
    dist[source] = 0;

    while (!Q.empty()) {
      U howFar = Q.top().first; 
      int where = Q.top().second;
      Q.pop();
      if (dist[where] < howFar) continue;

      for (int i=0; i<int(V[where].size()); i++) {
        if (E[ V[where][i] ].residue == 0) continue;
        int dest = E[ V[where][i] ].destination;
        U cost = E[ V[where][i] ].cost;
        if (dist[dest] > dist[where] + potential[where] - potential[dest] + cost + Uepsilon) {
          dist[dest] = dist[where] + potential[where] - potential[dest] + cost;
          from[dest] = V[where][i];
          Q.push( make_pair( dist[dest],dest ));
        }
      }
    }

    // update vertex potentials
    for (int i=0; i<N; i++) {
      if (dist[i]==Uinfinity) potential[i] = Uinfinity;
      else if (potential[i]<Uinfinity) potential[i] += dist[i];
    }

    // if there is no path, we are done
    if (from[sink] == -1) return make_pair(flowSize,flowCost);

    // construct an augmenting path
    T canPush = Tinfinity;
    int where = sink;

    while (1) { 
      if (from[where]==-2) break;
      canPush = min(canPush, E[ from[where] ].residue );
      where = E[ from[where] ].source;
    }

    // update along the path
    where = sink;
    while (1) { 
      if (from[where]==-2) break;
      E[ from[where] ].residue -= canPush;
      E[ from[where]^1 ].residue += canPush;
      flowCost += canPush * E[ from[where] ].cost;
      where = E[ from[where] ].source;
    }
    flowSize += canPush;
  }
  return make_pair(-1,47);
}

int main() {
    int T; cin >> T;
    FOR(t,1,T) {
        int K; cin >> K;
        string S; cin >> S;
        int N = S.size();

        set<string> edges;
        for (int n=0; n+K<=N; ++n) edges.insert( string( S.begin()+n, S.begin()+n+K ) );
        //DEBUG(edges);

        string startv(S.begin(), S.begin()+K-1);
        string endv(S.end()-(K-1), S.end());

        map< string, long long > DEG;

        long long celkovo_hran = 0;
        FOREACH(it,edges) {
            string E = *it;
            long long vrcholov = 1;
            for (int k=0; k<K-1; ++k) vrcholov *= strlen(images[ E[k]-'a' ]);
            long long hran = vrcholov * strlen(images[ E[K-1]-'a' ]);
            celkovo_hran += hran;

            DEG[ string(E.begin(),E.end()-1) ] -= strlen(images[ E[K-1]-'a' ]);
            DEG[ string(E.begin()+1,E.end()) ] += strlen(images[ E[0]-'a' ]);
        }
  
        vector< pair<string,long long> > VON,DNU;
        map<string,int> ID;
        int next_id = 3;

        long long add = 0;
        FOREACH(it,DEG) {
            long long x = it->second;
            if (x==0) continue;

            string V = it->first;
            if (!ID.count(V)) { ID[V]=next_id; ++next_id; }
            long long mul = 1;
            for (int k=0; k<K-1; ++k) mul *= strlen(images[ V[k]-'a' ]);
            if (x > 0) {
                VON.push_back(make_pair(V,x*mul));
                add += x*mul; 
            } else DNU.push_back(make_pair(V,-x*mul));
        }
        
        if (add == 0) {
            cout << "Case #" << t << ": " << (celkovo_hran+K-1) << endl;
            continue;
        }
        /*
        DEBUG(celkovo_hran);
        DEBUG(add);
        DEBUG(VON); DEBUG(DNU);
        DEBUG(transition_cost("abcde","cdefg"));
        */

        MincostMaxflow<long long,long long> MF;
        MF.addArc(0,1,add-1,0);
        FOREACH(it,VON) MF.addArc(1,ID[it->first],it->second,0);
        FOREACH(jt,DNU) MF.addArc(ID[jt->first],2,jt->second,0);
        FOREACH(it,VON) FOREACH(jt,DNU) MF.addArc(ID[it->first],ID[jt->first],min(it->second,jt->second),transition_cost(it->first,jt->first));

        pair<long long, long long> result = MF.getFlow(0,2);
        // DEBUG(result);
        assert( result.first == add-1 );

        cout << "Case #" << t << ": " << (celkovo_hran+result.second+K-1) << endl;
    }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
