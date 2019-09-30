#include <stdio.h>
#include <math.h>

FILE *ifp;
FILE *ofp;

int T;
int D;
int P[1000];

void output(int, int);
int process();

int main(void){
	int i,j;

	ifp = fopen("B-large.in","r");
	ofp = fopen("output.txt","w");

	fscanf(ifp, "%d", &T);

	for(i=0;i<T;i++){
		fscanf(ifp, "%d", &D);
		for(j=0;j<D;j++){
			fscanf(ifp,"%d", &P[j]);
		}
		output(i+1, process());
	}

	fclose(ifp);
	fclose(ofp);
	return 0;
}

int process(){
	int i,j;
	int res;
	int sum;
	int max;
	int special[1001];

	sum=0;
	max=0;
	for(i=0;i<D;i++){
		sum+=P[i];
		if(max<P[i])
			max=P[i];
	}

	for(i=0;i<=max;i++){
		special[i] = 0;
	}

	for(i=0;i<D;i++){
		for(j=1;j<=max;j++)
			special[j] += (int)ceil((double)P[i]/j);
	}

	for(i=1;i<=max;i++)
		special[i] = special[i] + i - D;

	res=max;
	for(i=1;i<=max;i++){
		if(res > special[i])
			res = special[i];
	}

	return res;
}

void output(int i, int res){
	fprintf(ofp, "Case #%d: %d\n", i, res);
}