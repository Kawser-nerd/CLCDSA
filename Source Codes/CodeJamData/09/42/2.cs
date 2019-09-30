using System;
using System.Collections.Generic;
using System.IO;

namespace ProblemB
{
    class Program
    {
        static int R, C, F;
        static int[, , , ,] memo;

        static int Solve(string[] cave, int row, int col, int len, int dir, int fall)
        {
            if (fall >= F)
            {
                return Int32.MaxValue;
            }
            if (memo[row, col, len, dir, fall] == 0)
            {
                if (row + 1 == R)
                {
                    memo[row, col, len, dir, fall] = 1;
                }
                else if (cave[row + 1][col] == '.')
                {
                    memo[row, col, len, dir, fall] = Solve(cave, row + 1, col, 0, 0, fall + 1) + 1;
                }
                else
                {
                    int l = col;
                    while (l > 0 && (cave[row][l - 1] == '.' || (dir == 1 && l > col - len)) && cave[row + 1][l - 1] == '#') l--;
                    int r = col;
                    while (r < C - 1 && (cave[row][r + 1] == '.' || (dir == 0 && r < col + len)) && cave[row + 1][r + 1] == '#') r++;

                    int min = Int32.MaxValue;
                    if (l > 0 && (cave[row][l - 1] == '.' || (dir == 1 && l > col - len)) && cave[row + 1][l - 1] != '#')
                        min = Math.Min(min, Solve(cave, row + 1, l - 1, 0, 0, 0));
                    if (r < C - 1 && (cave[row][r + 1] == '.' || (dir == 0 && r < col + len)) && cave[row + 1][r + 1] != '#')
                        min = Math.Min(min, Solve(cave, row + 1, r + 1, 0, 0, 0));
                    for (int i = l; i <= r; i++)
                    {
                        for (int j = i; j <= r; j++)
                        {
                            if (j < r)
                            {
                                int res = Solve(cave, row + 1, j, j - i, 1, 0);
                                if (res != Int32.MaxValue)
                                {
                                    min = Math.Min(min, res + j - i + 1);
                                }
                            }
                            if (i > l)
                            {
                                int res = Solve(cave, row + 1, i, j - i, 0, 0);
                                if (res != Int32.MaxValue)
                                {
                                    min = Math.Min(min, res + j - i + 1);
                                }
                            }
                        }
                    }
                    memo[row, col, len, dir, fall] = min + 1;
                }
            }
            return memo[row, col, len, dir, fall] == Int32.MaxValue ? Int32.MaxValue : memo[row, col, len, dir, fall] - 1;
        }

        static void Main(string[] args)
        {
            using (StreamReader reader = new StreamReader("..\\..\\input.txt"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\output.txt"))
                {
                    int N = Int32.Parse(reader.ReadLine());
                    for (int i = 0; i < N; i++)
                    {
                        string[] temp = reader.ReadLine().Split();
                        R = Int32.Parse(temp[0]);
                        C = Int32.Parse(temp[1]);
                        F = Int32.Parse(temp[2]);

                        string[] cave = new string[R];
                        for (int j = 0; j < R; j++)
                        {
                            cave[j] = reader.ReadLine();
                        }

                        memo = new int[R, C, C, 2, F];
                        int answer = Solve(cave, 0, 0, 0, 0, 0);
                        writer.WriteLine("Case #" + (i + 1) + ": " + (answer == Int32.MaxValue ? "No" : ("Yes " + answer)));
                    }
                }
            }
        }
    }
}