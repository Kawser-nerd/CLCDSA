using System;

namespace ABC106D
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] bufs = Console.ReadLine().Split(' ');
            int N = int.Parse(bufs[0]);
            int M = int.Parse(bufs[1]);
            int Q = int.Parse(bufs[2]);

            int[,] term = new int[N + 1, N + 1];

            for (int i = 0; i < M; i++)
            {
                bufs = Console.ReadLine().Split(' ');
                int L = int.Parse(bufs[0]);
                int R = int.Parse(bufs[1]);

                for (int j = R; j <= N; j++)
                {
                    term[L, j]++;
                }
            }

            for (int i = 0; i < Q; i++)
            {
                bufs = Console.ReadLine().Split(' ');
                int p = int.Parse(bufs[0]);
                int q = int.Parse(bufs[1]);

                int res = 0;

                for (int j = p; j <= q; j++)
                {
                    res += term[j, q];
                }

                Console.WriteLine(res);
            }

        }
    }
}