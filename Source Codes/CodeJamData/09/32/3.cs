using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace task2
{
	class Program
	{
		static void Main(string[] args)
		{
			var splitters = new char[] { ' ', '\t' };
			TextReader reader = null;
			TextWriter writer = null;
			try
			{
				reader = new StreamReader(args[0], Encoding.ASCII);
				writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII);
				var cases = int.Parse(reader.ReadLine());
				Console.WriteLine("Number of cases {0}", cases);
				for (var k = 1; k <= cases; ++k)
				{
					var n = int.Parse(reader.ReadLine());
					var X0 = 0L;
					var Y0 = 0L;
					var Z0 = 0L;
					var Vx = 0L;
					var Vy = 0L;
					var Vz = 0L;
					for (var i = 0; i < n; ++i)
					{
						var vars = reader.ReadLine().Split(splitters);
						X0 += long.Parse(vars[0]);
						Y0 += long.Parse(vars[1]);
						Z0 += long.Parse(vars[2]);
						Vx += long.Parse(vars[3]);
						Vy += long.Parse(vars[4]);
						Vz += long.Parse(vars[5]);
					}
					double x = X0;
					double y = Y0;
					double z = Z0;
					double d = 0;
					double t = 0;
					if (Vx == 0 && Vy == 0 && Vz == 0)
					{
						d = Math.Sqrt(x * x + y * y + z * z) / n;
					}
					else
					{
						double vxd = Vx;
						double vyd = Vy;
						double vzd = Vz;
						double temp = -vxd * x - vyd * y - vzd * z;
						if (temp <= 0)
						{
							d = Math.Sqrt(x * x + y * y + z * z) / n;
						}
						else
						{
							t = temp / (vxd * vxd + vyd * vyd + vzd * vzd);
							temp = (t * vxd + x) * (t * vxd + x)
								+ (t * vyd + y) * (t * vyd + y)
								+ (t * vzd + z) * (t * vzd + z);
							d = Math.Sqrt(temp) / n;
						}
					}
					var result = String.Format(CultureInfo.InvariantCulture,"Case #{0}: {1:F8} {2:F8}", k, d, t);
					Console.WriteLine(result);
					writer.WriteLine(result);
				}
			}
			finally
			{
				if (writer != null)
					writer.Close();
				if (reader != null)
					reader.Close();
			}
		}
	}
}