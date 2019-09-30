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

		int d, n;
		int[] k, s;

		public Problem(TextReader r)
		{
			int[] x = ReadVectInt(r);
			d = x[0]; n = x[1];
			k = new int[n];
			s = new int[n];

			for (int i = 0; i < n; i++)
			{
				x = ReadVectInt(r);
				k[i] = x[0];
				s[i] = x[1];
			}
		}

		public string Solve()
		{
			double max = 0;

			for (int i = 0; i < n; i++)
			{
				double t = (d - k[i])*1.0 / s[i];


				if (t > max) max = t;
			}

			double m = d / max;
			return m.ToString();
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
