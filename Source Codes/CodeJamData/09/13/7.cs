using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication4
{
    class Program
    {
        static double[,] cache = new double[100,100];

        static double Combi(int n, int r)
        {
            if (r == 0) return 1;
            if (n == 0) return 1;

            if (cache[n, r] > 0)
                return cache[n, r];

            double a = 1, b = 1;

            for (int i = 0; i < r; i++)
            {
                a *= (i + 1);
                b *= (n - i);
            }
            double ret = b / a;

            cache[n, r] = ret;

            return ret;
        }

        const int MAX = 100000;
        static void Main(string[] args)
        {
            int T = int.Parse(Console.In.ReadLine());

            for (int x = 1; x <= T; x++)
            {
                int[] tokens = Console.In.ReadLine().Split(' ').Select(xx => int.Parse(xx)).ToArray();
                int C = tokens[0];
                int N = tokens[1];


                double[,] p = new double[MAX,C+1];
                p[0, 0] = 1;
                double ans = p[1,C];

                for (int k = 1; k < MAX; k++)
                {
                    for (int m = N; m <= C; m++)
                    {
                        p[k, m] = 0;

                        for (int r = 0; r <= N; r++)
                        {
                            if (m - r < 0) continue;
                            if (m - r >= C) continue;

                            double v = p[k - 1, m - r] * Combi(C - m + r,r) * Combi(m-r,N-r) / Combi(C,N);
                            p[k, m] += v;
                        }
                        //Console.WriteLine("{0} {1} {2}", k, m, p[k, m]);
                    }

                    ans += k * p[k, C];
                }

                Console.WriteLine("Case #{0}: {1}",x, ans);
            }
        }
    }
}
