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
            StreamReader sr = new StreamReader("D:\\a-large.in");
            StreamWriter sw = new StreamWriter("D:\\a-large.out");
            int nTest = Convert.ToInt32(sr.ReadLine());
            for (int T = 1; T <= nTest; T++)
            {
				int n = Convert.ToInt32(sr.ReadLine());
				String[] inp = sr.ReadLine().Split(' ');
				int[] a = new int[n];
				for (int i = 0; i < n; i++)
					a[i] = Convert.ToInt32(inp[i]);
				int res1 = 0,mx = 0;
				for (int i = 1; i < n; i++)
					if (a[i] < a[i - 1])
					{
						res1 += a[i - 1] - a[i];
						mx = Math.Max(mx, a[i - 1] - a[i]);
					}
				int res2 = 0;
				for (int i = 0; i < n - 1; i++)
				{
					res2 += Math.Min(mx, a[i]);
				}
				sw.WriteLine("Case #" + T + ": " + res1 + " " + res2);
            }
            sr.Close();
            sw.Close();
        }
    }
}