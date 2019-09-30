#include <iostream>
#include <string>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, m, q;
  cin >> n >> m >> q;
  vector<string> ss(n);
  for(int i = 0; i < n; ++i) cin >> ss[i];
  vvi nblue, nb_tate, nb_yoko;
  vi vzero(m+1, 0);
  nblue.push_back(vzero);
  nb_tate.push_back(vzero);
  nb_yoko.push_back(vzero);
  for(int i = 1; i < (n+1); ++i){
    nblue.push_back(nblue[i-1]);
    nb_tate.push_back(nb_tate[i-1]);
    nb_yoko.push_back(nb_yoko[i-1]);
    for(int j = 1; j < (m+1); ++j){
      nblue[i][j] += nblue[i][j-1];
      nb_tate[i][j] += nb_tate[i][j-1];
      nb_yoko[i][j] += nb_yoko[i][j-1];
      nblue[i][j] -= nblue[i-1][j-1];
      nb_tate[i][j] -= nb_tate[i-1][j-1];
      nb_yoko[i][j] -= nb_yoko[i-1][j-1];
      if(ss[i-1][j-1] == '1'){
        nblue[i][j] += 1;
        if(i != 1 and ss[i-2][j-1] == '1') nb_tate[i][j] += 1;
        if(j != 1 and ss[i-1][j-2] == '1') nb_yoko[i][j] += 1;
      }
    }
  }
  for(int i=0; i < q; ++i){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int node = nblue[x2][y2] - nblue[x1-1][y2] - nblue[x2][y1-1] + nblue[x1-1][y1-1];
    int edge = (nb_yoko[x2][y2] - nb_yoko[x1-1][y2] - nb_yoko[x2][y1] + nb_yoko[x1-1][y1]);
    edge += (nb_tate[x2][y2] - nb_tate[x1][y2] - nb_tate[x2][y1-1] + nb_tate[x1][y1-1]);
    cout << (node - edge) << endl;
  }
  return 0;
}