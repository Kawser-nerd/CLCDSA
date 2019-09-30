#include <stdio.h>

int main()
{
	int T;
	
	scanf("%d", &T);
	
	for (int Q = 1; Q <= T; Q++)
	{
		double C, F, X;
		
		scanf("%lf %lf %lf", &C, &F, &X);
		
		double cps = 2,
		       t = 0,
		       best = X / 2,
		       total;
		
		while (t < best)
		{
			// buy a farm

			t += C / cps;
			cps += F;
			
			// go to end
			
			total = t + X / cps;
			
			if (total < best) best = total;
		}
		
		printf("Case #%d: %.7lf\n", Q, best);
	}
}