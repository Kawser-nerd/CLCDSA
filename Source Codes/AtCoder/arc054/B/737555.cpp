#include <stdio.h>
#include <math.h>

double p;

double c( double x) { return p / exp2l(x / 1.5) + x; }

int main()
{
	scanf("%lf",&p);
	double ans;

	double ub = 100.0, lb = 0.0;
	double lp = lb,mp = (lb + ub) / 2.0,rp = ub;
	for (int i = 0; i < 10000; ++i)
	{
		double lc = c(lp);
		double mc = c(mp);
		double rc = c(rp);
		int fl = 0;
		if (lc <= mc && lc <= rc)fl = 0;
		if (mc <= lc && mc <= rc)fl = 1;
		if (rc <= lc && rc <= mc)fl = 2;
		switch (fl)
		{
		case 0:
			ub = mp;
			//rp = ub; mp = lb; lp = mp - (rp - mp);
			rp = ub; lp = lb; mp = (lp + rp) / 2.0;
			break;
		case 1:
			ub = rp;
			lb = lp;
			lp = (ub + lb) / 2.0; rp = ub; mp = (lp + rp) / 2.0;
			break;
		case 2:
			lb = mp;
			//lp = lb; mp = ub; rp = mp + (mp - lp);
			lp = lb; rp = ub; mp = (lp + rp) / 2.0;
			break;
		}
	}

	ans = c(ub);

	printf("%.10lf\n",ans);
	return 0;
}