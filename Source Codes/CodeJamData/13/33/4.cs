using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace c
{
    class Program
    {
        private const int lim = 250;


        private static int Solve(int N, int[] d, int[] n, int[] w, int[] e, int[] s, int[] dd, int[] dp, int[] ds)
        {
            int cnt = 0;
            int[] wl = new int[2 * lim];

            while (true)
            {
                int d1 = int.MaxValue;
                for (int i = 0; i < N; i++)
                    if (n[i] > 0 && d[i] < d1) d1 = d[i];

                if (d1 == int.MaxValue) break;

                for (int i = 0; i < N; i++)
                    if (n[i] > 0 && d[i] == d1)
                    {
                        for (int x = w[i]; x < e[i]; x++)
                        {
                            if (wl[x + lim] < s[i])
                            {
                                cnt++;
                                break;
                            }
                        }
                    }

                for (int i = 0; i < N; i++)
                    if (n[i] > 0 && d[i] == d1)
                    {
                        for (int x = w[i]; x < e[i]; x++)
                        {
                            if (wl[x + lim] < s[i]) wl[x + lim] = s[i];
                        }

                        n[i]--;
                        if (n[i] > 0)
                        {
                            d[i] += dd[i];
                            w[i] += dp[i];
                            e[i] += dp[i];
                            s[i] += ds[i];
                        }
                    }
            }

            return cnt;
        }


        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int caseNum = 1; caseNum <= T; caseNum++)
            {
                int N = int.Parse(Console.ReadLine());
                int[] d = new int[N];
                int[] n = new int[N];
                int[] w = new int[N];
                int[] e = new int[N];
                int[] s = new int[N];
                int[] dd = new int[N];
                int[] dp = new int[N];
                int[] ds = new int[N];

                for (int i = 0; i < N; i++)
                {
                    string[] line = Console.ReadLine().Trim().Split();
                    d[i] = int.Parse(line[0]);
                    n[i] = int.Parse(line[1]);
                    w[i] = int.Parse(line[2]);
                    e[i] = int.Parse(line[3]);
                    s[i] = int.Parse(line[4]);
                    dd[i] = int.Parse(line[5]);
                    dp[i] = int.Parse(line[6]);
                    ds[i] = int.Parse(line[7]);
                }

                int res = Solve(N, d, n, w, e, s, dd, dp, ds);
                Console.WriteLine("Case #{0}: {1}", caseNum, res);
            }
        }
    }
}
