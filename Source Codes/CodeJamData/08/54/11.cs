using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJam
{
    class Program
    {
        const int M = 10007;
        static int[,] map;
        static int h, w;

        static void Main(string[] args)
        {
            int total = int.Parse(Console.ReadLine());
            for (int casen = 1; casen <= total; casen++)
            {
                int r;
                string[] buf = Input();
                h = int.Parse(buf[0]);
                w = int.Parse(buf[1]);
                r = int.Parse(buf[2]);
                map = new int[h+1, w+1];
                for (int i = 0; i <= h; i++)
                    for (int j = 0; j <= w; j++)
                        map[i, j] = -1;
                for (int i = 0; i < r; i++)
                {
                    buf = Input();
                    int x = int.Parse(buf[0]);
                    int y = int.Parse(buf[1]);
                    map[x, y] = -2;
                }
                Console.WriteLine("Case #{0}: {1}", casen, dp(1, 1));
            }
        }

        static int dp(int x, int y)
        {
            if (x <= 0|| y <= 0 || x> h || y > w || map[x, y] == -2) return 0;
            if (x == h && y == w) return 1;
            if (map[x, y] >= 0) return map[x, y];
            map[x, y] = (dp(x + 1, y + 2) + dp(x + 2, y + 1)) % M;
            return map[x, y];
        }

        static string[] Input()
        {
            return Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
        }
    }
}
