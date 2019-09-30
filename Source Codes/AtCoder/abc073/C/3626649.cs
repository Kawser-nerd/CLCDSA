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
            var num = new Dictionary<int, bool>();
            for (int i = 0; i < N; i++)
            {
                var A = ReadInt();
                if (num.ContainsKey(A))
                {
                    if (num[A]) num[A] = false;
                    else num[A] = true;
                }
                else
                {
                    num.Add(A, true);
                }
            }
            var cnt = 0;

            foreach (var v in num) if (v.Value) cnt++;

            Console.WriteLine(cnt);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}