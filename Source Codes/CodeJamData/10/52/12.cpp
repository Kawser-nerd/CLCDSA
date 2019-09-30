#include <iostream>
#include <queue>
using namespace std;

const int INFINITY = 100000000;
int bs[100];
int nu[100000];
int main(){
  int n2; scanf("%d", &n2);
  for (int casei = 1; casei <= n2; ++casei){
    long long l; cin >> l;
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; ++j)
      scanf("%d", &bs[j]);
    int maxb = bs[0];
    for (int j = 1; j < n; ++j)
      if (maxb < bs[j])
	maxb = bs[j];
    for (int k = 0; k < maxb; ++k)
      nu[k] = INFINITY;
    queue<pair<int, int> > q;
    nu[0] = 0;
    q.push(make_pair(0,0));
    while (!q.empty()){
      pair<int, int> qe = q.front();
      q.pop();
      if (nu[qe.first] != qe.second)
	continue;
      for (int j = 0; j < n; ++j){
	int b = bs[j];
	pair<int, int> qf;
	if (qe.first + b < maxb)
	  qf = make_pair(qe.first + b, qe.second + 1);
	else
	  qf = make_pair(qe.first + b - maxb, qe.second);
	if (qf.second < nu[qf.first]){
	  nu[qf.first] = qf.second;
	  q.push(qf);
	}
      }
    }
    printf("Case #%d: ", casei);
    long long L = l;
    int maxB = maxb;
    if (nu[(int)(L % maxB)] != INFINITY)
      cout << (L / maxB) + (nu[(int)(L % maxB)]);
    else
      cout << "IMPOSSIBLE";
    printf("\n");
  }
}


