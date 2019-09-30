using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Globalization;

namespace C
{
    class Program
    {
        static long M;
        static long N;
        static long[,] grid;
        static long[,] grid_x;
        static long[,] grid_y;
        static long[,] grid_xy;

        static void Main(string[] args)
        {            
            using (var reader = File.OpenText(args[0]))
            {
                int cases = int.Parse(reader.ReadLine());
                for (var c = 0; c < cases; c++)
                {
                    var data = reader.ReadLine().Split(' ').Select(s => long.Parse(s)).ToArray();
                    
                    M = data[0];
                    N = data[1];

                    grid = new long[M, N];
                    grid_xy = new long[M, N];
                    grid_y = new long[M, N];
                    grid_x = new long[M, N];

                    for (int i = 0; i < M; i++)
                    {
                        var line = reader.ReadLine();

                        for (int j = 0; j < N / 4; j++)
                        {
                            var cell = int.Parse(line[j].ToString(), NumberStyles.HexNumber);

                            grid[i, j*4 + 0] = (cell & 8) == 8 ? 1 : 0;
                            grid[i, j*4 + 1] = (cell & 4) == 4 ? 1 : 0;
                            grid[i, j*4 + 2] = (cell & 2) == 2 ? 1 : 0;
                            grid[i, j*4 + 3] = (cell & 1) == 1 ? 1 : 0;
                        }
                    }

                    var result = new SortedDictionary<long, long>();
                    var max = Math.Min(M, N);
                    for (var k = max; k >= 2; k--)
                    {
                        result[k] = 0;
                        for (var i = 0; ; i++)
                        {
                            if (i > M - k)
                            {
                                break;
                            }

                            for (var j = 0; ; j++)
                            {
                                if (j > N - k)
                                {
                                    break;
                                }

                                if (check_zeros2(i, j, k))
                                {
                                    result[k]++;
                                }
                            }
                        }
                    }

                    result[1] = N * M - result.Sum(pair => pair.Value * pair.Key * pair.Key);

                    Console.WriteLine("Case #{0}: {1}", c + 1, result.Sum(pair => pair.Value > 0 ? 1 : 0));
                    for (var k = max; k > 0; k--)
                    {
                        if (result[k] == 0)
                        {
                            continue;
                        }

                        Console.WriteLine("{0} {1}", k, result[k]);
                    }
                }
            }
        }

        private static bool check_zeros2(long ii, long jj, long k)
        {
            var startx = grid[ii, jj];
            if (startx == 2)
            {
                return false;
            }

            var v = startx;
            for (long i = ii; i < ii + k; i++)
            {
                startx = v;
                for (long j = jj; j < jj + k; j++)
                {
                    if (grid[i, j] != startx)
                    {
                        return false;
                    }

                    startx = startx == 1 ? 0 : 1;
                }

                v = v == 1 ? 0 : 1;
            }

            for (long i = ii; i < ii + k; i++)
            {
                for (long j = jj; j < jj + k; j++)
                {
                    grid[i, j] = 2;
                }
            }

            return true;
        }

        private static void print_grid(long[,] grid)
        {
            for (long i = 0; i < M; i++)
            {
                for (long j = 0; j < N; j++)
                {
                    Console.Write(grid[i, j]);
                }
                Console.WriteLine();
            }

            Console.WriteLine("-------------------------------------------------------");
        }        
    }
}
