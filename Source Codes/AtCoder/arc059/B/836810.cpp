#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
using ulong = unsigned long;
using ll = long long;

// int judge(string& s, int l){
// 	int nums[26] = {};
// 	int sum = 0;
// 	for(int i=l;i<s.size();i++){
// 		nums[s[i] - 'a']++;
// 		sum++;
// 		if(sum >= 2 && nums[s[i] - 'a'] * 2 > sum){
// 			return i;
// 		}
// 	}
// 	return -1;
// }

int main(){
	string s;
	cin >> s;
	for(int i=0;i<s.size()-1;i++){
		if(s[i] == s[i+1]){
			cout << i+1 << ' ' << i+2 << endl;
			return 0;
		}else if(s[i] == s[i+2]){
			cout << i+1 << ' ' << i+3 << endl;
			return 0;
		}
	}
	//for(int i=0;i<s.size();i++){
	//	int ret = judge(s, i);
	//	if(ret != -1){
	//		cout << i + 1 << ' ' << ret + 1 << endl;
	//		return 0;
	//	}
	//}
	cout << "-1 -1" << endl;
	return 0;
}