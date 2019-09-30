#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

ifstream in;
ofstream out;

int main(int argc, char** argv)
{
	in.open(argv[1]);
	out.open(argv[2]);

	int T;
	in >> T;

	for(int it = 1; it <= T; ++it)
	{
		int N;
		in >> N;

		double x0 = 0;
		double y0 = 0;
		double z0 = 0;
		double xv = 0;
		double yv = 0;
		double zv = 0;

		for(int i = 0; i < N; ++i)
		{
			int x, y, z, vx, vy, vz;
			in >> x >> y >> z >> vx >> vy >> vz;

			x0 += x;
			y0 += y;
			z0 += z;

			xv += vx;
			yv += vy;
			zv += vz;
		}

		double vv = xv * xv + yv * yv + zv * zv;
		double t = 0.0;

		if(vv)
		{
			t = (- x0 * xv - y0 * yv - z0 * zv) / vv;
			if(t < 0)
				t = 0;
		}

		double dmin = sqrt(((x0 + xv * t) * (x0 + xv * t) + (y0 + yv * t) * (y0 + yv * t) + (z0 + zv * t) * (z0 + zv * t)) / N / N);

		out << "Case #" << it << ": " << fixed << setprecision(8) << dmin << ' ' << t << endl;
	}

	return 0;
}
