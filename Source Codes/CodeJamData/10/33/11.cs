/* Codejam 2010
 * Jack Hou
 * jack.m.hou@gmail.com
 * 
 * To run, simply call Go(args)
 */

using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;
using System.IO;

namespace Codejam2010Round1C
{
    class Chess
    {
        public static void Go(string[] args)
        {
            Dictionary<char, bool[]> hex = new Dictionary<char, bool[]>();
            hex.Add('0', new bool[] { false, false, false, false });
            hex.Add('1', new bool[] { false, false, false, true });
            hex.Add('2', new bool[] { false, false, true, false });
            hex.Add('3', new bool[] { false, false, true, true });
            hex.Add('4', new bool[] { false, true, false, false });
            hex.Add('5', new bool[] { false, true, false, true });
            hex.Add('6', new bool[] { false, true, true, false });
            hex.Add('7', new bool[] { false, true, true, true });
            hex.Add('8', new bool[] { true, false, false, false });
            hex.Add('9', new bool[] { true, false, false, true });
            hex.Add('A', new bool[] { true, false, true, false });
            hex.Add('B', new bool[] { true, false, true, true });
            hex.Add('C', new bool[] { true, true, false, false });
            hex.Add('D', new bool[] { true, true, false, true });
            hex.Add('E', new bool[] { true, true, true, false });
            hex.Add('F', new bool[] { true, true, true, true });

            MatchCollection mc;
            string line = Console.ReadLine();
            int T = int.Parse(line);
            for (int t = 0; t < T; t++)
            {
                line = Console.ReadLine();
                mc = Regex.Matches(line, @"\d+");
                int M = int.Parse(mc[0].ToString());
                int N = int.Parse(mc[1].ToString());

                bool[,] grid = new bool[M, N];
                char[] row;
                for (int m = 0; m < M; m++)
                {
                    row = Console.ReadLine().ToCharArray();
                    for (int n = 0; n < N / 4; n++)
                    {
                        //Console.Write(row[n] + " ");
                        bool[] temp = hex[row[n]];
                        //Console.WriteLine("" + temp[0] + temp[1] + temp[2] + temp[3]);
                        grid[m, n * 4 + 0] = temp[0];
                        grid[m, n * 4 + 1] = temp[1];
                        grid[m, n * 4 + 2] = temp[2];
                        grid[m, n * 4 + 3] = temp[3];
                    }
                }

                // write board
                /*for (int m = 0; m < M; m++)
                {
                    for (int n = 0; n < N; n++)
                        Console.Write(grid[m, n] ? '1' : '0');
                    Console.WriteLine();
                }*/

                bool[,] correct = new bool[M, N];
                for (int m = 0; m < M - 1; m++)
                    for (int n = 0; n < N - 1; n++)
                    {
                        correct[m, n] = grid[m, n] != grid[m, n + 1] &&
                                        grid[m, n] != grid[m + 1, n] &&
                                        grid[m, n] == grid[m + 1, n + 1];
                    }

                // check connectivity
                /*for (int m = 0; m < M; m++)
                {
                    for (int n = 0; n < N; n++)
                        Console.Write(correct[m, n] ? 1 : 0);
                    Console.WriteLine();
                }*/

                bool[,] removed = new bool[M, N];

                int S = Math.Max(M, N);
                int[] count = new int[S + 1];
                for (int s = S; s > 1; s--)
                {
                    for (int m = 0; m <= M - s; m++)
                    {
                        for (int n = 0; n <= N - s; n++)
                        {
                            bool next = false;
                            for (int i = 0; i <= s - 2; i++)
                            {
                                for (int j = 0; j <= s - 2; j++)
                                    if (!correct[m + i, n + j] || removed[m + i, n + j])
                                    {
                                        next = true;
                                        break;
                                    }
                                if (next) break;
                                if (removed[m + i, n + s - 1])
                                {
                                    next = true;
                                    break;
                                }
                            }
                            if (next) continue;

                            for (int j = 0; j <= s - 1; j++)
                                if (removed[m + s - 1, n + j])
                                {
                                    next = true;
                                    break;
                                }
                            if (next) continue;

                            count[s]++;
                            for (int i = 0; i < s; i++)
                                for (int j = 0; j < s; j++)
                                    removed[m + i, n + j] = true;
                        }
                    }
                }

                for (int m = 0; m < M; m++)
                    for (int n = 0; n < N; n++)
                        if (!removed[m, n]) count[1]++;

                int K = 0;
                for (int s = 1; s <= S; s++)
                    if (count[s] > 0) K++;

                Console.WriteLine("Case #" + (t + 1) + ": " + K);
                for (int s = S; s >= 1; s--)
                    if (count[s] > 0)
                        Console.WriteLine(s + " " + count[s]);
            }
        }
    }
}
