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
            var N = input[0];
            var C = input[1];
            var bro = new bool[31, 100001];
            for (int i = 0; i < N; i++)
            {
                input = ReadArrayInt();
                var s = input[0];
                var t = input[1];
                var c = input[2];
                for (int j = s; j <= t; j++) bro[c, j] = true;
            }

            var ans = 0;
            for (int i = 1; i <= 100000; i++)
            {
                var cnt = 0;
                for (int j = 1; j <= 30; j++) if (bro[j, i]) cnt++;
                if (cnt > ans) ans = cnt;
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