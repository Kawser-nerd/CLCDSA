using System;
using System.IO;
using System.Collections.Generic;

namespace a
{
	class MainClass
	{
		public static int[] intvec(string s)
		{
			string[] x = s.Split (' ');
			int[] ret = new int[x.Length];
			for(int i = 0; i<ret.Length; i++)
				ret[i] = int.Parse (x[i]);

			return ret;
		}

		public static void Main (string[] args)
		{
			TextReader r = new StreamReader(args[0]);
			TextWriter w = new StreamWriter(args[1]);

			int t = int.Parse (r.ReadLine ());

			for(int c = 1; c <= t; c++)
			{
				string ret = "";
				int[] x = intvec(r.ReadLine());
				int m = x[0];
				int n = x[1];


				int[] v= intvec (r.ReadLine ());

				int min = n;

				Array.Sort(v);
				int z = 0;
				if (m > 1)
				for(int i = 0; i<n; i++)
				{

					while (m <= v[i])
					{
						m = m + m - 1;
						z++;
					}

					m += v[i];
					if (z+n-i-1 < min)
						min = z+n-i-1;

				}

				Console.WriteLine ("Case {0}", c);
				w.WriteLine ("Case #{0}: {1}", c, min);
			}

			w.Close ();

		}
	}
}
