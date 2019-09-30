#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int A[2][2], G[2][2], T, n;

void square(); // A->A*A
void pow(int); // G->A**n
void mul();    // G->A*G

int main() {
	FILE *fin = fopen("C.in","r"), *fout = fopen("C.out","w");
	fscanf(fin,"%d",&T);
	for(int k = 1; k<=T; k++) {
		A[0][0] = 6;
		A[0][1] = -4;
		A[1][0] = 1;
		A[1][1] = 0;
		G[0][0] = 1;
		G[0][1] = 0;
		G[1][0] = 0;
		G[1][1] = 1;
		fscanf(fin,"%d",&n);
		pow(n-2);
		fprintf(fout,"Case #%d: %03d\n", k, ((G[0][0]*28 + G[0][1]*6 + 1000)%1000+999)%1000);
	}
}

void square() {
	int B[2][2];
	B[0][0] = A[0][0] * A[0][0] + A[0][1] * A[1][0];
	B[0][1] = A[0][0] * A[0][1] + A[0][1] * A[1][1];
	B[1][0] = A[1][0] * A[0][0] + A[1][1] * A[1][0];
	B[1][1] = A[1][0] * A[0][1] + A[1][1] * A[1][1];
	A[0][0] = B[0][0]%1000;
	A[0][1] = B[0][1]%1000;
	A[1][0] = B[1][0]%1000;
	A[1][1] = B[1][1]%1000;
}

void mul() {
	int B[2][2];
	B[0][0] = A[0][0] * G[0][0] + A[0][1] * G[1][0];
	B[0][1] = A[0][0] * G[0][1] + A[0][1] * G[1][1];
	B[1][0] = A[1][0] * G[0][0] + A[1][1] * G[1][0];
	B[1][1] = A[1][0] * G[0][1] + A[1][1] * G[1][1];
	G[0][0] = B[0][0]%1000;
	G[0][1] = B[0][1]%1000;
	G[1][0] = B[1][0]%1000;
	G[1][1] = B[1][1]%1000;
}

void pow(int n) {
	while(n) {
		if(n&1) {
			mul();
		}
		square();
		n>>=1;
	}
}
