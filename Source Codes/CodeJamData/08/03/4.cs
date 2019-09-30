using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace GCJ_2008
{
	class FlySwatter: CommonProblem
	{
		public override void ProcessCase(TextReader reader, TextWriter writer)
		{
			double f, R, t, r, g;
			ParseInputLine<double, double, double, double, double>(reader, out f, out R, out t, out r, out g);

			Console.WriteLine("f={0} R={1} t={2} r={3} g={4}", f, R, t, r, g);

			double ret = 0.0f;
			if (2 * f > g) {
				ret = 1.0000000f;
			} else {
				double sum = R * R * Math.PI * 0.25;
				double survive = 0.0f;

				double R2 = (R - t - f) * (R - t - f);
				for (double y = r; y < R; y += g + 2 * r) {
					for (double x = r; x < R; x += g + 2 * r) {
						double d = x * x + y * y;
						if (d > R2)
							continue;

						double d2 = (x + g) * (x + g) + (y + g) * (y + g);

						if (d2 < R2) {
							survive += (g - 2 * f) * (g - 2 * f);
						} else { 
							survive += Integral(x + f, y + f, g - 2 * f, R - t - f);
						}
					}
				}
				ret = 1.0f - survive / sum;
			}

			writer.WriteLine("{0:F6}", ret);
		}

		public double Integral(double x0, double y0, double r, double R)
		{
			double dx = r / 20000.0;
			double ret = 0.0;
			for (double x = x0; x < x0 + r; x += dx) {
				if (x > R)
					break;

				double y = Math.Sqrt(R * R - x * x);
				
				double dy;
				if (y > y0 + r) {
					dy = r;
				} else if (y < y0) {
					dy = 0.0f;
				} else {
					dy = y - y0;
				}

				ret += dx * dy;
			}
			// Console.WriteLine("Calc x0={0} y0={1} r={2} R={3} ret={4}", x0, y0, r, R, ret);
			return ret;
		}

		public override void Test()
		{
			ProcessTest("0.25 1.0 0.1 0.01 0.5");
			ProcessTest("0.25 1.0 0.1 0.01 0.9");
			ProcessTest("0.00001 10000 0.00001 0.00001 1000");
			ProcessTest("0.4 10000 0.00001 0.00001 700");
			ProcessTest("1 100 1 1 10");
		}
	}
}
