#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int double_compare(const void * a, const void * b) {
	double x = ((*(double *)a) - (*(double *)b));
	if(x>0) {
		return 1;
	} else if (x < 0) {
		return -1;
	}
	return 0;
}

#define nmax 1000
void readMasses(double m[nmax], int n) {
	int i;
	for(i=0; i<n-1; i++) {
		scanf("%lf ", &m[i]);
	}
	scanf("%lf\n", &m[i]);
}
void printMasses(double m[nmax], int n) {
	int i;
	for(i=0; i<n-1; i++) {
		printf("%lf ", m[i]);
	}
	printf("%lf\n", m[i]);
}

int main() {
	int t;
	int n;
	scanf("%u\n", &t);
	double mn[nmax];
	double mk[nmax];

	int score_deceit, score_war;

	int i,j;
	
	for(i=1; i<=t; i++) {
		scanf("%u\n",&n);
		readMasses(mn, n);
		readMasses(mk, n);
		score_deceit = 0;
		score_war = 0;

		// sort the lists of masses
		qsort(mn, n, sizeof(double), double_compare);
		qsort(mk, n, sizeof(double), double_compare);

		//printMasses(mn, n);
		//printMasses(mk, n);

		// strategy for war:
		// Ken will always play his minimum mass that allows him to score, and otherwise play the smallest mass left
		// Sort the blocks, and then work your way up naomi's list from the smallest mass, assigning the next largest mass that will beat it from Ken's stash to it.
		// the order Naoimi plays in doesn't really matter, so we'll work in the easiest case, with the masses sorted.
		j = 0;
		//we'll calculate ken's score because that's more convenient.
		while(j<n) {
			if(mk[j]>=mn[score_war]) {//this mass of ken's allows him to beat Naomi's next mass
				score_war++;
			}
			j++;
		}
		score_war = n-score_war; //since we originally calculated Ken's score and we actually want Naomi's

		// strategy for deceitful war:
		// Naomi's benefit here is that she can get Ken to burn his largest masses on contests that she will lose anyway, leaving some number of remaining contests that she can now win.
		// Naomi starts by comparing the sorted mass lists.  For each mass of hers, she determines if she can use it to beat one of ken's remaining masses.  If so, she will be able to score a point with it, and she crosses the highest of ken's remaining masses off as the one she will require him to use when she scores that point.  At some point she reaches a point where she can no longer beat any more of his, but she still has a pile of masses left, and ken still has a pile of masses left which he will get points for.  To play out her strategy, she starts by forcing him to play all these masses that he will get points for (even if they are larger than some of his others that he won't get points for) by telling him a value just less than each of them.  Then, once they are gone, she plays her masses that she will get points for from smallest to largest.  Ken will always exhaust his smallest remaining mass and not get any points.
		j = n-1;
		while(j>=0) {
			if(mn[n-1-score_deceit] >= mk[j]) {//she can score with this one
				score_deceit++;
			}
			j--;
		}

		printf("Case #%u: %u %u\n", i, score_deceit, score_war);
	}
	return 0;
}
