#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	string S;

	cin >> N >> S;

	int count = 0;
	for(int i = 0 ; i < S.size() ; ++i) {
		switch(S[i]) {
		case '(':
			++count;
			break;

		case ')':
			if(count) {
				--count;
			} else {
				S = '(' + S;
				++i;
			}
			break;
		}
	}

	cout << (S + string(count, ')')) << endl;
}