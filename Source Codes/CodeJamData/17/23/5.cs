using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;


namespace ProjectTemplate
{
	class Problem
	{

		public string[] ReadVect(TextReader r)
		{
			string[] x = r.ReadLine().Split(' ');
			return x;
		}

		public int[] ReadVectInt(TextReader r)
		{
			string[] x = ReadVect(r);
			int[] y = new int[x.Length];

			for (int i = 0; i < x.Length; i++)
				y[i] = int.Parse(x[i]);

			return y;
		}

		public long[] ReadVectLong(TextReader r)
		{
			string[] x = ReadVect(r);
			long[] y = new long[x.Length];

			for (int i = 0; i < x.Length; i++)
				y[i] = long.Parse(x[i]);

			return y;
		}


		public double[] ReadVectDouble(TextReader r)
		{
			string[] x = ReadVect(r);
			double[] y = new double[x.Length];

			for (int i = 0; i < x.Length; i++)
				y[i] = double.Parse(x[i]);

			return y;
		}

		int n, q;

		long[] e, s, u, v;

		long[,] d;


		public Problem(TextReader r)
		{
			long[] x = ReadVectLong(r);
			n = (int) x[0];
			q = (int)x[1];
			e = new long[n];
			s = new long[n];
			d = new long[n, n];
			u = new long[q];
			v = new long[q];

			for (int i = 0; i < n; i++)
			{
				x = ReadVectLong(r);
				e[i] = x[0];
				s[i] = x[1];
			}

			for (int i = 0; i < n; i++)
			{
				x = ReadVectLong(r);
				for (int j = 0; j < n; j++)
				{
					d[i, j] = x[j];
				}
			}

			for (int i = 0; i < q; i++)
			{
				x = ReadVectLong(r);
				u[i] = x[0];
				v[i] = x[1];
			}

		}

		public string Solve()
		{
			for (int k = 0; k < n; k++)
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
					{
						if (d[i, k] == -1 || d[k, j] == -1) continue;
						if (d[i, j] == -1 || d[i, j] > d[i, k] + d[k, j])
							d[i, j] = d[i, k] + d[k, j];
					
					}


			double[,] dd = new double[n, n];

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					if (i == j) continue;
					if (d[i, j] == -1 || d[i, j] > e[i])
					{
						dd[i, j] = 1e20;
						continue;
					}
					double time = d[i, j] * 1.0 / s[i];
					dd[i, j] = time;
				}

			for (int k = 0; k<n; k++)
				for (int i = 0; i<n; i++)
					for (int j = 0; j<n; j++)
						if (dd[i, j] > dd[i, k] + dd[k, j])
							dd[i, j] = dd[i, k] + dd[k, j];

			string ret = "";
			for (int i = 0; i < q; i++)
			{
				if (i > 0) ret = ret + " ";
				ret = ret + dd[u[i]-1, v[i]-1].ToString();
			}

			return ret;
		}

	}

	class MainClass
	{
		public static void Main(string[] args)
		{
			if (args.Length != 1)
			{
				Console.WriteLine("Please specify input file");
				return;
			}
			TextReader r = new StreamReader(args[0]);
			string outputname = args[0].Replace(".in", ".out");
			if (outputname.Equals(args[0])) outputname = args[0] + ".out";

			TextWriter w = new StreamWriter(outputname);
			int t = int.Parse(r.ReadLine());

			for (int i = 1; i <= t; i++)
			{
				Problem p = new Problem(r);
				string answer = p.Solve();
				Console.WriteLine("Case #{0}: {1}", i, answer);
				w.WriteLine("Case #{0}: {1}", i, answer);
			}

			w.Close();
			r.Close();
		}
	}
}
