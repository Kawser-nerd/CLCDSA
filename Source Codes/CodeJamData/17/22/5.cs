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


		string col1 = "RBY";
		string col2 = "GOV";
		int[] p1, p2;
		int n;

		public Problem(TextReader r)
		{
			// 
			int[] s = ReadVectInt(r);
			n = s[0];

			p1 = new int[]{ s[1], s[5], s[3] };
			p2 = new int[]{ s[4], s[2], s[6] };


		}

		public string Solve()
		{
			string s = "";


			if (n == 1)
			{
				for (int i = 0; i < 3; i++)
				{
					if (p1[i] == 1) return "" + col1[i];
					if (p2[i] == 1) return "" + col2[i];
				}
			}

			for (int i = 0; i < 3; i++)
			{
				if (p2[i] == 0) continue;

				p1[i] -= p2[i];
				if (p1[i] < 0) return "IMPOSSIBLE";
			}

			if (p1[0] + p1[1] + p1[2] == 0)
			{
				for (int i = 0; i < 3; i++)
				{
					while (p2[i] != 0)
					{
						s = s + col2[i] + col1[i];
						p2[i]--;
					}
				}
			}



			int first, last;
			last = -1;
			first = -1;

			while (p1[0] + p1[1] + p1[2] > 0)
			{
				int best = 0;
				int besti = -1;

				for (int i = 0; i < 3; i++)
				{
					
					if ((p1[i] > best || p1[i] == best && i == first) && i != last)
					{
						best = p1[i];
						besti = i;
					}

				}

				if (besti == -1) return "IMPOSSIBLE";

				if (s.Length == 0) first = besti;
				last = besti;
				s = s + col1[besti];
				p1[besti]--;

				while (p2[besti] > 0)
				{
					p2[besti]--;
					s = s + col2[besti] + col1[besti];
				}

			}


			if (s.Length > 1 && s[0] == s[s.Length-1]) return "IMPOSSIBLE";
			if (p2[0] + p2[1] + p2[2] > 0) return "IMPOSSIBLE";


			string w = s + s[0];
			bool valid = true;
			for (int i = 0; i < s.Length; i++)
			{
				int a = col1.IndexOf(w[i]);
				int b = col1.IndexOf(w[i + 1]);
				int A = col2.IndexOf(w[i]);
				int B = col2.IndexOf(w[i + 1]);

				if (a == b) valid = false;
				if (a == -1 && b != A) valid = false;
				if (b == -1 && a != B) valid = false;

			}

			if (!valid) s += "zzz";

			return s;

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
