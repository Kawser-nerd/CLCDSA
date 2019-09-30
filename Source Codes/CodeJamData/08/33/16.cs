using System;
using System.Collections.Generic;
using System.IO;

namespace GCJ
{
    class Program
    {
        static void Main(string[] args)
        {
            new Program().Run();
        }

        void Run()
        {
            StreamReader sr = File.OpenText(@"d:\C-small-attempt0.in");
            int N = int.Parse(sr.ReadLine());
            long Q = 1000000007;
            for (int t = 0; t < N; t++)
            {
                string[] ss = sr.ReadLine().Split();
                long n = long.Parse(ss[0]), m = long.Parse(ss[1]), X = long.Parse(ss[2]), Y = long.Parse(ss[3]), Z = long.Parse(ss[4]);
                long[] A = new long[m];
                for (int i = 0; i < m; i++)
                    A[i] = int.Parse(sr.ReadLine());
                long[] a = new long[n];
                for (int i = 0; i < n; i++)
                {
                    a[i] = A[i % m];
                    A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z;
                }
                long[] f = new long[n];
                for (int i = 0; i < n; i++)
                {
                    f[i] = 1;
                    for (int j = 0; j < i; j++)
                    {
                        if (a[j] < a[i])
                        {
                            f[i] += f[j];
                            if (f[i] > Q) f[i] = f[i] % Q;
                        }
                    }
                }
                long res = 0;
                for (int i = 0; i < n; i++)
                    res = (res + f[i]) % Q;
                Console.WriteLine("Case #" + (t + 1) + ": " + res);
            }
            sr.Close();
        }
    }
}