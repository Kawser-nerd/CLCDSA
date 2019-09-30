using System;
using System.Collections.Generic;
using System.Text;

public class D
{
	static Random rand = new Random ();
	public static void Main ()
	{
		int n = int.Parse (Console.ReadLine ());
		D task = new D ();

		for (int i = 1; i <= n; ++i)
			Console.WriteLine ("Case #{0}: {1}", i, task.Solve ());
	}

	double[] X, Y, R;
	int n;

	double dist (double x1, double y1, double x2, double y2)
	{
		return Math.Sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	}

	bool inside (int i, double x, double y, double r)
	{
		double d = dist (x, y, X[i], Y[i]);

		return d <= r - R[i] + 1E-6;
	}

	long getmask (double x, double y, double r)
	{
		long mask = 0;
		for (int i = 0; i < n; ++i)
			if (inside (i, x, y, r))
				mask |= 1L << i;

		return mask;
	}

	double calcr (int i, out long mask)
	{
		mask = getmask (X[i], Y[i], R[i]);
		return R[i];
	}

	double calcr (int i, int j, out long mask)
	{
		if (i == j)
			return calcr (i, out mask);

		double dt = dist (X[i], Y[i], X[j], Y[j]);

		double r = (dt + R[i] + R[j]) / 2.0;
		double d1 = r - R[i];

		double x = X[i] + (X[j] - X[i]) * d1 / dt;
		double y = Y[i] + (Y[j] - Y[i]) * d1 / dt;

		mask = getmask (x, y, r);
		return r;
	}

	double getr (int i, int j, int k, double x, double y)
	{
		double r = 0;

		r = Math.Max (r, dist (X[i], Y[i], x, y) + R[i]);
		r = Math.Max (r, dist (X[j], Y[j], x, y) + R[j]);
		r = Math.Max (r, dist (X[k], Y[k], x, y) + R[k]);

		return r;
	}

	void getr2 (int i, int j, int k, double x, double y)
	{
		Console.WriteLine (dist (X[i], Y[i], x, y) + R[i]);
		Console.WriteLine (dist (X[j], Y[j], x, y) + R[j]);
		Console.WriteLine (dist (X[k], Y[k], x, y) + R[k]);
	}

	double calcr (int i, int j, int k, out long mask)
	{
		if (i == j)
			return calcr (i, k, out mask);
		if (i == k)
			return calcr (i, j, out mask);
		if (j == k)
			return calcr (i, j, out mask);

		double x = (X[i] + X[j] + X[k]) / 3.0;
		double y = (Y[i] + Y[j] + Y[k]) / 3.0;
		double r = getr (i, j, k, x, y);

		for (int qq = 0; qq < 100; ++qq)
		{
//			getr2 (i, j, k, x, y);

			double q = rand.NextDouble () * 2 * Math.PI;
			double dx = Math.Sin (q);
			double dy = Math.Cos (q);
			double coef = 1E-7;

			double rr = getr (i, j, k, x + dx * coef, y + dy * coef);
			if (rr > r)
				continue;

			double rrr = getr (i, j, k, x + dx * 2 * coef, y + dy * 2 * coef);
			while (rrr < rr)
			{
				coef *= 2;

				rr = rrr;
				rrr = getr (i, j, k, x + dx * 2 * coef, y + dy * 2 * coef);
			}

			double coef0 = coef / 2;
			double coef1 = coef;

			while (coef1 - coef0 > 1E-7)
			{
				double coefa = (2 * coef0 + coef1) / 3.0;
				double coefb = (coef0 + 2 * coef1) / 3.0;
				double rra = getr (i, j, k, x + dx * coefa, y + dy * coefa);
				double rrb = getr (i, j, k, x + dx * coefb, y + dy * coefb);

				if (rra > rrb)
					coef0 = coefa;
				else
					coef1 = coefb;
			}

			x += dx * coef0;
			y += dy * coef0;
			r = getr (i, j, k, x, y);
		}

		mask = getmask (x, y, r);
		return r;
	}

	public string Solve ()
	{
		n = int.Parse (Console.ReadLine ());

		X = new double[n];
		Y = new double[n];
		R = new double[n];

		for (int i = 0; i < n; ++i)
		{
			string[] ss = Console.ReadLine ().Split (' ');
			X[i] = int.Parse (ss[0]);
			Y[i] = int.Parse (ss[1]);
			R[i] = int.Parse (ss[2]);
		}

		double[,,] rr = new double[n, n, n];
		long[,,] mm = new long[n, n, n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < n; ++k)
			{
					rr[i, j, k] = calcr (i, j, k, out mm[i, j, k]);
			}

		double res = 1E50;

		long tmask = (1L << n) - 1;
		for (int i0 = 0; i0 < n; ++i0)
			for (int j0 = 0; j0 < n; ++j0)
				for (int k0 = 0; k0 < n; ++k0)
					for (int i1 = 0; i1 < n; ++i1)
						for (int j1 = 0; j1 < n; ++j1)
							for (int k1 = 0; k1 < n; ++k1)
								if ((mm[i0, j0, k0] | mm[i1, j1, k1]) == tmask)
									res = Math.Min (res, Math.Max (rr[i0, j0, k0], rr[i1, j1, k1]));

		return res.ToString ();
	}
}
