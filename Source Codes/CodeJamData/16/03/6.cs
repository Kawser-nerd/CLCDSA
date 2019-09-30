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
            StreamWriter sw = new StreamWriter("F:\\c-large.out");
			sw.WriteLine("Case #1:");
			int n2 = 32, cnt = 0, n = n2/2;
			while (cnt < 500)
			{
				long[] a = new long[n];
				a[0] = 1;
				for (int i = 1, x = cnt; i < n - 1; i++, x/=2)
				{
					a[i] = x % 2;
				}
				a[n - 1] = 1;
				String o = "";
				foreach (long x in a)
				{
					if (x == 0) o += "0";
					else
						o += "1";
				}
				sw.Write(o + o);
				for (int i = 2; i <= 10; i++)
				{
					long res = 0;
					foreach (long x in a)
					{
						res = res * i + x;
					}
					sw.Write(" " + Convert.ToString(res));
				}
				sw.WriteLine();
				cnt++;
			}
            sw.Close();
        }
    }
}