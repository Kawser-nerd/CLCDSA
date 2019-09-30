// made by diver_ru, made with love
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

public class Solver
{
	TextWriter Out;
	TextReader In;

	int readInt()
	{
		return int.Parse(In.ReadLine());
	}


	double sqr(double a)
	{
		return a * a;
	}
	double dist(double x1, double y1, double x2, double y2)
	{
		return Math.Sqrt(sqr(x1 - x2) + sqr(y1 - y2));
	}

	private void Solve()
	{
		In = new StreamReader("../../input.txt");
		Out = new StreamWriter("../../output.txt");

		int cntCases = readInt();
		for (int k = 1; k <= cntCases; ++k)
		{
			
			int N = readInt();
			double res = int.MaxValue;
			int[] x = new int[N], y = new int[N], R = new int[N];
			for (int i = 0; i < N; ++i)
			{
				String[] s = In.ReadLine().Split();
				x[i] = int.Parse(s[0]);
				y[i] = int.Parse(s[1]);
				R[i] = int.Parse(s[2]);
			}
			if (N == 1)
				res = R[0];
			else if (N == 2)
				res = Math.Max(R[0], R[1]);
			else
			{
				for (int i = 0; i < N; ++i)
					for (int j = i + 1; j < N; ++j)
					{
						res = Math.Min(res,
							Math.Max((dist(x[i], y[i], x[j], y[j]) + R[i] + R[j]) / 2.0, R[0 + 1 + 2 - i - j]));
					}
			}

			Out.WriteLine("Case #{0}: {1}", k, res.ToString("0.00000000").Replace(',', '.'));
		}

		In.Close();
		Out.Close();
	}

	// BEGIN CUT HERE
	public static void Main(string[] args)
	{
		new Solver().Solve();
	}
	// END CUT HERE
}
