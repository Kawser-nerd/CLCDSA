using System;

namespace ABC075C
{
    class Program
    {
        static int INFTY = 0x30000000;

        static void Main(string[] args)
        {
            string[] bufs = Console.ReadLine().Split(' ');
            int N = int.Parse(bufs[0]);
            int M = int.Parse(bufs[1]);

            int[] a = new int[M];
            int[] b = new int[M];

            int[,] cost = new int[N, N];

            for (int i = 0; i < M; i++)
            {
                bufs = Console.ReadLine().Split(' ');
                a[i] = int.Parse(bufs[0]) - 1;
                b[i] = int.Parse(bufs[1]) - 1;
            }

            // END Initialize

            int res = 0;

            for (int cut = 0; cut < M; cut++)
            {
                // Cost Reset
                for (int i = 0; i < N; i++)
                {
                    cost[i, i] = 0;
                    for (int j = i + 1; j < N; j++)
                    {
                        cost[i, j] = cost[j, i] = INFTY;
                    }
                }

                for (int m = 0; m < M; m++)
                {
                    if(m != cut)
                    {
                        cost[a[m], b[m]] = cost[b[m], a[m]] = 1;
                    }
                }
                // END Cost Reset

                // WF Method
                for (int k = 0; k < N; ++k)
                {
                    for (int i = 0; i < N; ++i)
                    {
                        for (int j = 0; j < N; ++j)
                        {
                            int wc = cost[i, k] + cost[k, j];
                            if (wc < cost[i, j])
                            {
                                cost[i, j] = wc;
                            }
                        }
                    }
                }

                // Check
                bool disconnected = false;

                for (int i = 0; i < N; i++)
                {
                    for (int j = i + 1; j < N; j++)
                    {
                        if (cost[i, j] >= INFTY)
                        {
                            disconnected = true;
                        }
                    }
                }

                if (disconnected)
                {
                    res++;
                }

            }


            Console.WriteLine(res);
        }
    }
}