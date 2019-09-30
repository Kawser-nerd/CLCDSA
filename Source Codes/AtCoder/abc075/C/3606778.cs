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
            var M = input[1];
            var sides = new int[M, 2];
            for (int i = 0; i < M; i++)
            {
                input = ReadArrayInt();
                sides[i, 0] = input[0];
                sides[i, 1] = input[1];
            }

            var cnt = 0;

            for (int i = 0; i < M; i++)
            {
                var ver = new bool[N + 1];
                ver[0] = true;
                ver[1] = true;
                while (true)
                {
                    var change = false;
                    for (int j = 0; j < M; j++)
                    {
                        if (j != i)
                        {
                            if (!(ver[sides[j, 0]] && ver[sides[j, 1]]) && (ver[sides[j, 0]] || ver[sides[j, 1]]))
                            {
                                ver[sides[j, 0]] = true;
                                ver[sides[j, 1]] = true;
                                change = true;
                            }
                        }
                    }
                    if (!change) break;
                }

                if (!ver.All(b => b)) cnt++;
            }            

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