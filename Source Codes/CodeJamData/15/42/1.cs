using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class B
{
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			string[] ps = Console.ReadLine().Split();
			int N = int.Parse(ps[0]);
			double V = double.Parse(ps[1]);
			double X = double.Parse(ps[2]);
			double[] R = new double[N];
			double[] C = new double[N];
			for (int i = 0; i < N; i++)
			{
				ps = Console.ReadLine().Split();
				R[i] = double.Parse(ps[0]);
				C[i] = double.Parse(ps[1]);
			}

			if (N == 1)
			{
				if (C[0] == X)
				{
					double t0 = V / R[0];
					Console.WriteLine("Case #" + CASE + ": " + t0);
				}
				else
				{
					Console.WriteLine("Case #" + CASE + ": IMPOSSIBLE");
				}

				continue;
			}
			else if (N == 2 && C[0] == X && C[1] == X)
			{
				double t0 = V / (R[0] + R[1]);
				Console.WriteLine("Case #" + CASE + ": " + t0);
				continue;
			}

			if (N > 2)
			{
				Console.WriteLine("Case #" + CASE + ": TODO");
				continue;
			}

			double V0 = (X * V - V * C[1]) / (C[0] - C[1]);
			bool can = !((C[0] < X && C[1] < X) || (C[0] > X && C[1] > X));

			if (can)
			{
				double t0 = V0 / R[0];
				double t1 = (V - V0) / R[1];
				Console.WriteLine("Case #" + CASE + ": " + Math.Max(t0, t1));
			}
			else
			{
				Console.WriteLine("Case #" + CASE + ": IMPOSSIBLE");

			}
		}
	}
}
