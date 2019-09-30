#include<iostream>
#include<vector>
using namespace std;

int main() {
  int D, G;
  int p[10], c[10];
  vector< vector <int> > cand;
  vector<int> solve_all;
  vector<int> nums;
  cin >> D >> G;
  for (int i = 0; i < D; i++) {
    cin >> p[i] >> c[i];
    solve_all.push_back(i);
  }
  for (int bit = 0; bit < (1<<D); bit++) {
    vector<int> tmp;
    for (int i = 0; i < D; i++) {
      if((bit & 1<<i)) tmp.push_back(solve_all[i]);
    }
    cand.push_back(tmp);
  }
  /*
  for (vector<int>  index_v : cand) {
    for (int  i : index_v) {
      cout << i;
    }
    cout << endl;
  }
  */
  vector<int> not_solve;
  cand.push_back(not_solve);
  for (vector<int> index_v : cand) {
    int sum_point = 0, sum_num = 0;
    for (int i: index_v) {
      sum_point += 100 * p[i] * (i+1) + c[i];
      sum_num += p[i];
    }
    vector<int> not_solve_all;
    for(int i = 0; i < D; i++) {
      if(binary_search(index_v.begin(), index_v.end(), i)) continue;
      not_solve_all.push_back(i);
    }
    // sort(not_solve_all.begin(), not_solve_all.rend());
    reverse(not_solve_all.begin(), not_solve_all.end());
    for(int i: not_solve_all) {
      for(int j = 0; j < p[i]; j++) {
        if (sum_point >= G) break; 
        sum_point += 100 * (i+1);
        sum_num++;
      }
    }
    nums.push_back(sum_num);
  }
  sort(nums.begin(), nums.end());
  cout << nums[0];
  return 0;
}