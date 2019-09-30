using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2009
{
	class CenterOfMass
	{
		public void SloveFile(string file)
		{
			using (StreamReader inf = new StreamReader(file, Encoding.ASCII))
			using (StreamWriter outf = new StreamWriter(file + ".out", false, Encoding.ASCII)) {
				int cases = int.Parse(inf.ReadLine());
				for (int i = 1; i <= cases; i++) {
					int n = int.Parse(inf.ReadLine());
					string[] inputs = new string[n];
					for (int j = 0; j < n; j++) {
						inputs[j] = inf.ReadLine();
					}
					double dmin;
					double tmin;
					Slove(inputs, out dmin, out tmin);
					outf.WriteLine("Case #{0}: {1:F10} {2:F10}", i, dmin, tmin);
					Console.WriteLine("Case #{0}: {1} {2}", i, dmin, tmin);
				}
			}
		}
		public void Slove(string[] inputs, out double dmin, out double tmin)
		{
			int n = inputs.Length;
			double sx = 0, sy = 0, sz = 0, svx = 0, svy = 0, svz = 0;
			for (int i = 0; i < inputs.Length; i++) {
				string[] ss = inputs[i].Split();
				int x = int.Parse(ss[0]);
				int y = int.Parse(ss[1]);
				int z = int.Parse(ss[2]);
				int vx = int.Parse(ss[3]);
				int vy = int.Parse(ss[4]);
				int vz = int.Parse(ss[5]);
				sx += x;
				sy += y;
				sz += z;
				svx += vx;
				svy += vy;
				svz += vz;
			}

			double a = (svx * svx + svy * svy + svz * svz) / (n * n);
			double b = 2 * (sx * svx + sy * svy + sz * svz) / (n * n);
			double c = (sx * sx + sy * sy + sz * sz) / (n * n);

			Console.WriteLine("a = {0} b = {1} c = {2}", a, b, c);
			if (b * b <= 4 * a * c) {
				Console.WriteLine("b*b < 4*a*c Maybe no solution");
			}
			if (a >= -0.0000001f && a <= 0.0000001f) {
				tmin = 0.0f;
			} else {
				tmin = -b / (2 * a);
			}
			if (tmin < 0.0f) {
				tmin = 0.0f;
			}

			double fmin = a * tmin * tmin + b * tmin + c;
			if (fmin > 0.0f)
				dmin = Math.Sqrt(fmin);
			else {
				dmin = 0.0f;
				Console.WriteLine("Minus: {0}", fmin);
			}
		}
	}
}
