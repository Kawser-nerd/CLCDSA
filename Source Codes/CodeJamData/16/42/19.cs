using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using NUnit.Framework;

namespace task2
{
	[TestFixture]
	public class Program
	{
		static void Main(string[] args)
		{
			using (var reader = new StreamReader(args[0], Encoding.ASCII))
			using (var writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII))
			{
				var cases = int.Parse(reader.ReadLine());
				Console.WriteLine("Cases {0}", cases);
				for (var i = 1; i <= cases; ++i)
				{
					var parameters = reader.ReadLine().Split(' ');
					var N = int.Parse(parameters[0]);
					var K = int.Parse(parameters[1]);
					var p = reader.ReadLine().Split(' ').Select(_ => double.Parse(_, CultureInfo.InvariantCulture)).ToArray();
					var pYes = new double[K + 1];
					pYes[0] = 1.0;
					var r = Solve(p, pYes, 0, 0);
					var result = string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", i, r);
					writer.WriteLine(result);
				}
			}
		}

		private static double Solve(double[] p, double[] pYes, int taken, int nextCandidateIndex)
		{
			var k = pYes.Length - 1;
			if (taken == k)
			{
				return pYes[k / 2];
			}

			var yesP = p[nextCandidateIndex];
			var noP = 1 - yesP;
			//try take
			var pYesTake = (double[])pYes.Clone();
			pYesTake[0] = pYes[0] * noP;
			for (var i = 1; i <= taken + 1; ++i)
			{
				pYesTake[i] = pYes[i - 1] * yesP + pYes[i] * noP;
			}
			var r1 = Solve(p, pYesTake, taken + 1, nextCandidateIndex + 1);
			var r2 = -1.0;
			if (p.Length - nextCandidateIndex > k - taken)
			{
				var pYesNotTake = (double[])pYes.Clone();
				r2 = Solve(p, pYesNotTake, taken, nextCandidateIndex + 1);
			}
			return Math.Max(r1, r2);
		}
	}
}
