using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace CodeJamSharp
{

    class Program
    {
        static int[,] count;

        static int[] dx = new int[] {2,1 };
        static int[] dy = new int[] {1,2 };
        static int LCount(int x, int y)
        {
            if (x > count.GetUpperBound(0) ||
               y > count.GetUpperBound(1) ||
               (count[x, y] == -1)) return 0;
            if (count[x, y] !=-2) return count[x, y];
            int ret = 0;
            for (int i = 0; i < dx.Length; i++)
            {
                ret += LCount(x + dx[i], y + dy[i]);
            }
            while (ret >= 10007) ret -= 10007;
            count[x, y] = ret;
            return ret;
        }
        static void Main(string[] args)
        {
            using (StreamReader sr = File.OpenText(@"C:\Google\D.in"))
            using (StreamWriter sout = File.CreateText(@"C:\Google\D.out"))
            {
                string line = sr.ReadLine();
                int cases = int.Parse(line);
                for (int cas = 1; cas <= cases; cas++)
                {
                    line = sr.ReadLine();
                    string[] items = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                    int H = int.Parse(items[0]);
                    int W = int.Parse(items[1]);
                    int R = int.Parse(items[2]);
                    count = new int[H, W];
                    for (int i = 0; i < H; i++)
                        for (int ii = 0; ii < W; ii++) count[i, ii] = -2;
                    for (int i = 1; i <= R; i++)
                    {
                        line = sr.ReadLine();
                        items = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                        int r = int.Parse(items[0]);
                        int c = int.Parse(items[1]);
                        count[r - 1, c - 1] = -1;
                    }
                    count[H - 1, W - 1] = 1;

                    sout.WriteLine("Case #{0}: {1}", cas, LCount(0, 0));
                }
            }
        }
    }
}
