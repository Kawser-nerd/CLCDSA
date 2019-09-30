#include<cstdio>
#include<iostream>
#include<glpk.h>
#include<algorithm>
using namespace std;
#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef long long int64;
main(){
  FILE *fout=fopen("output","w");
  int C,r,c,t[60][60],ans[60][60];
  scanf("%d",&C);for(int cc=1;cc<=C;cc++){
    scanf("%d %d",&r,&c);
//c=rand()%20+30;
//r=rand()%20+30;
#define nr(x,y) (x*c+y)
    FOR(i,r)FOR(j,c)scanf("%d",&t[i][j]);
/*    FOR(i,r)FOR(j,c)ans[i][j]=rand()%2;//scanf("%d",&ans[i][j]);
    FOR(x,r)FOR(y,c){
      int s=0;
	  for(int xx=max(0,x-1);xx<=min(r-1,x+1);xx++)
	  for(int yy=max(0,y-1);yy<=min(c-1,y+1);yy++)
	    s+=ans[xx][yy];
      t[x][y]=s;
    } */
    glp_prob *lp=glp_create_prob();
    glp_set_obj_dir(lp,GLP_MAX);  
    glp_add_cols(lp,r*c);
    for(int i=0; i<r*c; i++) glp_set_col_bnds(lp,1+i,GLP_DB,0,1);
    FOR(y,c)glp_set_obj_coef(lp,1+nr(r/2,y),1.);
    glp_add_rows(lp,r*c);
    FOR(x,r)FOR(y,c){
	  glp_set_row_bnds(lp,1+nr(x,y),GLP_FX,t[x][y],t[x][y]);
	  int ind[20]={},next=1;
	  double val[20]={};
	  for(int xx=max(0,x-1);xx<=min(r-1,x+1);xx++)
	  for(int yy=max(0,y-1);yy<=min(c-1,y+1);yy++){
        ind[next]=1+nr(xx,yy);
        val[next++]=1.;
      }
	  glp_set_mat_row(lp,1+nr(x,y),next-1,ind,val);
    }
    puts("ok");
	glp_smcp param;
	glp_init_smcp(&param);
	param.presolve=GLP_ON;
    glp_simplex(lp,&param);
	FOR(x,r){
      FOR(y,c){
        ans[x][y]=(int)(glp_get_col_prim(lp,1+nr(x,y))+1e-6);
//        printf("%.2lf ",glp_get_col_prim(lp,1+nr(x,y)));
        printf("%d ",ans[x][y]);
        }
      puts("");
    }
    FOR(x,r)FOR(y,c){
      int s=0;
	  for(int xx=max(0,x-1);xx<=min(r-1,x+1);xx++)
	  for(int yy=max(0,y-1);yy<=min(c-1,y+1);yy++)
	    s+=ans[xx][yy];
      if (s!=t[x][y])cout<<x<<" "<<y<<":"<<s<<" "<<t[x][y]<<endl;
      assert(s==t[x][y]);
    }
    int res=(int)glp_get_obj_val(lp);
    glp_delete_prob(lp);
    fprintf(fout,"Case #%d: %d\n",cc,res);
    fflush(fout);
  }
  fclose(fout);
}
