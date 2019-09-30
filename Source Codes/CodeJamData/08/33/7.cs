using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Increasing_Speed_Limits
{
    class Program
    {
        static long process()
        {
            long n, m, x, y, z;
            long[] a, t;
            long[] d;
            string[] s = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            n = Int64.Parse(s[0]);
            m = Int64.Parse(s[1]);
            x = Int64.Parse(s[2]);
            y = Int64.Parse(s[3]);
            z = Int64.Parse(s[4]);

            a = new long[m];
            t = new long[n];
            d = new long[n];

            for (int i = 0; i < m; i++)
                a[i] = Int64.Parse(Console.ReadLine());

            for (int i = 0; i < n; i++)
            {
                d[i] = 1;
                t[i] = a[i % m];
                a[i % m] = (x * a[i % m] + y * (i + 1)) % z;
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    if (t[i] > t[j])
                        d[i] = (d[i] + d[j]) % 1000000007;
                }
            }
            long ret = 0;
            foreach (long i in d)
                ret = (ret + i) % 1000000007;
            return ret;
        }
        static void Main(string[] args)
        {
            int t = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < t; i++)
                Console.WriteLine("Case #{0}: {1}", i + 1, process());
        }
    }
}
