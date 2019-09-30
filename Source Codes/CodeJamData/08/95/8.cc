#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
#include <glpk.h> // http://www.gnu.org/software/glpk/
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORI(i,v) FOR(i,(int)v.size())
#define BEND(v) v.begin(),v.end()
#define dump(x) cerr << #x << " = " << (x) << endl;
typedef long long ll; typedef long double ld;

const int inf = 123456789;
int dr[] = {0,1}, dc[]={1,0};
int cas = 0;
int N,M;
char grid[50][50];
int VERT(int r, int c) {
  return r*M+c+1;
}
void doit() {
  scanf("%d%d",&N,&M);

  FOR(i,N) FOR(j,M) {
    scanf(" %c",&grid[i][j]);
  }

  const size_t MAX_ASZ = 3*4*2500;
  int NROWS = 2*N*M - N - M;
  int NCOLS = N*M + NROWS;
  size_t ASZ = 3*NROWS;
  int ia[1+MAX_ASZ], ja[1+MAX_ASZ];
  double ar[1+MAX_ASZ];

  glp_prob *lp = glp_create_prob();
  glp_set_prob_name(lp, "E");
  glp_set_obj_dir(lp, GLP_MAX);

  if (NROWS) glp_add_rows(lp, NROWS);
  glp_add_cols(lp, NCOLS);

  int cur = 1;
  FOR(r,N) FOR(c,M) {
    glp_set_obj_coef(lp, VERT(r,c), 4);
    glp_set_col_bnds(lp, VERT(r,c), GLP_DB, 0, 1);
    if (grid[r][c] == '#') glp_set_col_bnds(lp, VERT(r,c), GLP_FX, 1, 1);
    if (grid[r][c] == '.') glp_set_col_bnds(lp, VERT(r,c), GLP_FX, 0, 0);
    FOR(k,2) {
      int r2 = r+dr[k], c2 = c+dc[k];
      if (r2 < 0 || r2 >= N || c2 < 0 || c2 >= M) continue;

      glp_set_row_bnds(lp, cur, GLP_UP, 0.0, 1.0);

      int ei = cur+N*M;

      ia[cur*3-2] = ia[cur*3-1] = ia[cur*3] = cur;
      ja[cur*3-2] = VERT(r,c);
      ja[cur*3-1] = VERT(r2,c2);
      ja[cur*3] = ei;

      ar[cur*3-2] = 1;
      ar[cur*3-1] = 1;
      ar[cur*3] = -1;

      glp_set_col_bnds(lp, ei, GLP_DB, 0, 1);
      glp_set_obj_coef(lp, ei, -2);

      cur++;
    }
  }
  assert(cur == NROWS+1);

  glp_load_matrix(lp, ASZ, ia, ja, ar);

  glp_smcp parm;
  glp_init_smcp(&parm);
  parm.msg_lev = GLP_MSG_OFF;
  assert(0 == glp_simplex(lp, &parm));

  int status = glp_get_status(lp);

  assert(status == GLP_OPT);

/*
  dump(glp_get_col_prim(lp,2));
  dump(glp_get_col_prim(lp,3));
  dump(glp_get_col_prim(lp,4));*/
  printf("Case #%d: %.0lf\n",++cas,glp_get_obj_val(lp));
  cerr << "ding" << endl;

  glp_delete_prob(lp);
}
int T;
int main() {
scanf("%d",&T);
FOR(i,T)doit();
}
