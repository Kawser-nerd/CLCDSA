using System;
using System.IO;
using System.Collections.Generic;

namespace A
{
    class Cake
    {
        public int R { get; set; }
        public int C { get; set; }
        public char[,] Grid { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var path = args[0];
            var testCases = ParseInput(path);
            var caseNo = 1;

            using (var stream = new FileStream($"{path}.out", FileMode.Create))
            {
                using (var sw = new StreamWriter(stream))
                {
                    foreach (var testCase in testCases)
                    {
                        var cake = Solve(testCase);
                        Console.WriteLine($"Case #{caseNo}:");
                        sw.WriteLine($"Case #{caseNo}:");

                        for (var i = 0; i < cake.R; ++i)
                        {
                            for (var j = 0; j < cake.C; ++j)
                            {
                                Console.Write(cake.Grid[i, j]);
                                sw.Write(cake.Grid[i, j]);
                            }
                            Console.WriteLine();
                            sw.WriteLine();
                        }
                        caseNo++;
                    }
                }
            }
        }

        private static IList<Cake> ParseInput(string path)
        {
            using (var stream = new FileStream($"{path}.in", FileMode.Open))
            {
                using (var sr = new StreamReader(stream))
                {
                    var count = int.Parse(sr.ReadLine());
                    var testCases = new List<Cake>(count);
                    while (count-- > 0)
                    {
                        var line = sr.ReadLine().Split(' ');
                        var R = int.Parse(line[0]);
                        var C = int.Parse(line[1]);
                        var cake = new char[R, C];
                        for (var i = 0; i < R; ++i)
                        {
                            var ln = sr.ReadLine();
                            for (var j = 0; j < C; ++j)
                            {
                                cake[i, j] = ln[j];
                            }
                        }
                        testCases.Add(new Cake { R = R, C = C, Grid = cake });
                    }
                    return testCases;
                }
            }
        }

        private static Cake Solve(Cake cake)
        {
            var grid = cake.Grid;
            // Scan row
            for (var row = 0; row < cake.R; ++row)
            {
                var col = 0;
                while (col < cake.C)
                {
                    if (col > 0 && grid[row, col] == '?')
                    {
                        grid[row, col] = grid[row, col - 1];
                    }
                    ++col;
                }

                col = cake.C - 1;
                while (col >= 0)
                {
                    if (col < cake.C - 1 && grid[row, col] == '?')
                    {
                        grid[row, col] = grid[row, col + 1];
                    }
                    --col;
                }
            }

            // Scan col
            for (var col = 0; col < cake.C; ++col)
            {
                var row = 0;
                while (row < cake.R)
                {
                    if (row > 0 && grid[row, col] == '?')
                    {
                        grid[row, col] = grid[row - 1, col];
                    }
                    ++row;
                }

                row = cake.R - 1;
                while (row >= 0)
                {
                    if (row < cake.R - 1 && grid[row, col] == '?')
                    {
                        grid[row, col] = grid[row + 1, col];
                    }
                    --row;
                }
            }

            return cake;
        }
    }
}
