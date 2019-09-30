// @betaveros :: generated with cpp2.hs
#include <algorithm>
#include <cstdio>
using namespace std;
int speed, n, qpos[88], qspeed[88];

const double OO = 1e18;
double best = OO;

double myabs(double x) {
	return x < 0 ? -x : x;
}

bool used[88];
void dfs(int caught, double here, double now) {
	if (caught == n) {
		
		best = min(best, now);
		return;
	}
	double leftcatch = OO, rightcatch = OO;
	double leftat = 0, rightat = 0;
	int left = -1, right = -1;
	
	for (int i = 0; i < n; ++i){
		if (used[i]) continue;
		int sign = (qpos[i] > 0 ? 1 : -1);
		double qhere = qpos[i] + sign * qspeed[i] * now;
		double qcatch = myabs(qhere - here) / (speed - qspeed[i]);
		
		double qat = here + sign * qcatch * speed;
		if (qpos[i] > 0) {
			if (qcatch < rightcatch) {
				rightcatch = qcatch;
				rightat = qat;
				right = i;
			}
		} else {
			if (qcatch < leftcatch) {
				leftcatch = qcatch;
				leftat = qat;
				left = i;
			}
		}
	}
	if (leftcatch > -1) {
		used[left] = true;
		dfs(caught + 1, leftat, now + leftcatch);
		used[left] = false;
	}
	if (rightcatch > -1) {
		used[right] = true;
		dfs(caught + 1, rightat, now + rightcatch);
		used[right] = false;
	}
}

void tc() {
	best = OO;
	scanf("%d%d", &speed, &n);
	for (int i = 0; i < n; ++i){ scanf("%d", &qpos[i]); }
	for (int i = 0; i < n; ++i){ scanf("%d", &qspeed[i]); }
	dfs(0, 0, 0);
	printf("%.15f\n", best);
}

int main() {
    int tcn; scanf("%d", &tcn);
    for (int tci = 1; tci <= tcn; ++tci) {
        printf("Case #%d: ", tci);
        tc();
    }
    return 0;
}

