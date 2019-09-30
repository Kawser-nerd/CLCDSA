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
            StreamReader sr = new StreamReader("D:\\c-small.in");
            StreamWriter sw = new StreamWriter("D:\\c-small.out");
            int nTest = Convert.ToInt32(sr.ReadLine());
            for (int T = 1; T <= nTest; T++)
            {
				int n = Convert.ToInt32(sr.ReadLine());
				long[] x = new long[n];
				long[] y = new long[n];
				for (int i = 0; i < n; i++)
				{
					String[] inp = sr.ReadLine().Split(' ');
					x[i] = Convert.ToInt64(inp[0]);
					y[i] = Convert.ToInt64(inp[1]);
				}
				sw.WriteLine("Case #" + T + ":");
				for (int i = 0; i < n; i++)
				{
					int res = n - 1;
					for (int j = 0; j < n; j++) if (i != j)
					{
						int A = 0, B = 0;
						for (int k = 0; k < n; k++)
						{
							long cr = (x[k] - x[i]) * (y[j] - y[i]) - (y[k] - y[i]) * (x[j] - x[i]);
							if (cr > 0) A++;
							else
								if (cr < 0) B++;
						}
						res = Math.Min(res, Math.Min(A, B));
					}
					sw.WriteLine(res);
				}
            }
            sr.Close();
            sw.Close();
        }
    }
}