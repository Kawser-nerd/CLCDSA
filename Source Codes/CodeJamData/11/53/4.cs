using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace cs_console
{
    class G3_C
    {
        public static void Main(String[] args)
        {
            string input = @"../../C.in";
            string output = @"../../C.out";
            using (StreamWriter sw = new StreamWriter(output))
            {
                using (StreamReader sr = new StreamReader(input))
                {
                    long tn = long.Parse(sr.ReadLine());
                    for (long tc = 1; tc <= tn; tc++)
                    {
                        sw.WriteLine("Case #{0}: {1}", tc, ls(sr));
                        //Console.WriteLine("Case #{0}: {1}", tc, ls(sr));
                    }
                }
            }
        }

        private static int ls(StreamReader sr)
        {
            string[] ss = sr.ReadLine().Split(' ');
            int r = int.Parse(ss[0]);
            int c = int.Parse(ss[1]);
            string[] a = new string[r];
            for (int i = 0; i < r; i++)
            {
                a[i] = sr.ReadLine();
            }
            int v = 1 << (r * c);
            int[] map = new int[256];
            map[(char)'-'] = 0;
            map[(char)'|'] = 1;
            map[(char)'/'] = 2;
            map[(char)'\\'] = 3;
            int[,] dir = new int[4, 2]{
                {0, 1}, {1, 0}, {-1, 1}, {1, 1}
            };
            int cnt = 0;
            for (int k = 0; k < v; k++)
            {
                if (check(r, c, a, map, dir, k))
                    cnt++;
            }
            return cnt % 1000003;
        }

        private static bool check(int r, int c, string[] a, int[] map, int[,] dir, int k)
        {
            bool[,] used = new bool[r, c];
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    int p = i * c + j;
                    bool f = (((1 << p) & k) != 0);
                    char ch = a[i][j];
                    int mv = map[(int)ch];
                    int ox = dir[mv, 0];
                    int oy = dir[mv, 1];
                    if (f)
                    {
                        ox = -ox;
                        oy = -oy;
                    }
                    int nx = (i + ox + r) % r;
                    int ny = (j + oy + c) % c;
                    if (used[nx, ny])
                    {
                        return false;
                    }
                    used[nx, ny] = true;
                }
            }
            return true;
        }

        static void assert(bool v)
        {
            if (!v)
            {
                throw new Exception();
            }
        }
    }
}
