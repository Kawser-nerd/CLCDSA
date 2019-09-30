using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017_0_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var input = Console.ReadLine().Split().Select(int.Parse).ToArray();
                var N = input[0];
                var M = input[1];
                var result = 0;
                var exes = new bool[N, N];
                var pluses = new bool[N, N];
                var rowsWithEx = new bool[N];
                var colsWithEx = new bool[N];
                for (int i = 0; i < M; i++)
                {
                    var line = Console.ReadLine().Split().ToArray();
                    var x = int.Parse(line[1]) - 1;
                    var y = int.Parse(line[2]) - 1;
                    if (line[0] != "x")
                    {
                        pluses[x, y] = true;
                        result++;
                    }
                    if (line[0] != "+")
                    {
                        rowsWithEx[x] = true;
                        colsWithEx[y] = true;
                        exes[x, y] = true;
                        result++;
                    }
                }
                var updated = new HashSet<Tuple<int, int>>();
                var k = 0;
                for (int l = 0; l < N; l++)
                {
                    if (!colsWithEx[l])
                    {
                        while (rowsWithEx[k]) k++;
                        result++;
                        rowsWithEx[k] = true;
                        colsWithEx[l] = true;
                        exes[k, l] = true;
                        updated.Add(Tuple.Create(k, l));
                        k++;
                    }
                }

                for (int d = 0; d < (N + 1) / 2; d++)
                {
                    for (int i = d; i < N - d; i++)
                    {
                        var free = true;
                        for (int j = -d; i - j >= 0; j++)
                            if (pluses[i - j, d + j])
                            {
                                free = false;
                                break;
                            }
                        if (!free) continue;
                        for (int j = -d; i + j < N; j++)
                            if (pluses[i + j, d + j])
                            {
                                free = false;
                                break;
                            }
                        if (free)
                        {
                            result++;
                            pluses[i, d] = true;
                            updated.Add(Tuple.Create(i, d));
                        }
                    }
                    for (int i = d; i < N - d; i++)
                    {
                        var free = true;
                        for (int j = -d; i - j >= 0; j++)
                            if (pluses[i - j, N - 1 - (d + j)])
                            {
                                free = false;
                                break;
                            }
                        if (!free) continue;
                        for (int j = -d; i + j < N; j++)
                            if (pluses[i + j, N - 1 - (d + j)])
                            {
                                free = false;
                                break;
                            }
                        if (free)
                        {
                            result++;
                            pluses[i, N - 1 - d] = true;
                            updated.Add(Tuple.Create(i, N - 1 - d));
                        }
                    }
                    for (int i = d; i < N - d; i++)
                    {
                        var free = true;
                        for (int j = -d; i - j >= 0; j++)
                            if (pluses[d + j, i - j])
                            {
                                free = false;
                                break;
                            }
                        if (!free) continue;
                        for (int j = -d; i + j < N; j++)
                            if (pluses[d + j, i + j])
                            {
                                free = false;
                                break;
                            }
                        if (free)
                        {
                            result++;
                            pluses[d, i] = true;
                            updated.Add(Tuple.Create(d, i));
                        }
                    }
                    for (int i = d; i < N - d; i++)
                    {
                        var free = true;
                        for (int j = -d; i - j >= 0; j++)
                            if (pluses[N - 1 - (d + j), i - j])
                            {
                                free = false;
                                break;
                            }
                        if (!free) continue;
                        for (int j = -d; i + j < N; j++)
                            if (pluses[N - 1 - (d + j), i + j])
                            {
                                free = false;
                                break;
                            }
                        if (free)
                        {
                            result++;
                            pluses[N - 1 - d, i] = true;
                            updated.Add(Tuple.Create(N - 1 - d, i));
                        }
                    }
                }

                Console.WriteLine("Case #{0}: {1} {2}", testN, result, updated.Count);
                foreach (var line in updated)
                {
                    var symbol = exes[line.Item1, line.Item2] ? (pluses[line.Item1, line.Item2] ? 'o' : 'x') : '+';
                    Console.WriteLine("{0} {1} {2}", symbol, line.Item1 + 1, line.Item2 + 1);
                }
            }
        }
    }
}
