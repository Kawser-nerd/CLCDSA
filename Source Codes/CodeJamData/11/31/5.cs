using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace BotTrust
{
    class Program
    {
        private string Solve(int T)
        {
            var nl = Environment.NewLine;
            int r = Int32.Parse(Nx());
            int c = Int32.Parse(Nx());

            var grid = new List<char[]>(r);
            for (int i = 0; i < r; ++i)
            {
                grid.Add(Nx().ToCharArray());
            }

            for (int i = 0; i < r; ++i)
            {
                for (int j = 0; j < c; ++j)
                {
                    if (grid[i][j] == '#')
                    {
                        if (j + 1 < c && grid[i][j + 1] == '#'
                            && i + 1 < r && grid[i + 1][j] == '#'
                            && grid[i + 1][j + 1] == '#')
                        {
                            grid[i][j] = '/';
                            grid[i][j + 1] = '\\';
                            grid[i + 1][j] = '\\';
                            grid[i + 1][j + 1] = '/';
                        }
                        else
                        {
                            return nl + "Impossible";
                        }
                    }
                }
            }

            var ret = String.Join(nl, grid.Select(l => new string(l)).ToArray());
            return nl + ret;
        }


        public static void Run()
        {
            var T = Int32.Parse(input[0]);
            tokenIdx = 1;

            for (int i = 1; i <= T; ++i)
            {
                output
                    .AppendFormat("Case #{0}:{1}", i, new Program().Solve(i))
                    .AppendLine();
            }
        }

        static int tokenIdx;
        static string[] input;
        static StringBuilder output;

        static string Nx()
        {
            return input[tokenIdx++];
        }

        static void Main(string[] args)
        {
            input = String.Join(" ", File.ReadAllLines("in.txt")).Split(' ');
            output = new StringBuilder();

            Run();

            File.WriteAllText("../../out.txt", output.ToString());
        }
    }
}
