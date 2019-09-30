#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<vector>
#include<cassert>

using namespace std;

struct point{
  int x,y;
};

point lo[100];
point up[100];
int W, L, U, G;

double g[100];

double cal_area(double left, double right)
{
  int left_l = 0,left_u = 0;
  int right_l = 0,right_u = 0;
  while(lo[left_l].x < left) ++left_l;
  while(up[left_u].x < left) ++left_u;

  while(lo[right_l].x < right) ++right_l;
  while(up[right_u].x < right) ++right_u;

  double yloleft = lo[left_l-1].y + (lo[left_l].y - lo[left_l-1].y)*(left - lo[left_l-1].x)/(lo[left_l].x - lo[left_l-1].x);
  double yupleft = up[left_u-1].y + (up[left_u].y - up[left_u-1].y)*(left - up[left_u-1].x)/(up[left_u].x - up[left_u-1].x);

  double yloright = lo[right_l-1].y + (lo[right_l].y - lo[right_l-1].y)*(right - lo[right_l-1].x)/(lo[right_l].x - lo[right_l-1].x);
  double yupright = up[right_u-1].y + (up[right_u].y - up[right_u-1].y)*(right - up[right_u-1].x)/(up[right_u].x - up[right_u-1].x);

  double area = 0.0;
  
  area += left*(yloleft - yupleft);
  if(left_l == right_l){
    area += left*yloright - right*yloleft;
  }else{
    area += left*lo[left_l].y - lo[left_l].x*yloleft;
    for(int i=left_l;i<right_l-1;++i){
      area += lo[i].x*lo[i+1].y - lo[i+1].x*lo[i].y;
    }
    area += lo[right_l-1].x * yloright - right*lo[right_l-1].y;
  }
  area += right*(yupright - yloright);
  if(left_u == right_u){
    area += right*yupleft - left*yupright;
  }else{
    area += right*up[right_u-1].y - up[right_u-1].x*yupright;
    for(int i=right_u-1;i>left_u;--i){
      area += up[i].x*up[i-1].y - up[i-1].x*up[i].y;
    }
    area += up[left_u].x*yupleft - left*up[left_u].y;
  }
  return area;
}

void search(double left, double right, int start, int div)
{
  if(div < 2) return;

  int half = div>>1;
  double area = cal_area(left, right)/div*half;

  double l = left;
  double r = right;

  double m = (l + r)*0.5;
  double lm = cal_area(left, m);
  while(fabs(lm - area)> 1e-9){
    if(lm < area) l = m;
    else r = m;
    m = (l + r)*0.5;
    lm = cal_area(left, m);
  }

  g[start + half - 1] = m;
  search(left, m, start, half);
  search(m, right, start + half, div - half);
}

void do_case(void)
{
  cin>>W>>L>>U>>G;
  for(int i=0;i<L;++i) cin>>lo[i].x>>lo[i].y;
  for(int i=0;i<U;++i) cin>>up[i].x>>up[i].y;

  search(0 + 1e-15, W - 1e-15, 0, G);
  cout<<'\n';
  for(int i=0;i<G-1;++i){
    printf("%17.10e\n", g[i]);
  }
}

int main()
{
  freopen("input.data", "r", stdin);
  //freopen("output.data", "r", stdout);

  int cases;
  cin>>cases;
  int i = 1;
  do{
    printf("Case #%d: ", i);
    do_case();
  }while(++i <= cases);

  return 0;
}
