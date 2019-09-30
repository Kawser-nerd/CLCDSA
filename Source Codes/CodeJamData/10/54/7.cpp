#include <vector>
#include <map>
#include <iostream>
using namespace std;

static unsigned long long M = 1000000007;
static unsigned long long C[128][128];

/* [digit count][max digit][sum] */
static unsigned long long digitCounts_nozero[128][128][4096];

/* digit count, sum -> how many */
map<pair<unsigned int, unsigned long long>, unsigned long long> buf;

static unsigned long long get(unsigned int n, unsigned long long sum, unsigned int B);

static unsigned long long solve(unsigned int n, unsigned long long sum, unsigned int B) {
	if (sum==0)
		return n==0 ? 1 : 0;
	if (n==0)
		return 0;
	unsigned int remainder = (unsigned int)(sum%B);

	unsigned long long res = 0;
	unsigned int maxSum = B*(B+1) / 2;
	if (maxSum>sum)
		maxSum = (unsigned int)sum;

	/* no zero */
	for (unsigned int digitSum=remainder; digitSum<=maxSum; digitSum += B) {
		unsigned long long digitWays = digitCounts_nozero[n][B][digitSum];
		if (digitWays==0) continue;
		for (unsigned int oneDigitNumbers=0; oneDigitNumbers<=n; oneDigitNumbers++) {
			unsigned long long prev = get(n-oneDigitNumbers, (sum-digitSum)/B, B);
			prev = (prev*C[n][oneDigitNumbers]) % M;
			for (unsigned int i=2; i<=n-oneDigitNumbers; i++)
				prev = (prev*i) % M;
			prev = (prev*digitWays) % M;
			res = (res + prev) % M;
		}
	}

	/* zero */
	for (unsigned int digitSum=remainder; digitSum<=maxSum; digitSum += B) {
		unsigned long long digitWays = digitCounts_nozero[n-1][B][digitSum];
		if (digitWays==0) continue;
		for (unsigned int oneDigitNumbers=0; oneDigitNumbers<n; oneDigitNumbers++) {
			unsigned long long prev = get(n-oneDigitNumbers, (sum-digitSum)/B, B);
			prev = (prev*C[n-1][oneDigitNumbers]) % M;
			for (unsigned int i=2; i<=n-oneDigitNumbers; i++)
				prev = (prev*i) % M;
			prev = (prev*digitWays) % M;
			res = (res + prev) % M;
		}
	}

	return res;
}

static unsigned long long get(unsigned int n, unsigned long long sum, unsigned int B) {
	if (buf.find(make_pair(n, sum))!=buf.end())
		return buf[make_pair(n, sum)];
	unsigned long long ans = solve(n, sum, B);
	buf[make_pair(n, sum)] = ans;
	return ans;
}

static void init(unsigned int B) {
	buf.clear();
	/* no zero */
	unsigned int maxSum = B*(B+1) / 2;
	for (unsigned int maxDigit=0; maxDigit<=B; maxDigit++) {
		fill(digitCounts_nozero[0][maxDigit], digitCounts_nozero[0][maxDigit]+maxSum+1, 0);
		digitCounts_nozero[0][maxDigit][0] = 1;
	}
	for (unsigned int digitCount=1; digitCount<=B; digitCount++) {
		for (unsigned int maxDigit=0; maxDigit<=B; maxDigit++) {
			for (unsigned int sum=digitCount*(digitCount-1)/2; sum<=maxSum && sum<=digitCount*B; sum++) {
				unsigned long long res = 0;
				for (unsigned int lastDigit=1; lastDigit<maxDigit && lastDigit<=sum; lastDigit++)
					res += digitCounts_nozero[digitCount-1][lastDigit][sum-lastDigit];
				digitCounts_nozero[digitCount][maxDigit][sum] = res % M;
			}
		}
	}
}

static void runTest() {
	unsigned long long N;
	unsigned int B;
	cin >> N >> B;
	init(B);
	unsigned long long res = 0;
	for (unsigned int n=1; n<=B; n++)
		res += get(n, N, B);
	cout << (res%M) << endl;
}

int main() {
	int T;
	cin >> T;
	for (unsigned int i=0; i<128; i++) {
		C[i][0] = 1;
		for (unsigned int j=1; j<i; j++)
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % M;
		C[i][i] = 1;
	}

	for (int i=0; i<T; i++) {
		cout << "Case #" << (i+1) << ": ";
		runTest();
		cout.flush();
		cerr << (i+1) << endl;
	}
	return 0;
}
