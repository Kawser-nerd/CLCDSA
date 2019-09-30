using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ
{
    class MineSweeper : GCJBase
    {
        string[] IMPOSSIBLE = new string[] { "Impossible" };
        public override void Solve()
        {
            string sLines = Console.ReadLine();
            bool bManual = sLines.StartsWith("m");
            if (bManual) sLines = sLines.Substring(1);
            int iCases = int.Parse(sLines);
            string[] s2 = new string[] { "*..", "...", "..." };
            bool b = IsValid(s2);

            for (int iCase = 1; iCase <= iCases; iCase++)
            {

                string[] s = Console.ReadLine().Split(' ');
                int R = int.Parse(s[0]);
                int C = int.Parse(s[1]);
                int M = int.Parse(s[2]);

                string[] sOut = ProcessMulti(R, C, M);
                if (sOut[0] != IMPOSSIBLE[0])
                {
                    if (!IsValid(sOut))
                    {
                        Console.WriteLine("Broken");
                        System.Diagnostics.Debug.WriteLine("Broken");
                    }
                }
                Console.WriteLine("Case #{0}:", iCase);
                System.Diagnostics.Debug.WriteLine("Case #{0}:", iCase);
                for (int j = 0; j < sOut.Length; j++)
                {
                    Console.WriteLine(sOut[j]);
                    System.Diagnostics.Debug.WriteLine(sOut[j]);
                }
            }

            if (bManual) Console.ReadKey();
        }

        private string[] ProcessMulti(int R, int C, int M)
        {
            int empty = R * C - M;
            if (empty == 0) return ImpWithExplanation("empty 0");
            if (R > 1 && C > 1 && empty < 4 && empty > 1) return ImpWithExplanation(string.Format("R:{0}, C:{1}, empty:{2}", R, C, empty));
            //if (R == 2 || C == 2 && M % 2 == 1) return IMPOSSIBLE;
            if (R == 1)
            {
                string ret = new string('*', M);
                ret += new string('.', empty - 1);
                ret += 'c';
                return new string[] { ret };
            }
            if (C == 1)
            {
                string[] ret = new string[R];
                for (int i = 0; i < M; i++)
                {
                    ret[i] = "*";
                }
                for (int i = M; i < R - 1; i++)
                {
                    ret[i] = ".";
                }
                ret[R - 1] = "c";
                return ret;
            }

            char[][] c = new char[R][];
            for (int i = 0; i < R; i++)
            {
                c[i] = new char[C];
            }
            for (int i = 0; i < R; i++)
            {
                for (int j = 0; j < C; j++)
                {
                    c[i][j] = '*';
                }
            }

            bool found = false;
            for (int X = 2; X <= C && !found; X++)
            {
                for (int x2 = 2; x2 <= X && !found; x2++)
                {
                    for (int Y = 2; Y <= R && !found; Y++)
                    {
                        for (int y2 = 2; y2 <= Y && !found; y2++)
                        {
                            if (X * Y - (X - x2) * (Y - y2) <= empty && X*Y>=empty)
                            {
                                found = true;

                                for (int rr = R - Y; rr < R; rr++)
                                {
                                    for (int cc = C - X; cc < C; cc++)
                                    {
                                        c[rr][cc] = '.';
                                        empty--;
                                    }
                                }

                                for (int rr = R - Y; rr < R - y2; rr++)
                                {
                                    for (int cc = C - X; cc < C - x2; cc++)
                                    {
                                        c[rr][cc] = '*';
                                        empty++;
                                    }
                                }

                                for (int rr = R-y2-1; rr >= R-Y; rr--)
                                {
                                    for (int cc = C-x2-1; cc >= C-X && empty>0; cc--)
                                    {
                                        c[rr][cc] = '.';
                                        empty--;
                                    }
                                }

                                break;
                            }
                        }
                    }
                }
            }

            if (!found && empty > 1) return ImpWithExplanation(string.Format("R:{0}, C:{1}, empty:{2}", R, C, empty));

            c[R - 1][C - 1] = 'c';

            string[] grid = new string[R];
            for (int i = 0; i < R; i++)
            {
                grid[i] = new string(c[i]);
            }
            return grid;
        }

        private int[] aDirI = new int[] { 1, 1, 1, 0, -1, -1, -1, 0 };
        private int[] aDirJ = new int[] { 1, 0, -1, -1, -1, 0, 1, 1 };

        private bool IsValid(string[] grid)
        {
            int N = grid.Length;
            int M = grid[0].Length;
            Queue<int> q = new Queue<int>();
            q.Enqueue(N - 1);
            q.Enqueue(M - 1);
            bool[,] visited = new bool[N, M];
            visited[N - 1, M - 1] = true;
            while (q.Count > 0)
            {
                int n = q.Dequeue();
                int m = q.Dequeue();

                int mineCount = 0;
                for (int i = 0; i < aDirI.Length; i++)
                {
                    int n2 = n + aDirI[i];
                    int m2 = m + aDirJ[i];
                    if (n2 >= 0 && m2 >= 0 && n2 < N && m2 < M && grid[n2][m2] == '*')
                    {
                        mineCount++;
                        break;
                    }
                }

                if (mineCount == 0)
                {
                    for (int i = 0; i < aDirI.Length; i++)
                    {
                        int n2 = n + aDirI[i];
                        int m2 = m + aDirJ[i];
                        if (n2 >= 0 && m2 >= 0 && n2 < N && m2 < M && !visited[n2, m2])
                        {
                            visited[n2, m2] = true;
                            q.Enqueue(n2);
                            q.Enqueue(m2);
                        }
                    }
                }
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (!visited[i, j] && grid[i][j] != '*') return false;
                }
            }

            return true;
        }

        private string[] ImpWithExplanation(string explain)
        {
            return IMPOSSIBLE;
            return new string[] { "Impossible" + " : " + explain };
        }
    }
}
