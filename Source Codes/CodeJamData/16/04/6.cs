using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("F:\\d-large.in");
            StreamWriter sw = new StreamWriter("F:\\d-large.out");
            int nTest = Convert.ToInt32(sr.ReadLine());
            for (int T = 1; T <= nTest; T++)
            {
				String[] w = sr.ReadLine().Split(' ');
				int K = Convert.ToInt32(w[0]);
				int C = Convert.ToInt32(w[1]);
				int S = Convert.ToInt32(w[2]);
				sw.Write("Case #" + Convert.ToString(T) + ":");
				if (S * C < K)
				{
					sw.WriteLine(" IMPOSSIBLE");
					continue;
				}
				long x = 0;
				for (int i = 0; ;i++)
				{
					x = x * K + i % K;
					if (i % C == C - 1)
					{
						sw.Write(" " + Convert.ToString(x + 1));
						if (i >= K - 1)
							break;
						x = 0;
					}
				}
				sw.WriteLine();
			}
            sr.Close();
            sw.Close();
        }
    }
}