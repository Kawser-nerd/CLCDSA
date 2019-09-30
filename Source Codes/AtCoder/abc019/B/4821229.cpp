#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<map>
#include<math.h>
#include<iomanip>

#define rep(i,n) for(ll i = 0; i < (ll)n; i++)
#define swap(a,b) a^=b;b^=a;a^=b;
//#define for(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define print(x) std::cout << x << std::endl;

typedef long long ll;

template<class T, class U> std::string replace(std::string s, const T& target, const U& replacement, bool replace_first = 0, bool replace_empty = 0) {
	using S = std::string;
	using C = std::string::value_type;
	using N = std::string::size_type;
	struct {
		auto len(const S& s) { return s.size(); }
		auto len(const C* p) { return std::char_traits<C>::length(p); }
		auto len(const C  c) { return 1; }
		auto sub(S* s, const S& t, N pos, N len) { s->replace(pos, len, t); }
		auto sub(S* s, const C* t, N pos, N len) { s->replace(pos, len, t); }
		auto sub(S* s, const C  t, N pos, N len) { s->replace(pos, len, 1, t); }
		auto ins(S* s, const S& t, N pos) { s->insert(pos, t); }
		auto ins(S* s, const C* t, N pos) { s->insert(pos, t); }
		auto ins(S* s, const C  t, N pos) { s->insert(pos, 1, t); }
	} util;

	N target_length = util.len(target);
	N replacement_length = util.len(replacement);
	if (target_length == 0) {
		if (!replace_empty || replacement_length == 0) return s;
		N n = s.size() + replacement_length * (1 + s.size());
		s.reserve(!replace_first ? n : s.size() + replacement_length);
		for (N i = 0; i < n; i += 1 + replacement_length) {
			util.ins(&s, replacement, i);
			if (replace_first) break;
		}
		return s;
	}

	N pos = 0;
	while ((pos = s.find(target, pos)) != std::string::npos) {
		util.sub(&s, replacement, pos, target_length);
		if (replace_first) return s;
		pos += replacement_length;
	}
	return s;
}

using namespace std;

bool isContain(int value, int under, int top) {
	if (under <= value && value <= top) return true;
	return false;
}

vector<int> range(int x);

int main(void) {
	//Program Start
	std::string s;
	cin >> s;

	//map<char, int> data;
	vector<char> chars;
	vector<int> numbers;

	char cur = s[0];
	int num = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != cur) {
			chars.push_back(cur);
			numbers.push_back(num);
			cur = s[i];
			num = 1;
		}
		else {
			num++;
		}
	}
	//data.insert(make_pair(cur, num));
	chars.push_back(cur);
	numbers.push_back(num);

	for (auto e : range(chars.size())) {
		printf("%c%d", chars[e], numbers[e]);
	}
	cout << endl;


ProgramEndPointLabel:;

	//Program End
	system("pause");

	return 0;
}


vector<int> range(int y) {
	vector<int> result(y);
	for (int i = 0; i < y; i++)
		result[i] = i;
	return result;
}