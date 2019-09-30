using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam
{
    class Program
    {
        static private int Solve(string[] rows)
        {
            int R = rows.Length;
            int C = rows[0].Length;
            int count = 0;
            for (int r = 0; r < R; ++r)
            {
                for (int c = 0; c < C; ++c)
                {
                    if (rows[r][c] != '.')
                    {
                        int upper = Enumerable.Range(0, r).Count(i => rows[i][c] != '.');
                        int bottom = Enumerable.Range(r + 1, R - r - 1).Count(i => rows[i][c] != '.');
                        int left = Enumerable.Range(0, c).Count(i => rows[r][i] != '.');
                        int right = Enumerable.Range(c + 1, C - c - 1).Count(i => rows[r][i] != '.');
                        if (upper == 0 && bottom == 0 && left == 0 && right == 0) { return -1; }
                        switch (rows[r][c])
                        {
                        case '^': if (upper == 0) { ++count; } break;
                        case 'v': if (bottom == 0) { ++count; } break;
                        case '<': if (left == 0) { ++count; } break;
                        case '>': if (right == 0) { ++count; } break;
                        }
                    }
                }
            }
            return count;
        }
        static void Main(string[] args)
        {
            string filename = "../A-large";
            var sr = new StreamReader(filename + ".in");
            var sw = new StreamWriter(filename + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; ++i)
            {
                int[] values = Array.ConvertAll(sr.ReadLine().Split(), int.Parse);
                int R = values[0];
                var rows = new string[R];
                for (int j = 0; j < R; ++j) { rows[j] = sr.ReadLine(); }
                int result = Solve(rows);
                sw.WriteLine("Case #{0}: {1}", i + 1, result < 0 ? "IMPOSSIBLE" : result.ToString());
                Console.WriteLine("Case #{0}: Done", i + 1);
            }
            sw.Close();
            sr.Close();
            Console.ReadKey();
        }
    }
}
