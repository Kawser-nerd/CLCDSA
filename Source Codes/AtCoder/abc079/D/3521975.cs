using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = ReadArrayInt();
            var H = input[0];
            var W = input[1];
            var c = new int[10, 10];
            var A = new int[10];
            var min = new int[10, 10];
            for (int i = 0; i < 10; i++)
            {
                input = ReadArrayInt();
                for (int j = 0; j < 10; j++)
                {
                    c[i, j] = input[j];
                    min[i, j] = input[j];
                }
            }
            for (int i = 0; i < H; i++)
            {
                input = ReadArrayInt();
                for (int j = 0; j < W; j++) if (input[j] != -1) A[input[j]]++;
            }

            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    for (int k = 0; k < 10; k++)
                    {
                        min[j, k] = Math.Min(min[j, k], min[j, i] + min[i, k]);
                    }
                }
            }

            var ans = 0;
            for (int i = 0; i < 10; i++) if (i != 1 && A[i] > 0) ans += min[i, 1] * A[i];

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