using System;

namespace AGC024_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = long.Parse(Console.ReadLine());
            var P = new int[N];
            var C = new int[N];
            for (int i = 0; i < N; i++)
            {
                P[i] = int.Parse(Console.ReadLine());
                C[P[i]-1] = i;
            }

            var c = 0;
            var left = -1;
            var a = 0;
            for (int i = 0; i < N; i++)
            {
                if (left < C[i]) c++;
                else c = 1;
                left = C[i];
                a = Math.Max(a, c);
            }
            Console.WriteLine(N-a);
        }
    }
}