using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace test.Google
{
    public class gcj2009
    {
        public static void Main(string[] arg)
        {
            try
            {
                using (StreamReader sr = new StreamReader(arg[0]))
                using (StreamWriter sw = new StreamWriter(arg[1]))
                {
                    int T = int.Parse(sr.ReadLine());
                    for (int i = 0; i < T; ++i)
                    {
                        string[] tstrs = sr.ReadLine().Trim().Split(' ');
                        int H = int.Parse(tstrs[0]), W = int.Parse(tstrs[1]);
                        int[,] map = new int[H, W];
                        for (int j = 0; j < H; ++j)
                        {
                            tstrs = sr.ReadLine().Trim().Split(' ');
                            for (int k = 0; k < W; ++k) map[j, k] = int.Parse(tstrs[k]);
                        }


                        string[] res = solve(H, W, map);

                        sw.WriteLine("Case #" + (i + 1) + ": ");
                        foreach (string rr in res) sw.WriteLine(rr);
                    }
                }
            }
            catch (Exception e) { Console.WriteLine(e.Message + e.StackTrace); }
            Console.ReadKey();
        }

        private static int WW;
        private static char[][] res;
        private static List<int>[,] sons;

        private static void setColor(int parent, char color)
        {
            res[parent / WW][parent % WW] = color;
            foreach (int son in sons[parent/WW, parent%WW])setColor(son,color);
        }

        private static string[] solve(int H, int W, int[,] map)
        {
            WW = W;
            res = new char[H][];
            for (int i = 0; i < H; ++i) { res[i] = new char[W]; for (int j = 0; j < W; ++j)res[i][j] = '-'; }

            int[,] parents = new int[H, W];
            for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) parents[i, j] = -1;
            
            sons = new List<int>[H, W];
            for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) sons[i, j] = new List<int>();

            int[,] offset=new int[4,2]{{0,-1},{-1,0},{1,0},{0,1}};
            for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j)
                {
                    int min = map[i, j];
                    int parent = -1;
                    for (int k = 0; k < 4; ++k)
                    {
                        int y = i + offset[k, 1], x = j + offset[k, 0];
                        if (x < 0 || y < 0 || x >= W || y >= H) continue;
                        if (map[y, x] < min) { min = map[y, x]; parent = y * W + x; }
                    }

                    int value = i * W + j;
                    if (parent != -1)
                    {
                        parents[i, j] = parent;
                        sons[parent / W, parent % W].Add(value);
                    }
                }

            int mark = (int)'a';
            for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j)
                {
                    if (res[i][j] != '-') continue;
                    char color = (char)(mark++);

                    int root = i * W + j;
                    while (true)
                    {
                        int test = parents[root / W, root % W];
                        if (test != -1) root = test;
                        else break;
                    }
                    setColor(root, color);
                }

            string[] strs = new string[H];
            for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j)
                {
                    strs[i] += res[i][j];
                    if (j < W - 1) strs[i] += ' ';
                }
            return strs;
        }
    }
}
