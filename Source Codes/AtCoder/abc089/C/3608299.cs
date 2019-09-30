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
            var cnt = new long[5];
            for (int i = 0; i < N; i++)
            {
                var input = Read();
                if (input[0] == 'M') cnt[0]++;
                else if (input[0] == 'A') cnt[1]++;
                else if (input[0] == 'R') cnt[2]++;
                else if (input[0] == 'C') cnt[3]++;
                else if (input[0] == 'H') cnt[4]++;
            }
            var ans = 0L;
            for (int i = 0; i < 5; i++)
            {
                for (int j = i + 1; j < 5; j++)
                {
                    for (int k = j + 1; k < 5; k++)
                    {
                        ans += cnt[i] * cnt[j] * cnt[k];
                    }
                }
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