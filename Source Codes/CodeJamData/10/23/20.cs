using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace C
{
    class Program
    {
        const int MOD = 100003;

        static int[,] nCr = new int[501, 501];



        static void Main(string[] args)
        {
            nCr[0, 0] = 1;
            for (int n = 1; n <= 500; n++)
                for (int k = 0; k <= n; k++)
                {
                    int val = 0;
                    if (k > 0) val += nCr[n - 1, k - 1];
                    if (k < n) val += nCr[n - 1, k];
                    nCr[n, k] = val % MOD;
                }


            int[,] S = new int[501, 500];

            for (int n = 2; n <= 500; n++)
                S[n, 1] = 1;

            for (int n = 3; n <= 500; n++) // n
                for(int k=2; k<n; k++)  // rank of n
                {
                    int sum = 0;
                    for (int i = 1; i < k; i++)
                    {
                        sum += S[k, i] * nCr[n - k - 1, k - i - 1];
                        sum %= MOD;
                    }
                    S[n, k] = sum;
                }

            int[] R = new int[501];
            for (int n = 2; n <= 500; n++)
            {
                int r = 0;
                for (int k = 1; k < n; k++)
                {
                    r += S[n, k];
                    r %= MOD;
                }
                R[n] = r;
            }

            var ts = Console.ReadLine();
            int T = Convert.ToInt32(ts);
            for (int t = 0; t < T; t++)
            {
                var ns = Console.ReadLine();
                int n = Convert.ToInt32(ns);

                int res = R[n];

                Console.WriteLine("Case #{0}: {1}", t + 1, res);
            }
        }

    }
}
