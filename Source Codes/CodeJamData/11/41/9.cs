using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace R2ProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            int totalCase = Convert.ToInt32(Console.ReadLine());
            for (int curCase = 0; curCase < totalCase; ++curCase)
            {
                string[] str = Console.ReadLine().Split(new char[] { ' ' });
                int len = Convert.ToInt32(str[0]);
                int s = Convert.ToInt32(str[1]);
                int r = Convert.ToInt32(str[2]);
                int t = Convert.ToInt32(str[3]);
                int n = Convert.ToInt32(str[4]);
                int[] left = new int[n];
                int[] right = new int[n];
                decimal[] l = new decimal[n + 1];
                int[] v = new int[n + 1];
                l[n] = len;
                v[n] = s;
                for (int i = 0; i < n; ++i)
                {
                    str = Console.ReadLine().Split(new char[] { ' ' });
                    left[i] = Convert.ToInt32(str[0]);
                    right[i] = Convert.ToInt32(str[1]);
                    v[i] = Convert.ToInt32(str[2]) + s;
                    l[i] = right[i] - left[i];
                    l[n] -= l[i];
                }
                Array.Sort(v, l);
                decimal ans = 0;
                decimal cur = t;
                for (int i = 0; i <= n; ++i)
                {
                    if (l[i] / (v[i] + r - s) < cur)
                    {
                        ans += l[i] / (v[i] + r - s);
                        cur -= l[i] / (v[i] + r - s);
                    }
                    else
                    {
                        ans += (l[i] - (v[i] + r - s) * cur) / v[i] + cur;
                        cur = 0;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", curCase + 1, ans);
            }
        }
    }
}
