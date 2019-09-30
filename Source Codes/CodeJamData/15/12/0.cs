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
            StreamReader sr = new StreamReader("D:\\b-large.in");
            StreamWriter sw = new StreamWriter("D:\\b-large.out");
            int nTest = Convert.ToInt32(sr.ReadLine());
            for (int T = 1; T <= nTest; T++)
            {
				String[] inp = sr.ReadLine().Split(' ');
				int n = Convert.ToInt32(inp[0]);
				long q = Convert.ToInt64(inp[1]);
				inp = sr.ReadLine().Split(' ');
				long[] a = new long[n];
				for (int i = 0; i < n; i++)
					a[i] = Convert.ToInt64(inp[i]);
				long l = 0, r = 1000000000000000L;
				while (l != r)
				{
					long tot1 = 0, m = (l+r)/2;
					for (int i = 0; i < n; i++)
						tot1 += m / a[i] + 1;
					if (tot1 >= q)
						r = m;
					else
						l = m + 1;
				}
				long tot = 0;
				for (int i = 0; i < n; i++)
				{
					if (l % a[i] == 0)
						tot += l / a[i];
					else
						tot += l / a[i] + 1;
				}
				q -= tot;
				int res = 0;
				for (int i = 0; i < n; i++)
				{
					if (l % a[i] == 0)
					{
						if (q == 1)
						{
							res = i + 1;
							break;
						}
						else
							q--;
					}
				}
				sw.WriteLine("Case #" + T + ": " + res);
            }
            sr.Close();
            sw.Close();
        }
    }
}