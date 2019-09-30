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
            var S = Read();
            var ans = "";
            var sby = 0;
            for (int i = 0; i < N; i++)
            {
                if (S[i] == '(')
                {
                    ans += "(";
                    sby++;
                }
                else
                {
                    if (sby > 0)
                    {
                        ans = ans + ")";
                        sby--;
                    }
                    else
                    {
                        ans = "(" + ans + ")";
                    }
                }
            }
            while (sby > 0)
            {
                ans += ")";
                sby--;
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