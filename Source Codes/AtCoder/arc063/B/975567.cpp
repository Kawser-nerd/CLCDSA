#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>
#define NMAX 100000
#define MMAX 10000
using namespace std;
vector<int > group[NMAX];
int main(){
	int N,T,A[NMAX] = {},dif[NMAX] = {},most = 0,first,end = 0,num = 0,gr_num = 0;
	cin >> N >> T;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		if(i == 0){
			first = A[i];
			group[gr_num].push_back(A[i]);
		}else if(first < A[i]){
			group[gr_num].push_back(A[i]);
			if(i == N-1){
				sort(group[gr_num].begin(), group[gr_num].end());
				dif[gr_num] = group[gr_num][group[gr_num].size()-1]-group[gr_num][0];
				most = max(most,dif[gr_num]);
			}
		}else{
			first = A[i];
			sort(group[gr_num].begin(), group[gr_num].end());
			dif[gr_num] = group[gr_num][group[gr_num].size()-1]-group[gr_num][0];
			most = max(most,dif[gr_num]);
			gr_num++;
			group[gr_num].push_back(A[i]);
		}
	}
	// for (int i = 0; i <= gr_num; ++i)
	// {
	// 	for (int j = 0; j < group[i].size(); ++j)
	// 	{
	// 		cout << group[i][j] << " ";
	// 	}
	// 	cout << dif[i];
	// 	cout << "\n";
	// }
	for (int i = 0; i < N; ++i)
	{
		if(dif[i] == most){
			num += /*dif_num[i]*/1;
			// cout << dif_num[i] << "\n";
		}
	}
	// cout << dif_num[N-1] << "\n";
	cout << num << "\n";
	return 0;
}