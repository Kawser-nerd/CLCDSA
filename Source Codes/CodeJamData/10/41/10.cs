using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ElegantDiamond
{
    class Program
    {
        static int[,] map;
        static int n,nn;
        static int minScore;

        public static int pickUp(int x, int y)
        {
            if (x < 0 || x >= nn|| y < 0 || y >=nn) return -1;
            return map[y, x];
        }
        public static  void seek(int x, int y)
        {
            int inf = Math.Abs(x-n+1) + Math.Abs(y-n+1);
            int m = inf+n;
            int score = m * m - n * n;

            //Console.WriteLine("m" + m + ":" + x + ":" + y);
            if (minScore < score) return ;
            for (int i = 0; i <= m; i++)
            {
                for (int j = 0; j <= m; j++)
                {
                    int t1 = pickUp(x+i, y+j);
                    int t2 = pickUp(x + i, y - j);
                    if (t1 == -1) t1 = t2;
                    if (t2 != -1 && t1 != t2) return;
                    t2 = pickUp(x - i, y + j);
                    if (t1 == -1) t1 = t2;
                    if (t2 != -1 && t1 != t2) return;
                    t2 = pickUp(x - i, y - j);
                    if (t1 == -1) t1 = t2;
                    if (t2 != -1 && t1 != t2) return;
                }
            }
            minScore = score;
        }
        public static int solve()
        {
            n = Int32.Parse( Console.ReadLine());
            nn = n*2-1;
            map = new int[nn,nn];
            for (int i = 0; i < nn; i++)
            {
                for (int j = 0; j < nn; j++) { map[i, j] = -1; }
                String[] s = Console.ReadLine().Split(new char[]{' '},StringSplitOptions.RemoveEmptyEntries);
                int off = Math.Abs(n -1 - i);
                for (int j = 0; j < s.Length; j++)
                {
                    map[i, off + j * 2] = Int32.Parse(s[j]);
                }
            }
            minScore = Int32.MaxValue;
            for (int x = -1; x <= nn; x++)
            {
                for (int y = -1; y <= nn; y++)
                {
                    seek(x,y);
                }
            }
            return minScore;
        }

        static void Main(string[] args)
        {
            int T = Int32.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                Console.WriteLine("Case #" + (i + 1) + ": " + solve());
            }
        }
    }
}
