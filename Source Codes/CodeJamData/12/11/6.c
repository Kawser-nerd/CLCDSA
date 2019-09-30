/*
 * a.c
 *
 *  Created on: 22/05/2011
 *      Author: achester
 */


#include <stdio.h>
#include <stdlib.h>

double min(double o, double o1){
	if(o1<o){
		return o1;
	}
	return o;
}

int main(int argc, char **argv) {

    int i,j,n,a,b, k;
   // double p[100000];
    double o1, o2, o3, pcum, o;
    double p;

    scanf("%d\n",&n);
    for(i=0;i<n;i++){


        scanf("%d %d\n",&a,&b);
        o = b+2;
       // printf("%lf\n",o);
        o1 = a+b+1;
    	//printf("%lf\n",o1);

        o=min(o1,o);
        pcum=1;
        for(j=1;j<=a;j++){
        	scanf("%lf ",&p);
        	pcum*=p;
        	o1=(1-pcum)*(b+1)+(b-a)+1+2*(a-j);
       // 	printf("%lf\n",o1);
        	o = min(o1,o);
        }

        scanf("\n");
        printf("Case #%d: %lf\n",i+1,o);


    }

}
