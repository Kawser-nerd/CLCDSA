using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC113D
{
    class Program
    {
        static long[,] dp;
        static int[] fibonucchi = new int[9];
        static void Main(string[] args)
        {
            var HWK = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int H = HWK[0];
            int W = HWK[1];
            int K = HWK[2];
            dp = new long[W, H + 1];
            dp[0, 0] = 1;
            long div = 1000000007;

            fibonucchi[0] = 1;
            fibonucchi[1] = 1;
            for (int i = 2; i < fibonucchi.Length; i++) fibonucchi[i] = fibonucchi[i - 1] + fibonucchi[i - 2];
            for (int h = 1; h < H + 1; h++)
            {
                for (int w = 0; w < W; w++)
                {
                    long X = Fibonucchi(w - 1) * Fibonucchi(W - w - 1);
                    long Y = Fibonucchi(w) * Fibonucchi(W - w - 1);
                    long Z = Fibonucchi(w) * Fibonucchi(W - w - 2);
                    dp[w, h] = (X * DP(w - 1, h - 1) + Y * DP(w, h - 1) + Z * DP(w + 1, h - 1)) % div;
                }
            }

            long ans = dp[K - 1, H];
            Console.WriteLine(ans);
            Console.ReadKey();
        }

        static long Fibonucchi(int w)
        {
            if (w < 0) return 0;
            return fibonucchi[w];
        }

        static long DP(int w, int h)
        {
            if (w < 0 || h < 0) return 0;
            else if (w >= dp.GetLength(0) || h >= dp.GetLength(1)) return 0;
            return dp[w, h];
        }
    }
}