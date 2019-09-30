#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <stdlib.h>
#define let(i,a) __typeof(a)i=a
using namespace std;

int N;
string A;

int atoi2(string a) {
	int num = 0;
	for (int i = 0; i < a.size(); i++) {
		num *= 10;
		num += (a[i] - '0');
		num %= 210;
	}
	return num;
}

int main() {
	cin >> N;
	for (int case_n = 1; case_n <= N; case_n++) {
		cin >> A;
		map<int, long long> NS[50];
		for (int i = 0; i < 50; i++) NS[i].clear();
		for (int i = 1; i <= A.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (j) {
					int num = atoi2(A.substr(j, i - j).c_str());
					for (let(it, NS[j].begin()); it != NS[j].end(); it++) {
						NS[i][it->first - num] += it->second;
						NS[i][it->first + num] += it->second;
					}
				} else {
					NS[i][atoi2(A.substr(0, i).c_str())]++;
				}
			}
		}
		long long ug = 0;
		for (let(it, NS[A.size()].begin()); it != NS[A.size()].end(); it++) {
			for (int i = 2; i < 8; i++) {
				if (it->first % i == 0) { ug += it->second; break; }
			}
		}
		printf("Case #%d: %lld\n", case_n, ug);
	}
	return 0;
}