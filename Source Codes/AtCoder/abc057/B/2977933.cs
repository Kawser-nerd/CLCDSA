using System;

namespace ABC057B
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] bufs;
            bufs = Console.ReadLine().Split(' ');
            int N = Int32.Parse(bufs[0]);
            int M = Int32.Parse(bufs[1]);
            int[,] s = new int[N, 2];
            int[,] p = new int[M, 2];

            for (int i = 0; i < N; i++)
            {
                bufs = Console.ReadLine().Split(' ');
                s[i,0] = Int32.Parse(bufs[0]);
                s[i,1] = Int32.Parse(bufs[1]);
            }
            for (int i = 0; i < M; i++)
            {
                bufs = Console.ReadLine().Split(' ');
                p[i, 0] = Int32.Parse(bufs[0]);
                p[i, 1] = Int32.Parse(bufs[1]);
            }

            for (int i = 0; i < N; i++)
            {
                int min = 1000000007;
                int res = -1;

                for (int j = 0; j < M; j++)
                {
                    int diff = ((s[i, 0] > p[j, 0]) ? s[i, 0] - p[j, 0] : p[j, 0] - s[i, 0])
                        + ((s[i, 1] > p[j, 1]) ? s[i, 1] - p[j, 1] : p[j, 1] - s[i, 1]);
                    if (min > diff)
                    {
                        min = diff;
                        res = j;
                    }
                }

                Console.WriteLine(res + 1);
            }

        }
    }
}