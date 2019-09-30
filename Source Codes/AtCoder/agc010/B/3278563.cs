using System;
using System.Linq;

namespace AGC010B
{
    class Program
    {
        static void Main(string[] args)
        {
            long N = long.Parse(Console.ReadLine());
            long[] A = Console.ReadLine().Split(' ').Select(a => long.Parse(a)).ToArray();

            long onetime = N * (N + 1) / 2;
            long Sum = A.Sum();

            if (Sum % onetime != 0)
            {
                Console.WriteLine("NO");
                return;
            }

            long times = Sum / onetime;

            long[] Difference = new long[N];
            for (long i = 0; i < N - 1; i++)
            {
                Difference[i] = A[i + 1] - A[i] - times;
            }

            Difference[N - 1] = A[0] - A[N - 1] - times;

            long count = 0;
            for (long i = 0; i < N; i++)
            {
                if (Difference[i] % N != 0 | Difference[i] > 0)
                {
                    Console.WriteLine("NO");
                    return;
                }

                count += Difference[i] / N;
            }

            if (-count == times)
            {
                Console.WriteLine("YES");
                return;
            }
            Console.WriteLine("NO");
        }
    }
}