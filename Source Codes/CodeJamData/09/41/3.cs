using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Google_Code_Jam
{
	class problemA
	{
		public static void Solve(TextReader tr, TextWriter tw)
		{
			int T = int.Parse(tr.ReadLine());
			for (int i = 1; i <= T; i++)
			{
				int N = int.Parse(tr.ReadLine());
				int[] last = new int[N];
				for (int j = 0; j < N; j++)
				{
					string s = tr.ReadLine();
					last[j] = s.LastIndexOf('1');
				}
				int ans = 0;
				for (int k = 0; k < N; k++)
				{
					int j = k;
					while (last[j] > k)
						j++;
					for (int q = j; q > k; q--)
						last[q] = last[q - 1];
					ans += (j - k);
				}
				tw.WriteLine(String.Format("Case #{0}: {1}", i, ans));
			}
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			TextReader tr = new StreamReader(@"C:\GCJ\A-large.in");
			TextWriter tw = new StreamWriter(@"C:\GCJ\A-large.out");
			problemA.Solve(tr, tw);
			tr.Close(); tw.Close();
		}
	}
}
