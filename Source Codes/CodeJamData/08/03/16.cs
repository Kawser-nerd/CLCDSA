using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class Program
{
	static int N;
	static double f, R, t, r, g;
	static double dist(double x, double y)
	{
		return Math.Sqrt(x * x + y * y);
	}
	static double F(double R, double x)
	{
		return 0.5 * x * Math.Sqrt(R * R - x * x) + 0.5 * R * R * Math.Atan(x / Math.Sqrt(R * R - x * x));
	}
	static void Main(string[] args)
	{
		string infile = "c-large.in";
		string outfile = "c-large.out";
		TextReader tr = new StreamReader(infile);
		TextWriter tw = new StreamWriter(outfile);
		N = int.Parse(tr.ReadLine());		
		for (int i = 0; i < N; ++i)
		{
			string[] tmp = tr.ReadLine().Split(' ');
			f = double.Parse(tmp[0], System.Globalization.CultureInfo.InvariantCulture);
			R = double.Parse(tmp[1], System.Globalization.CultureInfo.InvariantCulture);
			t = double.Parse(tmp[2], System.Globalization.CultureInfo.InvariantCulture);
			r = double.Parse(tmp[3], System.Globalization.CultureInfo.InvariantCulture);
			g = double.Parse(tmp[4], System.Globalization.CultureInfo.InvariantCulture);
			double d = g - 2 * f;
			double step = 2 * r + 2 * f;
			double begin = r + f;
			double maxr = R - t - f;
			double prop;			
			if (2 * f >= g) prop = 1;
			else
			{
				double square=0;
				for (double x = begin; x <= R; x+=step+d)
				{
					for (double y = begin; y <= R; y += step+d)
					{
						if (dist(x, y) >= maxr) continue;
						if (dist(x + d, y + d) <= maxr)
						{
							square += d * d;
						}
						else
						{
							double xsh, xsh2, ysh;
							ysh = Math.Sqrt(maxr * maxr - x * x);
							if (ysh < y + d) xsh = x;
							else
							{
								xsh = Math.Sqrt(maxr * maxr - (y + d) * (y + d));
								square += d * (xsh - x);
							}
							xsh2 = Math.Sqrt(maxr * maxr - y * y);
							if (xsh2 > x + d) xsh2 = x + d;
							square += F(maxr, xsh2) - F(maxr, xsh) - y * (xsh2 - xsh);
						}
					}
				}
				prop = 1.0 - 4.0 * square / (Math.PI * R * R);
			}
			tw.WriteLine(string.Format(	System.Globalization.CultureInfo.InvariantCulture,
				"Case #{0}: {1}", i + 1, prop
				));
		}
		tw.Close();
	}
}
