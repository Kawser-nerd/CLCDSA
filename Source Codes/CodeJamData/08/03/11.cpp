#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

long double f, R, t, r, g, Rin;

long double PI = acos(0) * 2;
long double fMIN = 1e-15;

long double secArea(long double sec)
{
	long double halfAngle = asin(sec/2/Rin);
	long double pieArea = halfAngle * Rin * Rin;
	long double triangleArea = sec * (Rin * cos(halfAngle)) / 2;
	return pieArea - triangleArea;
}

long double dis(long double x1, long double y1, long double x2, long double y2)
{
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

long double circleEval(long double p)
{
	if (p <= -Rin || p >= Rin)
		return -1.0;

	return sqrt(Rin * Rin - p * p);
}

long double emptyArea(long double x, long double y)
{
	long double xEnd = x + g;
	long double yEnd = y + g;
	long double xyDis = dis(0.0, 0.0, x, y);
	long double xEndDis = dis(0.0, 0.0, xEnd, y);
	long double yEndDis = dis(0.0, 0.0, x, yEnd);
	long double xyEndDis = dis(0.0, 0.0, xEnd, yEnd);
	long double xEval = circleEval(xEnd) - y;
	long double yEval = circleEval(yEnd) - x;
	long double xBigEval = circleEval(x) - y;
	long double yBigEval = circleEval(y) - x;
	if (xyDis >= Rin)
		return 0.0;
	if (xyEndDis <= Rin)
		return g * g;
	if (xEndDis <= Rin && yEndDis <= Rin)
		return g * g - (g-yEval)*(g-xEval)/2 + secArea(dis(yEval, g, g, xEval));
	if (xEndDis > Rin && yEndDis <= Rin)
		return yEval * g + (yBigEval - yEval) * g / 2 + secArea(dis(yBigEval, 0.0, yEval, g));
	if (xEndDis <= Rin && yEndDis > Rin)
		return xEval * g + (xBigEval - xEval) * g / 2 + secArea(dis(0.0, xBigEval, g, xEval));
	// if (xEndDis > Rin && yEndDis > Rin)
		return xBigEval * yBigEval / 2 + secArea(dis(0.0, xBigEval, yBigEval, 0.0));
}

int main()
{
	int numCase;
	scanf("%d", &numCase);
	int i, j, k;
	for (i = 0; i < numCase; i++)
	{
		cin >> f >> R >> t >> r >> g;
		t += f;
		r += f;
		g -= 2*f;
		Rin = R - t;
		long double totalArea = PI * R * R;
		long double area = totalArea;

		if (g > 0.0)
		{
			for (j = 0; j < 1100; j++)
			{
				for (k = 0; k < 1100; k++)
				{
					long double curEmpty = emptyArea(r + j * (g + r + r), r + k * (g + r + r));
					if (curEmpty < fMIN)
						break;
					area -= curEmpty;
				}
			}
			area -= 3 * (totalArea - area);
		}
		cout << "Case #" << i+1 << ": " << area / totalArea << endl;
	}
	return 0;
}
