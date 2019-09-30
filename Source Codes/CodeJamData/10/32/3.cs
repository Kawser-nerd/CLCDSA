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
			StreamReader reader = new StreamReader(@"C:\B-large.in");
			StreamWriter writer = new StreamWriter(@"C:\B-large.out");

			int T = Convert.ToInt32(reader.ReadLine());


			for (int k = 1; k <= T; k++)
			{
				int ans = 0;

				string[] s =reader.ReadLine().Split();
				int L = Convert.ToInt32(s[0]);
				int P = Convert.ToInt32(s[1]);
				int C = Convert.ToInt32(s[2]);

				P = P / L + (P % L != 0 ? 1 : 0);

				while (P > C)
				{
					int P1 = (int)Math.Sqrt(P);
					if (P1 * P1 < P) P1++;
					P = P1;
					ans++;
				}

				writer.WriteLine(String.Format("Case #{0}: {1}", k, ans));
			}

			writer.Close();
			reader.Close();
		}
	}
}
