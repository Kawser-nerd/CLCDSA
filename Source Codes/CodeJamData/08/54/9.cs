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
            StreamReader sr = File.OpenText(@"d:\d-small-attempt0.in");
            int T = int.Parse(sr.ReadLine());
            for (int t = 0; t < T; t++)
            {
                int[,] a = new int[101, 101];
                int[,] f = new int[101, 101];
                string[] ss = sr.ReadLine().Split();
                int m = int.Parse(ss[0]), n = int.Parse(ss[1]), R = int.Parse(ss[2]);
                for (int i = 0; i < R; i++)
                {
                    ss = sr.ReadLine().Split();
                    a[int.Parse(ss[0]) - 1, int.Parse(ss[1]) - 1] = 1;
                }

                f[0, 0] = 1;
                for (int i = 1; i < m; i++)
                    for (int j = 0; j < n; j++) if (a[i, j] == 0)
                    {
                        if (i >= 2 && j >= 1) f[i, j] += f[i - 2, j - 1];
                        f[i, j] = f[i, j] % 10007;
                        if (j >= 2 && i >= 1) f[i, j] += f[i - 1, j - 2];
                        f[i, j] = f[i, j] % 10007;
                    }
                Console.WriteLine("Case #" + (t + 1) + ": " + f[m-1,n-1]);
            }
            sr.Close();
        }
    }
}