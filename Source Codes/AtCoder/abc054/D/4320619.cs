using System;
using System.Linq;

class Program
{
    static int N;
    static int Ma;
    static int Mb;
    static int[] a;
    static int[] b;
    static int[] c;

    static void Main()
    {
        /*???????*/
        int[] inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
        N = inputs[0];
        Ma = inputs[1];
        Mb = inputs[2];
        a = new int[N];
        b = new int[N];
        c = new int[N];
        for (int i = 0; i < N; i++)
        {
            inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
            a[i] = inputs[0];
            b[i] = inputs[1];
            c[i] = inputs[2];
        }

        /*
            DP[i][p,q] : i?????????A?p(g),B?q(g)??????(??????)
        ???DP???
         */
        int[][,] DP = new int[N + 1][,];
        int a_sum = a.Sum();
        int b_sum = b.Sum();
        for (int i = 0; i <= N; i++)
            DP[i] = new int[a_sum + 1, b_sum + 1];
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= a_sum; j++)
                for (int k = 0; k <= b_sum; k++)
                    DP[i][j, k] = (int)1e8;
        DP[0][0, 0] = 0;
        for (int i = 1; i <= N; i++)
        {
            int ai = a[i - 1];
            int bi = b[i - 1];
            int ci = c[i - 1];
            for (int p = 0; p <= a_sum; p++)
            {
                for (int q = 0; q <= b_sum; q++)
                {
                    try
                    {
                        DP[i][p, q] = Math.Min(DP[i - 1][p, q], DP[i - 1][p - ai, q - bi] + ci);
                    }
                    catch
                    {
                        DP[i][p, q] = DP[i - 1][p, q];
                    }
                }
            }
        }

        /*DP[N][Ma * i,Mb * i] (i = 1,2,3,...)?????????*/
        int ans = int.MaxValue;
        for (int i = 1; ; i++)
        {
            try
            {
                ans = Math.Min(ans, DP[N][Ma * i, Mb * i]);
            }
            catch { break; }
        }
        Console.WriteLine(ans >= (int)1e5 ? -1 : ans);
    }
}