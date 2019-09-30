using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Codejame
{
	class Program
	{

		static void Main(string[] args)
		{
			StreamReader reader = new StreamReader(@"C:\A-large.in");
			StreamWriter writer = new StreamWriter(@"C:\A-large.out");

			int T = Convert.ToInt32(reader.ReadLine());
			for (int k = 1; k <= T; k++)
			{
				int ans = 0;

				int N = Convert.ToInt32(reader.ReadLine());

				int[] a = new int[N];
				int[] b = new int[N];

				for (int i = 0; i < N; i++)
				{
					string[] s = reader.ReadLine().Split(' ');
					a[i] = Convert.ToInt32(s[0]);
					b[i] = Convert.ToInt32(s[1]);
				}

				for (int i = 0; i < N; i++)
					for (int j = 0; j < i; j++)
						if (a[i] > a[j] != b[i] > b[j]) ans++;
				
				
				writer.WriteLine(String.Format("Case #{0}: {1}", k, ans));
			}

			writer.Close();
			reader.Close();
		}
	}
}
