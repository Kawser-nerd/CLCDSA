using System;
using System.Collections.Generic;
using System.Linq;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = Read();
            var ans = int.Parse(N.Substring(0, 1));
            for (int i = 1; i < N.Length; i++)
            {
                var chk = int.Parse(N.Substring(i, 1));
                if (chk != 9)
                {
                    ans += (N.Length - i) * 9;
                    ans--;
                    break;
                }
                else
                {
                    ans += 9;
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