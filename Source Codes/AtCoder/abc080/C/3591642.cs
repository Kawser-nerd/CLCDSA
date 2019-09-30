using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = ReadInt();
            var F = new int[N, 10];
            var P = new int[N, 11];
            for (int i = 0; i < N; i++)
            {
                var input = ReadArrayInt();
                for (int j = 0; j < 10; j++) F[i, j] = input[j];
            }
            for (int i = 0; i < N; i++)
            {
                var input = ReadArrayInt();
                for (int j = 0; j < 11; j++) P[i, j] = input[j];
            }
            var ans = int.MinValue;

            for (int i = 1; i < (1 << 10); i++)
            {
                var tmp = 0;
                for (int j = 0; j < N; j++)
                {
                    var cnt = 0;
                    for (int k = 0; k < 10; k++)
                    {
                        if (F[j, k] == 1 && (i & (1 << k)) == (1 << k)) cnt++;
                    }
                    tmp += P[j, cnt];
                }

                if (tmp > ans) ans = tmp;
            }

            Console.WriteLine(ans);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}