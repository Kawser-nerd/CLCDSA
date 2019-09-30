using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABC_D
{
    class _089
    {
        static void Main(string[] args)
        {
            int[] p = Console.ReadLine().Split(' ').Select(xx => int.Parse(xx)).ToArray();
            int H = p[0], W = p[1], D = p[2];

            int N = H * W;
            int[] h = new int[N + 1];
            int[] w = new int[N + 1];

            for (int i = 0; i < H; i++)
            {
                int[] aa = Console.ReadLine().Split(' ').Select(xx => int.Parse(xx)).ToArray();
                for (int j = 0; j < W; j++)
                {
                    int A = aa[j];
                    h[A] = i;
                    w[A] = j;
                }
            }

            long[] S = new long[N + 1];
            for (int k = 1; k <= D; k++)
            {
                long distance = 0;
                for (int j = k + D; j <= N; j += D)
                {
                    distance += Math.Abs(h[j] - h[j - D]) + Math.Abs(w[j] - w[j - D]);
                    S[j] = distance;
                }
            }


            int Q = int.Parse(Console.ReadLine());
            for (int i = 0; i < Q; i++)
            {
                int[] lr = Console.ReadLine().Split(' ').Select(xx => int.Parse(xx)).ToArray();
                int L = lr[0], R = lr[1];
                long sum = S[R] - S[L];
                Console.WriteLine(sum);
            }
        }
    }
}