#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void solve();

int main(int argc, char *argv[]) {
    int t;
   
    scanf("%d\n", &t);
    for (int i=0;i<t;i++) {
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}

void solve() {
	int n,a;
	double d;
	double *ac;
	double *pos;
	double t;
	double to,tcrit;

	scanf("%lf %d %d\n",&d, &n,&a);
	ac=malloc(a*sizeof(double));
	pos=malloc(n*2*sizeof(double));
	for (int i=0;i<n;i++) {
		scanf("%lf %lf\n",pos+2*i,pos+2*i+1);
	}
	for (int i=0;i<a;i++) {
		scanf("%lf",ac+i);
	}

	if (n==1) {
		printf("\n");
		for (int i=0;i<a;i++){
			printf("%0.6lf\n", sqrt(2*d/ac[i]));
		}
		return;
	}
	if (n==2) {
		printf("\n");
		to=pos[0]+((d-pos[1])*(pos[2]-pos[0]))/(pos[3]-pos[1]);
		for (int i=0;i<a;i++) {
			t=sqrt(2*d/ac[i]);
			tcrit=sqrt(2*pos[1]/ac[i]);
			if ((to>t))
				printf("%0.7lf\n",to);
			else if ((t>to) && (tcrit<pos[0]))
				printf("%0.7lf\n",t+pos[0]);
			else
				printf("%0.7lf\n",t);
		}
		return;
	}
	printf("ERROR\n");
	return;

}
