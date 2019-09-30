#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793238

double getSafeArea(double, double, double, double, double);
double getAngle(double, double, double, double);

int main(void)
{
	int k, i, j, iMax;
	int N;
	double f, R, t, r, g;
	double eR;
	double x1, y1, x2, y2;
	double safeArea;
	double P;

	scanf("%d", &N);

	for (k = 0; k < N; ++k)
	{
		scanf("%lf %lf %lf %lf %lf", &f, &R, &t, &r, &g);
		eR = R - t - f;
		iMax = (int)((eR - r - f) / (g + 2 * r));

		safeArea = 0;
		if (g <= 2 * f // gap is too small
			|| eR < 0 // interior of the racquet is smaller than fly
			|| eR < sqrt(2) * r // string is too thick
		   )
		{
			// safeArea = 0;
			// Do nothing
		}
		else
		{
			for (i = 1; i <= iMax; ++i)
			{
				for (j = 0; j < i; ++j)
				{
					x1 = (r + f) + (g + 2 * r) * i;
					y1 = (r + f) + (g + 2 * r) * j;

					if (x1 * x1 + y1 * y1 > eR * eR) break;

					x2 = (r + g - f) + (g + 2 * r) * i;
					y2 = (r + g - f) + (g + 2 * r) * j;

					if (x2 * x2 + y2 * y2 < eR * eR)
					{
						safeArea += (g - 2 * f) * (g - 2 * f);
					}
					else
					{
						safeArea += getSafeArea(x1, y1, x2, y2, eR);
					}
				}
			}

			for (i = 0; i <= iMax; ++i)
			{
				x1 = y1 = (r + f) + (g + 2 * r) * i;
				x2 = y2 = (r + g - f) + (g + 2 * r) * i;

				if (sqrt(2) * x1 > eR) break;

				if (x2 * x2 + y2 * y2 < eR * eR)
				{
					safeArea += (g - 2 * f) * (g - 2 * f) / 2;
				}
				else
				{
					safeArea += getSafeArea(x1, y1, x2, y2, eR) / 2;
				}
			}
		}

		P = 1 - 4 * 2 * safeArea / (PI * R * R);

		printf("Case #%d: %f\n", k + 1, P);
	}

	return 0;
}

double getSafeArea(double x1, double y1, double x2, double y2, double eR)
{
	double safeArea = 0;
	double x3, x4, y3, y4;

	if (eR * eR < x1 * x1 + y2 * y2)
	{
		x3 = sqrt(eR * eR - y1 * y1);
		y3 = sqrt(eR * eR - x1 * x1);

		safeArea = eR * eR * getAngle(x3, y1, x1, y3) / 2 
					- ((y3 - y1) * x1 + (x3 - x1) * y1) / 2;
	}
	else if (eR * eR < x2 * x2 + y1 * y1)
	{
		x3 = sqrt(eR * eR - y1 * y1);
		x4 = sqrt(eR * eR - y2 * y2);
		y3 = y2 / x4 * x1;
	
		safeArea = eR * eR * getAngle(x3, y1, x4, y2) / 2
					- ((y3 - y1) * x1 + (x3 - x1) * y1) / 2
					+ (y2 - y3) * (x4 - x1) / 2;
	}
	else
	{
		x4 = sqrt(eR * eR - y2 * y2);
		y4 = sqrt(eR * eR - x2 * x2);
		y3 = y2 / x4 * x1;
		x3 = x2 / y4 * y1;

		safeArea = eR * eR * getAngle(x2, y4, x4, y2) / 2
					- ((y3 - y1) * x1 + (x3 - x1) * y1) / 2
					+ ((y2 - y3) * (x4 - x1) + (x2 - x3) * (y4 - y1)) / 2;
	}

	return safeArea;
}

double getAngle(double x1, double y1, double x2, double y2)
{
	return acos((x1 * x2 + y1 * y2)
				/ sqrt(x1 * x1 + y1 * y1) / sqrt(x2 * x2 + y2 * y2));
}
