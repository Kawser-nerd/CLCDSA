#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define t_step 0.5

void calc_area(float *v_now, float *t_now, const vector<int> v, const vector<int> t, double *area){
  float t_next = *t_now + t_step;
  float v_max = -1;
  for(int i=0; i<t.size(); i++){
    float v_max_tmp;
    if(t_next <= t[i]) v_max_tmp = v[i+1] + (t[i] - t_next) * 1.0;
    else if(t_next >= t[i] && t_next <= t[i+1]) v_max_tmp = v[i+1];
    else v_max_tmp = v[i+1] + (t_next - t[i+1]) * 1.0;

    if(v_max == -1 || v_max_tmp <= v_max) v_max = v_max_tmp;
  }

  double area_tmp;
  if(v_max > *v_now){
    area_tmp = (*v_now + *v_now + 0.5) * t_step / 2.0;
    *v_now += 0.5;
  }
  else if(v_max == *v_now){
    area_tmp = *v_now * t_step;
    *v_now += 0.0;
  }
  else{
    area_tmp = (*v_now + *v_now - 0.5) * t_step / 2.0;
    *v_now -= 0.5;
  }

  *area += area_tmp;
  *t_now += t_step;
}

int main(){
  int N;
  cin >> N;
  vector<int> t, v;
  double area = 0.0;
  for(int i=0; i<N; i++){
    int t_;
    cin >> t_;
    t.push_back(t_);
  }
  for(int i=0; i<N; i++){
    int v_;
    cin >> v_;
    v.push_back(v_);
  }

  vector<int> t_processed(N+1), v_processed(N+2);
  t_processed[0] = 0.0;
  v_processed[0] = 0.0; v_processed[N+1] = 0.0;
  for(int i=0; i<N; i++){
    t_processed[i+1] = t_processed[i] + t[i];
    v_processed[i+1] = v[i];
  }

  float v_now = 0.0; float t_now = 0.0;
  while(t_now < t_processed[N]){
    calc_area(&v_now, &t_now, v_processed, t_processed, &area);
    // cout << t_now << ' ' << area << endl;                                                                                                                                 
  }

  cout << fixed << area << endl;

  return 0;
}