using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;

namespace ProblemA
{
    class Program
    {
        class Solver
        {
            private void Move(int[,] lawn, bool[,] cut, int len, int row, int col, int dr, int dc)
            {
                int max = 0;
                for (int i = 0; i < len; i++)
                {
                    max = Math.Max(max, lawn[row + i * dr, col + i * dc]);
                }
                for (int i = 0; i < len; i++)
                {
                    if (max == lawn[row + i * dr, col + i * dc])
                    {
                        cut[row + i * dr, col + i * dc] = true;
                    }
                }
            }

            public string Solve(int[,] lawn)
            {
                bool[,] cut = new bool[lawn.GetLength(0), lawn.GetLength(1)];
                for (int i = 0; i < lawn.GetLength(0); i++)
                {
                    Move(lawn, cut, lawn.GetLength(1), i, 0, 0, 1);
                }
                for (int i = 0; i < lawn.GetLength(1); i++)
                {
                    Move(lawn, cut, lawn.GetLength(0), 0, i, 1, 0);
                }

                for (int i = 0; i < lawn.GetLength(0); i++)
                {
                    for (int j = 0; j < lawn.GetLength(1); j++)
                    {
                        if (!cut[i, j])
                        {
                            return "NO";
                        }
                    }
                }

                return "YES";
            }
        }

        static void Main(string[] args)
        {
            //string filename = "sample";
            //string filename = "B-small-attempt0";
            string filename = "B-large";
            using (StreamReader reader = new StreamReader("..\\..\\" + filename + ".in"))
            {
                using (StreamWriter writer = new StreamWriter("..\\..\\" + filename + ".out"))
                {
                    int T = Int32.Parse(reader.ReadLine());
                    Solver solver = new Solver();
                    for (int i = 0; i < T; i++)
                    {
                        string[] tmp = reader.ReadLine().Split();
                        int n = Int32.Parse(tmp[0]);
                        int m = Int32.Parse(tmp[1]);

                        int [,] lawn = new int[n,m];
                        for (int j = 0; j < n; j++)
                        {
                            tmp = reader.ReadLine().Split();
                            for (int k = 0; k < m; k++)
                            {
                                lawn[j,k] = Int32.Parse(tmp[k]);
                            }
                        }
                        writer.WriteLine("Case #" + (i + 1) + ": " + solver.Solve(lawn));
                    }
                }
            }
        }
    }
}
