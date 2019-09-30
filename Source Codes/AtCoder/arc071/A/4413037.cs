using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = ReadInt();
            var S = Enumerable.Repeat("", n).Select(s => Read()).ToArray();
            var letter = new Dictionary<char, int>();
            for (char c = 'a'; c <= 'z'; c++)
            {
                var cnt = int.MaxValue;
                for (int i = 0; i < n; i++)
                {
                    var tmp = 0;
                    for (int j = 0; j < S[i].Length; j++)
                    {
                        if (S[i][j] == c) tmp++;
                    }
                    if (tmp < cnt) cnt = tmp;
                }
                letter.Add(c, cnt);
            }
            var ans = "";
            foreach(var l in letter)
            {
                if (l.Value > 0)
                {
                    ans += new string(l.Key, l.Value);
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