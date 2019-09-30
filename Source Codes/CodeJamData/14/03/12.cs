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
        static private char[][] Generate(int R, int C, char c)
        {
            char[][] res = new char[R][];
            for (int i = 0; i < R; i++) { res[i] = new string(c, C).ToCharArray(); }
            res[0][0] = 'c';
            return res;
        }
        static private char[][] Solve(int R, int C, int M)
        {
            int E = R * C - M;
            if (E == 1)
            {
                return Generate(R, C, '*');
            }
            else if (R == 1)
            {
                var res = Generate(R, C, '.');
                for (int c = E; c < C; c++)
                {
                    res[0][c] = '*';
                }
                return res;
            }
            else if (C == 1)
            {
                var res = Generate(R, C, '.');
                for (int r = E; r < R; r++)
                {
                    res[r][0] = '*';
                }
                return res;
            }
            else if (M <= (R - 2) * (C - 2))
            {
                var res = Generate(R, C, '.');
                for (int r = R - 1; r >= 2; r--)
                {
                    for (int c = C - 1; c >= 2; c--)
                    {
                        if (M-- > 0)
                        {
                            res[r][c] = '*';
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                return res;
            }
            else
            {
                for (int r = 2; r <= R; r++)
                {
                    for (int c = 2; c <= C; c++)
                    {
                        var res = Generate(R, C, '*');
                        {
                            for (int i = 0; i < r; i++)
                            {
                                for (int j = 0; j < c; j++)
                                {
                                    if (i != 0 || j != 0) { res[i][j] = '.'; }
                                }
                            }
                        }
                        {
                            if (r * c == E) { return res; }
                            if (c > 2)
                            {
                                for (int i = r - 1; i >= 2; i--)
                                {
                                    res[i][c - 1] = '*';
                                    if (res.Sum(y => y.Count(x => x == '*')) == M) { return res; }
                                }
                            }
                            if (r > 2)
                            {
                                for (int j = c - 1; j >= 2; j--)
                                {
                                    res[r - 1][j] = '*';
                                    if (res.Sum(y => y.Count(x => x == '*')) == M) { return res; }
                                }
                            }
                        }
                    }
                }
            }
            return new char[][] { "Impossible".ToCharArray() };
        }
        static void Main(string[] args)
        {
            string filename = "../C-large";
            StreamReader sr = new StreamReader(filename + ".in");
            StreamWriter sw = new StreamWriter(filename + ".out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                int[] values = Array.ConvertAll(sr.ReadLine().Split(' '), int.Parse);
                char[][] res = Solve(values[0], values[1], values[2]);
                sw.WriteLine("Case #{0}:", i);
                Console.WriteLine("Case #{0}:", i);
                for (int j = 0; j < res.Length; j++)
                {
                    sw.WriteLine(res[j]);
                    Console.WriteLine(res[j]);
                }
            }
            sw.Close();
            sr.Close();
            Console.ReadKey();
        }
    }
}
