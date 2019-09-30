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
            var b = ReadArrayInt().ToList();
            var ans = new List<int>();
            for (int i = 0; i < N; i++)
            {
                var suc = false;
                for (int j = b.Count() - 1; j >= 0; j--)
                {
                    if (b[j] - 1 == j)
                    {
                        ans.Add(b[j]);
                        b.RemoveAt(j);
                        suc = true;
                        break;
                    }
                }
                if (!suc) { Console.WriteLine(-1); return; }
            }
            ans.Reverse();

            Console.WriteLine(string.Join(" ", ans));
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}