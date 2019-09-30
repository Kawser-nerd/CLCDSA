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
            var K = input[1];
            var sushi = new List<int[]>();
            for (int i = 0; i < N; i++)
            {
                input = ReadArrayInt();
                sushi.Add(new int[] { input[0], input[1] });
            }
            sushi = sushi.OrderBy(s => s[0]).ThenByDescending(s => s[1]).ToList();
            for (int i = N - 1; i > 0; i--)
            {
                if (sushi[i][0] == sushi[i - 1][0]) sushi[i][0] = 0;
                else sushi[i][0] = 1;
            }
            sushi[0][0] = 1;
            sushi = sushi.OrderByDescending(s => s[1]).ThenByDescending(s => s[0]).ToList();
            var t = 0L;
            var d = 0L;
            var sta = new Stack<long>();
            for (int i = 0; i < K; i++)
            {
                t += sushi[i][0];
                d += sushi[i][1];
                if (sushi[i][0] == 0) sta.Push(sushi[i][1]);
            }
            var ans = t * t + d;
            for (int i = K; i < N; i++)
            {
                if (sushi[i][0] == 0) continue;
                else if (!sta.Any()) break;
                t += sushi[i][0];
                d += sushi[i][1];
                var s = sta.Pop();
                d -= s;
                var chk = t * t + d;
                if (ans < chk) ans = chk;
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