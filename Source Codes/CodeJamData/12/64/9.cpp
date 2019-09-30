#include <stdio.h>
#include <cmath>
#include <algorithm>
#define PI 3.1415926535897932

using namespace std;

int n, m;
int x[5000], y[5000];
int a[5000], b[5000];

int mx[4] = {1, 0, -1,  0};
int my[4] = {0, 1,  0, -1};

struct event_t
{
	int x, y;
	double angle;
} data[5000];
int dp;
double ans;

double angles[40000];
int ap;

bool operator < (const event_t& a, const event_t& b)
{
	return a.angle < b.angle;
}

double normalized (double angle)
{
	while (angle < -PI)
		angle  += PI * 2;
	while (angle > PI)
		angle -= PI * 2;
	return angle;
}

void getBest (double angle)
{
	double xx[4], yy[4];

//	printf ("getBest %lf\n", angle);

	for (int i = 0; i < 4; i ++)
		xx[i] = yy[i] = 0;

	for (int i = 0; i < 4; i ++)
	{
		int id = 0;
		long long len = cos(angle) * (long long)(a[0] * mx[i] + b[0] * my[i]) + sin(angle) * (long long)(a[0] * mx[(i + 1) % 4] + b[0] * my[(i + 1) % 4]);
		for (int j = 1; j < n; j ++)
		{
			long long cur = cos(angle) * (long long)(a[j] * mx[i] + b[j] * my[i]) + sin(angle) * (long long)(a[j] * mx[(i + 1) % 4] + b[j] * my[(i + 1) % 4]);

			if (cur > len)
			{
				len = cur;
				id = j;
			}
		}

		for (int j = 0; j < 4; j ++)
		{
			int mul = (std::max(m - j, 0) + (3-i)) / 4;
			xx[j] += mul * (double)(a[id] * mx[i] + b[id] * my[i]);
			yy[j] += mul * (double)(a[id] * mx[(i + 1) % 4] + b[id] * my[(i + 1) % 4]);
		}
	}

	for (int j = 0; j < 4; j ++)
	{
		if (sqrt (xx[j] * xx[j] + yy[j] * yy[j]) > ans)
			ans = sqrt (xx[j] * xx[j] + yy[j] * yy[j]);
	}
}

int main ()
{
	int t, ct = 0;

	for (scanf ("%d", &t); t > 0; t --)
	{
		scanf ("%d%d", &n, &m);

		dp = 0;

		bool haszero = false;
		for (int i = 0; i < n; i ++)
		{
			scanf ("%d%d", x + i, y + i);

			a[i] = x[i] - y[i];
			b[i] = x[i] + y[i];

			if (a[i] || b[i])
			{
				data[dp].x = a[i];
				data[dp].y = b[i];
				data[dp].angle = atan2(b[i], (double)a[i]);
				dp ++;
			}
			else 
				haszero = true;
		}

		sort(data, data + dp);

		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int i = 0; i < dp; i ++)
				while (dp > 1 && (data[i].x*data[i].x+data[i].y*data[i].y <= data[i].x*data[(i+1) % dp].x+data[i].y*data[(i+1) % dp].y ||
					data[i].x*data[i].x+data[i].y*data[i].y <= data[i].x*data[(i+dp-1) % dp].x+data[i].y*data[(i+dp-1) % dp].y))
				{
					for (int j = i; j < dp - 1; j ++)
						data[j] = data[j + 1];
					dp --;
					if (i > 0) i --;
					flag = true;
				}
		}

		ap = 0;
		for (int i = 0; i < dp; i ++)
		{
			int j = (i + 1) % dp;

			if (data[j].x*data[i].y - data[j].y*data[i].x < 0)
			{
				angles[ap ++] = atan2 (data[i].x - data[j].x, (double)data[j].y - data[i].y);
			}
			else if (data[j].x*data[i].y - data[j].y*data[i].x == 0)
			{
				if (data[j].x * data[i].x + data[j].y * data[i].y > 0)
					angles[ap ++] = atan2 (data[j].y, (double)data[j].x);
				else
				{
//					printf ("%d %d -- %d %d\n", data[i].x, data[i].y,data[j].x, data[j].y);
				}
			}
			else if (haszero)
			{
				angles[ap ++] = atan2 (-data[i].x, (double)data[i].y);
				angles[ap ++] = atan2 (-data[j].x, (double)data[j].y);
			}
			else
			{
				angles[ap ++] = atan2 (data[i].x - data[j].x, (double)data[j].y - data[i].y);
//				printf ("No zero found.\n");
			}
		}

//		printf ("dp = %d, ap = %d\n", dp, ap);
		for (int i = 0; i < ap; i ++)
		{
//			printf ("Angle: %lf\n", angles[i]);
			angles[i] = normalized(angles[i]);
			angles[i + ap] = normalized (angles[i] + PI / 2);
			angles[i + ap * 2] = normalized (angles[i] + PI);
			angles[i + ap * 3] = normalized (angles[i] + PI * 3/ 2);
		}
		ap *= 4;
		sort(angles, angles + ap);

		ans = 0;

		for (int i = 0; i < ap; i ++)
			::getBest ((angles[i + 1] + angles[i]) / 2);
		::getBest((angles[0] + angles[ap - 1]) / 2);
		::getBest((angles[0] + angles[ap - 1] + PI * 2) / 2);


		for (double xx = 0; xx <= 6.30; xx += 0.0001)
			::getBest ( xx);

		printf ("Case #%d: %.10lf\n", ++ ct, ans);
		fprintf (stderr, "Case #%d: %.10lf\n", ct, ans);
	}

	return 0;
}