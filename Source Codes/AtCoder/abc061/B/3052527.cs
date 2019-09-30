using System;

namespace ABC061B
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] bufs = Console.ReadLine().Split(' ');
            int N = Int32.Parse(bufs[0]);
            int M = Int32.Parse(bufs[1]);

            int[] res = new int[N + 1];
            for (int i = 0; i <= N; i++)
            {
                res[i] = 0;
            }


            for (int i = 0; i < M; i++)
            {
                bufs = Console.ReadLine().Split(' ');
                int a = Int32.Parse(bufs[0]);
                int b = Int32.Parse(bufs[1]);

                res[a]++;
                res[b]++;
            }

            for (int i = 1; i <= N; i++)
            {
                Console.WriteLine(res[i]);
            }
        }
    }
}