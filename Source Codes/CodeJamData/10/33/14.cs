using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MakingChessBoards
{
    class Program
    {
        struct pair
        {
            public int a, b;
        }

        public static void solve2(bool[,] map)
        {
            int m = map.GetLength(0);
            int n = map.GetLength(1);
            int[] count = new int[Math.Min(m, n) + 1];
            bool[,] dmap = new bool[m, n];
            for (int cc = count.Length - 1; cc > 0; cc--)
            {
                int[,] a = new int[m, n];
                int[,] b = new int[m, n];

                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (dmap[i, j])
                        {
                            a[i, j] = -1;
                        }
                        b[i, j] = -1;
                    }
                }

                for (int i = 0; i < m; i++)
                {
                    for (int j = 1; j < n; j++)
                    {
                        if (dmap[i, j]) continue;
                        if (map[i, j] != map[i, j - 1]) a[i, j] = a[i, j - 1] + 1;
                    }
                }
                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (dmap[i, j]) continue;
                        if (a[i, j] < cc - 1) continue;
                        if (j == 0) { b[i, j] = 0; }
                        if (i !=0 && map[i - 1, j] != map[i, j])
                        {
                            b[i, j] = b[i - 1, j] + 1;
                        }
                        else b[i, j] = 0;
                    }
                }
                for (int i = cc - 1; i < m; i++)
                {
                    for (int j = cc - 1; j < n; j++)
                    {
                        if (dmap[i, j]) continue;
                        if (b[i, j] >= cc - 1)
                        {
                            for (int x = 0; x < cc; x++)
                            {
                                for (int y = 0; y < cc; y++)
                                {
                                    if (dmap[i - x, j - y]) goto re_try;
                                }
                            }
                            for (int x = 0; x < cc; x++)
                            {
                                for (int y = 0; y < cc; y++)
                                {
                                    dmap[i - x, j - y] = true;
                                }
                            }
                            count[cc]++;
                        re_try: ;
                        }
                    }
                }
            }
            int c = 0;
            for (int i = 0; i < count.Length; i++) if (count[i] != 0) c++;
            Console.WriteLine(c);
            for (int i = count.Length - 1; i > 0; i--)
            {
                if (count[i] == 0) continue;
                Console.WriteLine(i + " " + count[i]);
            }
        }
        public static void solve()
        {
            String[] s = Console.ReadLine().Split(' ');
            int m = Int32.Parse(s[0]);
            int n = Int32.Parse(s[1]);
            bool[,] map = new bool[m, n];
            for (int i = 0; i < m; i++)
            {
                String a = Console.ReadLine();
                for (int j = 0; j < a.Length; j++)
                {
                    int p = Convert.ToInt32(a[j].ToString(), 16);
                    for (int k = 0; k < 4; k++)
                    {
                        map[i, j*4 + k] = (p & (1 << (3 - k))) != 0;
                    }
                }
            }
            solve2(map);
        }

        static void Main(string[] args)
        {
            int T = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                Console.Write("Case #" + (i + 1) + ": ");
                solve();
            }
        }
    }
}
