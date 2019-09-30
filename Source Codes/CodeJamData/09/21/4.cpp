#include <cstdio>
#include <set>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 100100;

int n;
int ls[MAX], rs[MAX];
char leaf[MAX];
string feat[MAX];
double prob[MAX];

inline bool is_space(char ch){
  return ((ch==' ') || (ch=='\n') || (ch=='\t'));
}

void parse(int v, const string & str, int & pos){
  n++;
  while (str[pos] != '(') pos++;
  pos++;
  while (is_space(str[pos])) pos++;
  int flen=0;
  char fnum[20];
  while (!is_space(str[pos]) && str[pos]!=')'){
    fnum[flen++] = str[pos++];
  }
  fnum[flen] = 0;
  sscanf(fnum, "%lf", &prob[v]);
  while (is_space(str[pos])) pos++;
  leaf[v] = 1;
  if (str[pos] != ')'){
    leaf[v] = 0;
    feat[v] = "";
    while (!is_space(str[pos])){
      feat[v] += str[pos++];
    }
    ls[v] = n+1;
    parse(n+1, str, pos);
    rs[v] = n+1;
    parse(n+1, str, pos);
    while (str[pos] != ')') pos++;
  }
  pos++;
}

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int tn, t;
  scanf("%d\n", &tn);
  for (t=1; t<=tn; t++){
    printf("Case #%d:\n", t);
    int L;
    scanf("%d", &L);
    char str[110];
    gets(str);
    string tree = "";
    for (int i=0; i<L; i++){
      gets(str);
      tree += string(str);
      tree += ' ';
    }
    n = 0;
    int pos = 0;
    parse(1, tree, pos);
    /*printf("%d\n", n);
    for (int i=1; i<=n; i++){
      printf("%d %d %d %lf %s\n", leaf[i], ls[i], rs[i], prob[i], feat[i].c_str());
    }*/
    int m;
    scanf("%d\n", &m);
    for (int i=0; i<m; i++){
      int k;
      scanf("%s%d", str, &k);
      set<string> S;
      for (int j=0; j<k; j++){
        scanf("%s", str);
        S.insert(string(str));
      }
      int cv = 1;
      double res = prob[1];
      while (!leaf[cv]){
        if (S.find(feat[cv]) != S.end()){
          cv = ls[cv];
        }
        else{
          cv = rs[cv];
        }
        res *= prob[cv];
      }
      printf("%.7lf\n", res);
    }
  }
  return 0;
}
