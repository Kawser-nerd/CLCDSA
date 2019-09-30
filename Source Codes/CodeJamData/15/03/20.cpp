#include <iostream>
#include <cassert>
#include <limits>

using namespace std;

#define pos1 0
#define posI 1
#define posJ 2
#define posK 3
#define neg1 4
#define negI 5
#define negJ 6
#define negK 7

const long long MAX_LEN = 10000;
const long long MAX_X = 1000000000000ll;
const long long MAX_LX = 10000000000000000ll;
const long long NOT_FOUND = numeric_limits<long long>::max();
const long long SOME_GENEROUS_UPPER_BOUND = 20;

int table[][4] = {{pos1, posI, posJ, posK},
                  {posI, neg1, posK, negJ},
                  {posJ, negK, neg1, posI},
                  {posK, posJ, negI, neg1}};

char kar[] = {'1', 'i', 'j', 'k'};

struct quaternion {
	int val; // quaternions in order: {1, i, j, k, -1, -i, -j, -k}
	quaternion() : val(0) {}
	quaternion(int _val) : val(_val) {}
	bool operator==(const quaternion& other) const {
		return val == other.val;
	}
	bool operator!=(const quaternion& other) const {
		return val != other.val;
	}
	quaternion& operator*=(const quaternion& other) {
		int sgn = 4 * (val / 4) + 4 * (other.val / 4);
		val = (table[val % 4][other.val % 4] + sgn) % 8;
		return *this;
	}
	quaternion operator*(const quaternion& other) const {
		return quaternion(*this) *= other;
	}
	friend ostream& operator<<(ostream& os, const quaternion& q) {
		os << (q.val >= 4 ? "-" : "") << kar[q.val % 4];
		return os;
	}
};

quaternion pow(quaternion q, long long exponent) {
	quaternion ans;
	for (long long i = 1; i <= exponent; i <<= 1) {
		if (exponent & i) ans *= q;
		q *= q;
	}
	return ans;
}

long long L, X;
quaternion partial[MAX_LEN + 1];
quaternion powers[SOME_GENEROUS_UPPER_BOUND];

long long findPartial(quaternion q, long long start) {
	int practicalX = min(SOME_GENEROUS_UPPER_BOUND, X);
	long long found = NOT_FOUND;
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < practicalX; j++) {
			long long curPos = L * j + i;
			if (curPos >= start && powers[j] * partial[i] == q)
				found = min(found, curPos);
		}
	}
	return found;
}

bool solve() {
	cin >> L >> X;
	assert(L >= 1 && L <= MAX_LEN);
	assert(X >= 1 && X <= MAX_X);
	assert(L * X <= MAX_LX);
	string s;
	cin >> s;
	assert((int) s.size() == L);
	partial[0] = quaternion(0);
	for (int i = 0; i < L; i++) {
		assert(s[i] == 'i' || s[i] == 'j' || s[i] == 'k');
		partial[i + 1] = partial[i] * (quaternion) {s[i] - 'h'};
	}
	//cerr << "  total product: " << pow(partial[L], X) << endl;
	assert(pow(partial[L], X) == pow(partial[L], X % 4)); // just checking ;-)
	if (pow(partial[L], X) != neg1)
		return false;
	powers[0] = quaternion();
	for (int i = 1; i < SOME_GENEROUS_UPPER_BOUND; i++) {
		powers[i] = powers[i - 1] * partial[L];
		assert(powers[i] == pow(partial[L], i)); // again, just checking
	}
	long long firstI = findPartial(posI, 0);
	if (firstI == NOT_FOUND) return false;
	//cerr << "  first i: " << firstI << endl;
	long long firstK = findPartial(posK, firstI);
	//cerr << "  first k: " << firstK << endl;
	return firstK != NOT_FOUND;
}

int main() {
	int T;
	cin >> T;
	assert(T >= 1 && T <= 100);
	for (int i = 0; i < T; i++)
		cout << "Case #" << (i + 1) << ": " << (solve() ? "YES" : "NO") << endl;
	return 0;
}
