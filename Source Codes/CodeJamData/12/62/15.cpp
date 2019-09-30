#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <assert.h>
using namespace std;

double simpleCheck(const vector<double>& probs) {
	int k = (int)probs.size();
	vector<double> pref(k+1);
	pref[0] = 1.0;
	for (int i = 0; i < k; ++i) {
		pref[i+1] = pref[i] * probs[i];
	}
	double currentProb = 0;
	double curSuffix = 1.0;
	for (int i = 0; i <= k; ++i) {
		if (i != 0)
			curSuffix *= 1.0 - probs[k - i];
		currentProb += pref[k - i] * curSuffix;
	}
	return currentProb;
}

int main(void) {
	int testCount;
	scanf("%d", &testCount);
	for (int testNo = 1; testNo <= testCount; ++testNo) {
		int n, k;
		scanf("%d%d", &n, &k);
		vector<double> probs;
		for (int i = 0; i < n; ++i) {
			int a, b, c;
			scanf("%d%*[/]%d%d", &a, &b, &c);
			for (int i = 0; i < c; ++i) {
				if (a == 0 || a == b) {
					--k;
				} else
					probs.push_back(a * 1.0 / b);
			}
		}
		k = max(k, 0);
		sort(probs.begin(), probs.end(), greater<double>());
		vector<double> pref(k+1);
		pref[0] = 1.0;
		for (int i = 0; i < k; ++i) {
			pref[i+1] = pref[i] * probs[i];
		}
		double currentProb = 0;
		double curSuffix = 1.0;
		for (int i = 0; i <= k; ++i) {
			if (i != 0)
				curSuffix *= 1.0 - probs[k - i];
			currentProb += pref[k - i] * curSuffix;
		}
		double result = currentProb;
		double leftSum = 0.0;
		double rightSum = currentProb;
		curSuffix = 1.0;
		vector<double> cProbAr(probs.begin(), probs.begin() + k);
		for (int i = 1; i <= k; ++i) {
			double oldProb = probs[k - i];
			double newProb = probs[probs.size() - i];
			cProbAr[k - i] = newProb;
			leftSum += curSuffix * pref[k - i] * oldProb;
			rightSum -= curSuffix * pref[k - i] * oldProb;
			leftSum *= newProb / oldProb;
			rightSum *= (1 - newProb) / (1 - oldProb);
			curSuffix *= 1.0 - newProb;
			currentProb = leftSum  + rightSum;
			double simpleAns = simpleCheck(cProbAr);
			//assert(abs(currentProb - simpleAns) < 1e-6);
			result = max(result, simpleAns);
		}
		printf("Case #%d: %.9lf\n", testNo, double(1.0 - result));
	}
	return 0;
}
