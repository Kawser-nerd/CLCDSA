#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N;
int inseq[1000];
int seq[1000];
int len;
int newSeq[1000];
int last;
bool done;
bool good;
bool unknown;
int ans;

int cVals[30];
int sVals[30];

bool isEven(int l) {
	for (int i = 0; i < l; i+=2) {
		if (seq[i] != seq[0]) {
			return false;
		}
	}
	return true;
}

bool isOdd(int l) {
	for (int i = 1; i < l; i+=2) {
		if (seq[i] != seq[1]) {
			return false;
		}
	}
	return true;
}

int modify(int l) {
	int ret;
	bool even;
	if (isEven(l)) {
		even = true;
		if (isOdd(l)) {
			return 10000000;		
		}
	} else {
		even = false;
	}

	if (even) {
		ret = seq[0];
		len = 0;
		for (int i = 1; i < l; i+=2) {
			newSeq[i/2] = seq[i];
			len++;
		}
		if (l % 2 == 0) {
			good = true;
		}
	} else {
		ret = seq[1];
		len = 0;
		for (int i = 0; i < l; i+=2) {
			newSeq[i/2] = seq[i];
			len++;
		}
		if (l % 2 == 1) {
			good = true;
		}
	}
	return ret;
}

int main() {
	fstream in;
	fstream out;
	in.open("prob3.in", fstream::in);
	out.open("prob3.out",fstream::out);
	
	in >> T;
	for (int a = 0; a < T; a++) {
		done = false;
		unknown = false;
		ans = 0;
		in >> N;
		len = N;
		for (int b = 0; b < N; b++) {
			in >> inseq[b];
		}
		last = inseq[N-1];
		for (int c = 0; c < N-1; c++) {
			seq[c] = (inseq[c+1] - inseq[c] + 10007) % 10007;
		}
		len --;
		if (len > 2) {
			good = false;
			cVals[0] = modify(len);
			if (cVals[0] == 10000000) {
				done = true;
				unknown = true;
			} else if (good) {
				done = true;
				ans = (last + cVals[0]) % 10007;
			}
		}
		int count = 1;
		while (len > 2 && !done) {
			good = false;
			sVals[count] = modify(len);
			if (sVals[count] == 10000000) {
				done = true;
				unknown = true;
			} else if (good) {
				done = true;
				ans = (last + sVals[count]) % 10007;
			}
			count++;
		}
		if (!unknown && done) {
			out << "Case #" << a + 1 << ": " << ans << endl;
		} else {
			out << "Case #" << a + 1 << ": " << "UNKNOWN" << endl;
		}
	}
	
	in.close();
	out.close();
	return 0;
}