#include <stdio.h>
#include <stdlib.h>

FILE *ifp;
FILE *ofp;

int process(int S, char *aud);
void output(int T, int res);

int main(void){
	int i, T;
	int S;
	char *aud;

	ifp = fopen("A-large.in", "r");
	ofp = fopen("output.txt","w");

	fscanf(ifp, "%d", &T);
	
	for(i=0;i<T;i++){
		fscanf(ifp, "%d", &S);
		aud = (char *)malloc(sizeof(char)*(S+2));
		fscanf(ifp, "%s", aud);
		output(i+1, process(S, aud));
	}

	fclose(ifp);
	fclose(ofp);
	return 0;
}

int process(int S, char *aud){
	int res=0;
	int sum=aud[0]-'0';
	int i;

	for(i=1;i<=S;i++){
		if(i > sum + res){
			res = i - sum;
		}
		sum += aud[i]-'0';
	}

	return res;
}

void output(int T, int res){
	fprintf(ofp, "Case #%d: %d\n", T, res);
}