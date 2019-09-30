#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#define mk(a,b) make_pair(a,b)
using namespace std;
typedef long long int lli;
     
typedef pair<lli,lli> pii;
     
const lli INF=1LL<<60;
     
struct Edge{
  int type;
  lli Acost;
  lli Bcost;
  int from;
  int to;
  Edge(int t,int f,int _to):type(t),Acost(0),Bcost(0),from(f),to(_to){}
  Edge(int t,lli Ac,lli Bc,int f,int _to):type(t),Acost(Ac),Bcost(Bc),from(f),to(_to){}
  Edge(){}
};
     
bool operator>(Edge e1,Edge e2){
  if(e1.Bcost != e2.Bcost) return (e1.Bcost > e2.Bcost);
  else return (e1.Acost > e2.Acost);
}
     
typedef vector<Edge> Edges;
     
int main(){
  int N,M;
  cin>>N>>M;
  vector<Edges> G(N);
  for(int i=0;i<M;i++){
    int C,A,B;
    cin>>C>>A>>B;
    G[A].push_back(Edge(C,A,B));
    G[B].push_back(Edge(C,B,A));
  }
  vector<lli> nlist(N,INF);
  priority_queue<Edge,vector<Edge>,greater<Edge> > pq;
  pq.push(Edge(0,0,0));
  while(pq.size()){
    Edge edge = pq.top();
    pq.pop();
    if(edge.Acost > nlist[edge.to]) continue;
    nlist[edge.to]=edge.Acost;
    for(int i=0;i<G[edge.to].size();i++){
      Edge &e=G[edge.to][i];
      if(e.type == 0){
	if(nlist[e.to] > nlist[e.from]+1 )
	  pq.push(Edge(0,nlist[e.from]+1,edge.Bcost,e.from,e.to));
      }else{
	if(nlist[e.to] > nlist[e.from]+edge.Bcost + 1)
	  pq.push(Edge(1,nlist[e.from]+edge.Bcost+1,edge.Bcost+1,e.from,e.to));
      }   
    }
  }
  for(int i=0;i<N;i++) cout<<nlist[i]<<endl;
  return 0;
}