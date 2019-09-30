using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            string name = "../B-large";

            StreamReader sr = new StreamReader(name + ".in");
            StreamWriter sw = new StreamWriter(name + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                string[] str = sr.ReadLine().Split(' ');
                int L = int.Parse(str[0]);
                long t = long.Parse(str[1]);
                int N = int.Parse(str[2]);
                int C = int.Parse(str[3]);
                long[] a = new long[C];
                for (int j = 0; j < C; j++) a[j] = long.Parse(str[j + 4]);
                long[] d = new long[N];
                for (int j = 0; j < N; j++) d[j] = a[j % C];
                sw.WriteLine(string.Format("Case #{0}: {1}", i, Solve(L, t, d)));
                Console.WriteLine(string.Format("Case #{0}: Done", i));
            }
            sw.Close();
            sr.Close();
        }
        static long Solve(int L, long t, long[] d)
        {
            long sum = 0;
            for (int i = 0; t > 0 && i < d.Length   ; i++)
            {
                long x = Math.Min(t, d[i] * 2);
                d[i] -= x / 2;
                t -= x;
                sum += x;
            }
            Array.Sort(d, (a, b) => (int)(b - a));
            for (int i = 0; i < L && i < d.Length; i++)
            {
                sum += d[i];
                d[i] = 0;
            }
            sum += d.Sum() * 2;
            return sum;
        }
    }
}
