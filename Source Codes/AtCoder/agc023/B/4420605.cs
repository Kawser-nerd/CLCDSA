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
            var S = new char[N, N];
            for (int i = 0; i < N; i++)
            {
                var input = Read();
                for (int j = 0; j < N; j++)
                {
                    S[i, j] = input[j];
                }
            }
            var cnt = 0;
            for (int i = 0; i < N; i++)
            {
                var A = 0;
                var B = i;
                var tmp = new char[N, N];
                for (int j = 0; j < N; j++)
                {
                    for (int k = 0; k < N; k++)
                    {
                        var y = (j + A) % N;
                        var x = (k + B) % N;
                        tmp[y, x] = S[j, k];
                    }
                }
                var suc = true;
                for (int j = 0; j < N; j++)
                {
                    for (int k = j; k < N; k++)
                    {
                        if (tmp[j, k] != tmp[k, j]) { suc = false; break; }
                    }
                    if (!suc) break;
                }
                if (suc) cnt++;
            }

            Console.WriteLine(cnt * N);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}