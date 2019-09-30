#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	string s1, s2, s3; cin >> s1 >> s2 >> s3;
	printf("%c%c%c\n", s1[0]-'a'+'A', s2[0]-'a'+'A', s3[0]-'a'+'A');
}