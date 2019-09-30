using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using QuickGraph;
using QuickGraph.Algorithms;
using QuickGraph.Algorithms.Exploration;
using QuickGraph.Algorithms.MaximumFlow;
using QuickGraph.Algorithms.MinimumSpanningTree;
using QuickGraph.Algorithms.Search;
using QuickGraph.Algorithms.ShortestPath;

static class ProblemA
{
    static void Main(string[] args)
    {
        using (var prob = new CodeJamProblem('a', ProblemType.Large, 1))
        {
            var t = prob.ReadLineInt32();
            for (int c = 0; c < t; c++)
            {
                var info1 = prob.ReadInt32Array();
                var n = info1[0];
                var k = info1[1];
                var board = prob.ReadLines(n).Select(s => s.Select(ch => ".RB".IndexOf(ch)).ToArray()).ToArray();

                for (int i = 0; i < board.Length; i++)
                {
                    for (int r = 0; r < board[i].Length - 1; r++)
                    {
                        for (int j = board[i].Length - 1; j >= 1; j--)
                        {
                            if (board[i][j] == 0)
                            {
                                board[i][j] = board[i][j - 1];
                                board[i][j - 1] = 0;
                            }
                        }
                    }
                }

                var red = false;
                var blue = false;
                for (int i = 0; i < board.Length; i++)
                {
                    for (int j = 0; j < board[i].Length; j++)
                    {
                        var p = board[i][j];
                        if (p == 0)
                            continue;

                        var hl = true;
                        var vl = true;
                        var dll = true;
                        var drl = true;

                        for (int x = 1; x < k; x++)
                        {
                            if (j <= board[i].Length - k)
                            {
                                if (board[i][j + x] != p)
                                    hl = false;
                            }
                            else
                            {
                                hl = false;
                            }

                            if (i >= k - 1 && j <= board[i].Length - k)
                            {
                                if (board[i - x][j + x] != p)
                                    dll = false;
                            }
                            else
                            {
                                dll = false;
                            }

                            if (i <= board.Length - k)
                            {
                                if (board[i + x][j] != p)
                                    vl = false;
                            }
                            else
                            {
                                vl = false;
                            }

                            if (i <= board.Length - k && j <= board[i].Length - k)
                            {
                                if (board[i + x][j + x] != p)
                                    drl = false;
                            }
                            else
                            {

                                drl = false;
                            }
                        }

                        var hasLine = hl || vl || dll || drl;
                        if (p == 1)
                            red |= hasLine;
                        else if (p == 2)
                            blue |= hasLine;
                    }
                }

                if (red && blue)
                {
                    prob.OutputCase("Both");
                }
                else if (red)
                {
                    prob.OutputCase("Red");
                }
                else if (blue)
                {
                    prob.OutputCase("Blue");
                }
                else
                {
                    prob.OutputCase("Neither");
                }
            }
        }
    }
}
