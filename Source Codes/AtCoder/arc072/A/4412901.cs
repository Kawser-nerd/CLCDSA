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
            var a = ReadArrayInt();
            var plus = 0L;
            var val = 0L;
            for (int i = 0; i < n; i++)
            {
                val += a[i];
                if (i % 2 == 0)
                {
                    if (val <= 0)
                    {
                        plus += Math.Abs(val) + 1;
                        val = 1;
                    }
                }
                else
                {
                    if (val >= 0)
                    {
                        plus += Math.Abs(val) + 1;
                        val = -1;
                    }
                }
            }
            var minus = 0L;
            val = 0;
            for (int i = 0; i < n; i++)
            {
                val += a[i];
                if (i % 2 != 0)
                {
                    if (val <= 0)
                    {
                        minus += Math.Abs(val) + 1;
                        val = 1;
                    }
                }
                else
                {
                    if (val >= 0)
                    {
                        minus += Math.Abs(val) + 1;
                        val = -1;
                    }
                }
            }

            Console.WriteLine(plus < minus ? plus : minus);
            Console.ReadLine();
        }

        static string Read() { return Console.ReadLine(); }
        static int ReadInt() { return int.Parse(Read()); }
        static long ReadLong() { return long.Parse(Read()); }
        static int[] ReadArrayInt() { return Read().Split(' ').Select(s => int.Parse(s)).ToArray(); }
        static long[] ReadArrayLong() { return Read().Split(' ').Select(s => long.Parse(s)).ToArray(); }
    }
}