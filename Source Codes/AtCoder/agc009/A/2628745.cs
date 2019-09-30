using System;
using System.Linq;

namespace AGC009_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = long.Parse(Console.ReadLine());
            var A = new long[N];
            var B = new long[N];
            for (long i = 0; i < N; i++)
            {
                var l = Console.ReadLine().Split().Select(long.Parse).ToArray();
                A[i] = l[0];
                B[i] = l[1];
            }

            long c = 0;
            for (long i = N - 1; i >= 0; i--)
            {
                var t = (A[i] + c) % B[i];
                if (t != 0) c += B[i] - t;
            }
            Console.WriteLine(c);
        }
    }
}