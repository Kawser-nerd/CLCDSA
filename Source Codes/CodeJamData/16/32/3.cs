using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1CProblemB
{
    class Program
    {
        private class CycleException : Exception
        {
        }

        /*private static readonly int[] BitMasks = new int[]
        {
            1,
            2,
            4,
            8,
            16,
            32,
            64,
            128,
            256,
        };*/

        private static int GetWaysCount(Dictionary<int, List<int>> configuration, int start, int end)
        {
            if (start == end)
            {
                return 1;
            }

            if (start > end)
            {
                return 0;
            }

            return configuration[start].Sum(next => GetWaysCount(configuration, next, end));
        }

        static void Main(string[] args)
        {
            var t = int.Parse(Console.ReadLine());
            for (var t0 = 1; t0 <= t; t0++)
            {
                var line = Console.ReadLine().Split(' ');
                var b = int.Parse(line[0]);
                var m = int.Parse(line[1]);

                bool success = false;

                var cnt = (b * (b - 1)) / 2;

                var totals = new int[30];
                for (var i = 0; i < 30; i++)
                {
                    totals[i] = 0;
                }

                for (var i = 0; i < (1 << cnt); i++)
                {
                    var configuration = new Dictionary<int, List<int>>();
                    for (var row = 0; row < b; row++)
                    {
                        configuration[row] = new List<int>();

                        if (row == b-1)
                        {
                            continue;
                        }

                        for (var col = row+1; col < b; col++)
                        {
                            var last = (row + 1) * b - (((row + 1) * (row + 2)) / 2) - 1; //0: b-2; 1: 2b-4
                            var first = last - (b - 1);
                            var pos = first + col;
                            if ((i & (1 << pos)) != 0)
                            {
                                configuration[row].Add(col);
                            }
                        }
                    }

                    totals[configuration.Sum(kvp => kvp.Value.Count)]++;

                    if (GetWaysCount(configuration, 0, b-1) == m)
                    {
                        success = true;

                        Console.WriteLine($"Case #{t0}: POSSIBLE");

                        for (var row = 0; row < b; row++)
                        {
                            Console.WriteLine(string.Join("", Enumerable.Range(0, b).Select(col => configuration[row].Contains(col) ? "1" : "0")));
                        }

                        break;
                    }
                }

                if (!success)
                {
                    Console.WriteLine($"Case #{t0}: IMPOSSIBLE");
                    if (m < (1 << (b-2)))
                    {
                        //Console.WriteLine("!!!");
                    }
                }

                //Console.WriteLine($"Case #{t0}: {string.Join(" ", totals)}");
            }
        }
    }
}
