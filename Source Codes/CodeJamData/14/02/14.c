/*
    By Yemeli Tasse Cyrille
    http://yemelitc.org
    Date: 12 April 2014
*/


#include<stdio.h>


int main()
{
	int i, j;
	int cases, T;

	double C, F, X;
	double count, ans;
	double a, b, c, f1, f2;

	FILE *output = fopen("B-large.out", "w");
	FILE *input = fopen("B-large.in", "r");
	fscanf(input, "%d", &T);

	for(cases=1; cases<=T; cases++)
	{
        fscanf(input, "%lf %lf %lf", &C, &F, &X);
        
        f1 = 2.0;
        count = 1.0;
		ans = 0.0;

		while(1)
		{
		    f2 = 2.0 + F*count;
		    a = X/f1;
		    b = C/f1;
		    c = X/f2;

		    if( a > b + c )
		    {
		        ans += b;
		        f1 = f2;
		        count += 1.0;
		    }
		    else
		    {
		        ans += a;
		        break;
		    }
		}
		
		fprintf(output, "Case #%d: %.7lf\n", cases, ans);
		printf("Case #%d: %.7lf\n", cases, ans);
	}

	fclose(input);
	fclose(output);
}

