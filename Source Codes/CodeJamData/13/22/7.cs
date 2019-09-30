using System;
using System.IO;
using System.Collections.Generic;

namespace b
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
				double ret = 0;
				int[] v = intvec (r.ReadLine ());
				int x,y,n,m ;

				n = v[0]; 
				x = v[1];
				y = v[2];

				int tot = 1;

				for(m = 1; ; m+=2)
				{
					if (tot + 2*(m+1)+1 > n)
						break;

					tot += 2*(m+1)+1;
				
				}

				x = Math.Abs (x);
				if (x+y <= m)
					ret = 1;
				else if (x+y == m+1)
				{
					n = n - tot;
					double[,] p = new double[n+1, n+1];

					p[0,0] = 1;	

					for(int i = 0; i<n; i++)
					{
						for(int j = 0; j<=i; j++)
						{
							if (i-j >= m+1)
								p[i+1, j+1] += p[i,j];
							else if (j >= m+1)
								p[i+1, j] += p[i,j];
							else {
								p[i+1,j] += p[i,j]*0.5;
								p[i+1,j+1] += p[i,j]*0.5;
							}
						}
					}

					ret = 0;

					for(int i = y+1; i<=n; i++) 
						ret += p[n, i];

				}

				Console.WriteLine ("Case #{0}: {1}", c, ret);
				w.WriteLine ("Case #{0}: {1}", c, ret);
			}
			
			w.Close ();
			
		}

	}
}
