/*
 *  File: Program2.cpp
 *  ------------------
 *
 *  Created by Elina Robeva on 5/7/10.
 *
 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int C;
int N;



int compare (string a, string b) {
	if(a.size() > b.size()) return 1;
	if(a.size() < b.size()) return -1;
	for(int i = 0; i < a.size(); ++i) {
		if(a[i] > b[i]) return 1;
		if(a[i] < b[i]) return -1;
	}
	return 0;
}





string rev(string s) {
	string res = "";
	for(int j = s.size() - 1; j >= 0; --j) {
		res += s[j];
	}
	return res;
}



string diff(string s1, string s2) {
		string a = rev(s1);
		string b = rev(s2);
		string res = "";
		
		
		for(int i = 0; i < b.size(); ++i) {
			if(a[i] >= b[i]) {
				res += a[i] - b[i] + '0';
			} else {
				int j = 1;
				while(true) {
					if(a[i + j] != '0') {
						a[i + j] -= 1;
						break;
					} else {
						a[i + j] = '9';
						j++;
					}
				}
				res += 10 + (a[i] - b[i]) + '0';
			}
		}
		for(int i = b.size(); i < a.size(); ++i) {
			res += a[i];
		}
		string real_res = "";
		res = rev(res);
		int flag = 0;
		for(int i = 0; i < res.size(); ++i) {
			if(res[i] != '0') {
				flag = 1;
			}
			if(flag) {
				real_res += res[i];
			}
		}
		if(real_res == "") {
			real_res += '0';
		}
		return real_res;
}

string rem(string a, string b) {
	
	if(compare(a, b) < 0) return a;
	string tmp = b;
	for(int i = 1; i < a.size() - b.size(); ++i) {
		tmp += '0';
	}
	return rem(diff(a, tmp), b);
}





string gcd(string a, string b) {
	if(compare(a, b) == 0) {
		return a;
	}
	string tmp;
	if(compare(a, b) < 0) {
		tmp = a;
		a = b;
		b = tmp;
	}
	
	
	string r = rem(a, b);
	if(r == "0") {
		return b;
	}
	return gcd(b, r);
}


string vec_gcd(vector<string> nums) {
	if(nums.size() == 1) {
		return nums[0];
	}
	vector<string> next;
	for(int i = 0; i < nums.size()/2; ++i) {
		next.push_back(gcd(nums[2 * i], nums[2 * i + 1]));
	}
	if(nums.size() % 2) {
		next.push_back(nums[nums.size() - 1]);
	}
	return vec_gcd(next);
}


int main() {
	freopen("/Users/erobeva/Downloads/B-large.in","r",stdin);
	freopen("/Users/erobeva/Downloads/AAAout.txt", "w", stdout);
	
	cin >> C;
	
	for(int i = 0; i < C; ++i) {
		cin >> N;
		
		vector<string> times;
		for(int j = 0; j < N; ++j) {
			string str;
			cin >> str;
			
			times.push_back(str);
		}	
		vector<string> nums;
		for(int j = 1; j < N; ++j) {
			string str;
			if(compare(times[0], times[j]) > 0) {
				
				str = diff(times[0], times[j]);
			} else {
				
				str = diff(times[j], times[0]);
			}	
			if(str != "0") {
				nums.push_back(str);
			}	
		}
		
		string gcd = vec_gcd(nums);
		
		string result;
		string r = rem(times[0], gcd);
		if(r == "0") {
			result = "0";
		} else {
			result = diff(gcd, r);
		}	
		cout << "Case #" << i + 1 << ": " << result << endl;
	}
	
	return 0;
	
}
