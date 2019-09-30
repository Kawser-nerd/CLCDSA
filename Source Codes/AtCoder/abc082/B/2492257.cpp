#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    priority_queue<char, vector<char>, greater<char> > que_s;
    priority_queue<char> que_t;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) {
        que_s.push(s[i]);
    }
    for (int i = 0; i < t.length(); i++) {
        que_t.push(t[i]);
    }
    while(!que_s.empty()) {
        if (que_t.empty()) {
            printf("No\n");
            return 0;
        }
        if (que_s.top() > que_t.top()) {
            printf("No\n");
            return 0;
        }else if (que_s.top() < que_t.top()) {
            printf("Yes\n");
            return 0;
        }
        que_s.pop(); que_t.pop();
		if (que_s.empty() && que_t.empty()) {
			printf("No\n");
			return 0;
		}
    }
    printf("Yes\n");
    return 0;
}