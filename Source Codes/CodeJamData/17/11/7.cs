using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017R1A
{
    class Program
    {
        static void Main(string[] args)
        {
            var T = int.Parse(Console.ReadLine());
            for (var t = 1; t <= T; ++t)
            {
                var ar = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                var R = ar[0];
                var C = ar[1];
                var cake = Enumerable.Repeat(0, R).Select(x => Console.ReadLine().Select(y => y).ToArray()).ToArray();
                var flag = true;
                for (int i = 0; i < R; i++)
                {
                    if (flag)
                    {
                        if (cake[i].All(x => x == '?'))
                            continue;
                        var l = cake[i].First(x => x != '?');
                        for (int j = 0; j < C; j++)
                        {
                            if (cake[i][j] != '?')
                            {
                                l = cake[i][j];
                            }
                            cake[i][j] = l;
                        }
                        for (int j = 0; j < i; ++j)
                        {
                            for (int k = 0; k < C; ++k)
                            {
                                cake[j][k] = cake[i][k];
                            }
                        }
                        flag = false;
                    }
                    else
                    {
                        if (cake[i].All(x => x == '?'))
                        {
                            for (int j = 0; j < C; ++j)
                            {
                                cake[i][j] = cake[i - 1][j];
                            }
                        }
                        else
                        {
                            var l = cake[i].First(x => x != '?');
                            for (int j = 0; j < C; j++)
                            {
                                if (cake[i][j] != '?')
                                {
                                    l = cake[i][j];
                                }
                                cake[i][j] = l;
                            }
                        }
                    }
                }

                Console.WriteLine("Case #{0}:", t);
                for (int j = 0; j < R; j++)
                {
                    Console.WriteLine("{0}", string.Concat(cake[j]));
                }
            }
        }
    }
}
