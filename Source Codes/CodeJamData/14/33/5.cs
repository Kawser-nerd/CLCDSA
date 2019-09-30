using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.IO;

namespace ProblemC
{
    class Program
    {
        private static bool[,] u;
        private static int[,] vis;

        private static int n;
        private static int m;

        static void Main(string[] args)
        {
            using (var sr = new StreamReader(@"..\..\C-small-attempt0.in"))
            {
                using (var sw = new StreamWriter(@"..\..\C-small-attempt0.out"))
                {
                    var T = int.Parse(sr.ReadLine());
                    for (int t = 1; t <= T; t++)
                    {
                        var z = sr.ReadLine().Split().Select(int.Parse).ToArray();
                        n = z[0];
                        m = z[1];
                        int k = z[2];

                        int bm = 1;
                        for (int i = 0; i < n*m; i++)
                        {
                            bm *= 2;
                        }

                        u = new bool[n, m];
                        vis = new int[n, m];

                        int minStones = int.MaxValue;
                        for (int b = 1; b < bm; b++)
                        {
                            Array.Clear(u, 0, n*m);
                            var stones = 0;
                            for (int i = 1, j = 0; i <= b; i <<= 1, j++)
                            {
                                if ((b & i) != 0)
                                {
                                    u[j/m, j%m] = true;
                                    stones++;
                                }
                            }

                            Array.Clear(vis, 0, n*m);
                            int c = 0;
                            for (int i = 0; i < n; i++)
                            {
                                for (int j = 0; j < m; j++)
                                {
                                    bool free = IsFree(i, j);
                                    vis[i, j] = free ? 1 : -1;
                                    if (!free)
                                    {
                                        c++;
                                    }
                                }
                            }

                            if (c >= k)
                            {
                                if (stones < minStones)
                                {
                                    minStones = stones;

                                }
                            }
                        }

                        sw.WriteLine("Case #{0}: {1}", t, minStones);

                    }
                }
            }
        }

        private static bool IsFree(int r, int c)
        {
            if (u[r, c])
            {
                return false;
            }
            if (vis[r, c] == 1)
            {
                return true;
            }
            if (vis[r, c] == -1)
            {
                return false;
            }
            if (r == 0 || c == 0 || r == n - 1 || c == m - 1)
            {
                vis[r, c] = u[r, c] ? -1 : 1;
                return !u[r, c];
            }
            var res = false;
            vis[r, c] = -2;
            if (r > 0 && vis[r-1, c]!=-2)
            {
                res |= IsFree(r - 1, c);
            }
            if (c > 0 && vis[r, c-1] != -2)
            {
                res |= IsFree(r, c -1);
            }
            if (r < n - 1 && vis[r + 1, c] != -2)
            {
                res |= IsFree(r + 1, c);
            }
            if (c < m - 1 && vis[r, c+1] != -2)
            {
                res |= IsFree(r, c+1);
            }
            
            return res;
        }
    }
}


