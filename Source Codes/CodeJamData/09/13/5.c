/*
 *  cards.c
 *  gcj
 *
 *  Created by Joseph Moore on 9/11/09.
 *  Copyright 2009. All rights reserved.
 *
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
const long double HPI=3.1415926535897932384626433832795;
double lnfactorial(int x);
double factorial(int x);

double lngamma(double x){
	double z, temp, sum;
	static double coeff[10]={5716.400188274341379136, -14815.30426768413909044,
		14291.49277657478554025, -6348.160217641458813289, 1301.608286058321874105, -108.1767053514369634679,
		2.605696505611755827729, -0.7423452510201416151527e-2, 0.5384136432509564062961e-7,
		-0.4023533141268236372067e-8};
	int i;
	
	if (((double)((int)x))==x && x<=50) return log(factorial(x-1.0));
	
	if (x > 1.0)
	{
		z=x-1.0;
		temp=z+9.5;
		temp -= (z+0.5)*log(temp);
		sum=1.000000000000000174663;
		for(i=0;i<=9;i++)
		{
			z += 1.0;
			sum += coeff[i]/z;
		}
		return (double)(-temp+log(2.5066282746310002*sum));
	}
	if (x<1.0 && x>0.0) return lngamma(1.0+x)-log(x);
	return log(HPI)-lngamma(x)-log(sin(HPI*x));
	
}

double factorial(int x){
	static int nMax = 7;
	static double facts[51]={1.0,1.0,2.0,6.0,24.0,120.0,720.0,5040.0};
	int temp;
	if (x<0) return 0.0/0.0;
	if (x>50) return exp(lngamma(x + 1.0));
	while (x>nMax) {
		temp=nMax++;
		facts[nMax]=facts[temp]*nMax;
	}
	return facts[x];
}

double gamma(double x){
	if (((double)((int)x))==x) return factorial(x-1.0);
	return exp(lngamma(x));
}

double binom(int n, int k){

	if(k>n){
		return 0.0;
	}
	if(k==n){
		return 1.0;
	}
	return floor(0.5+exp(lnfactorial(n)-lnfactorial(k)-lnfactorial(n-k)));
}

double lnfactorial(int x){
	static double lnfacts[151];
	
	if (x<0) return 0.0/0.0;
	if (x<=1) return 0.0;
	if(x<=150) return lnfacts[x] ? lnfacts[x] : (lnfacts[x]=lngamma(x+1.0));
	return lngamma(x+1.0);
}
double U(int s, int t, int n, int k){
	return ((binom(s,k+s-t)*binom(n-s,t-s))/binom(n,k));
}
int min(int a, int b){
	if (a<b){
		return a;
	}
	return b;
}

int main(){
	FILE *ifp, *ofp;
	double M[41];
	char *infile = "C-large.in", *outfile = "cards.out";
	int i,t,s, N, n, k;
	double out;
	ifp = fopen(infile, "r");
	if (ifp == NULL) {
		fprintf(stderr, "Can't open input file!\n");
		exit(1);
	}
	ofp = fopen(outfile, "w");
	if (ofp == NULL) {
		fprintf(stderr, "Can't open output file!\n");
		exit(1);
	}
	fscanf(ifp, "%d", &N);
	for(i=1;i<=N;i++){
		fscanf(ifp,"%d %d",&n,&k);
		if(n==k){
			fprintf(ofp, "Case #%d: %.7f\n",i,1.0);
		}
		else if(k==1){
			out=0;
			for(t=1;t<=n;t++){
				out+=1.0/((double)(t));
			}
			out*=n;
			fprintf(ofp, "Case #%d: %.7f\n",i,out);
		}
		else{
			M[n]=0;
			for (s=n-1; s>=0; s--) {
				out=1.0;
				for(t=s+1;t<=min(n,s+k);t++){
					out+=U(s,t,n,k)*M[t];
				}
				M[s]=out/(1-U(s,s,n,k));
			}
			fprintf(ofp, "Case #%d: %.7f\n",i,M[0]);
		}
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}
