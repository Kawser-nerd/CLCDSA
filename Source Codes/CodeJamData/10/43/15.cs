using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Bacteria
{
    class Program
    {
        public static int solve()
        {
            int line = Int32.Parse(Console.ReadLine());
            bool[,] map = new bool[300, 300];
            for (int i = 0; i < line; i++)
            {
                String[] s = Console.ReadLine().Split(' ');
                int x1 = Int32.Parse(s[0]);
                int y1 = Int32.Parse(s[1]);
                int x2 = Int32.Parse(s[2]);
                int y2 = Int32.Parse(s[3]);
                for (int n = x1; n <= x2; n++)
                {
                    for (int m = y1; m <= y2; m++)
                    {
                        map[m, n] = true;
                    }
                }
            }
            for (int cc = 0; ; cc++)
            {
                bool[,] map2 = new bool[300, 300];
                bool flag = false;
                for (int n = 1; n < 300; n++)
                {
                    for (int m = 1; m < 300; m++)
                    {
                        if (map[m, n])
                        {
                            if (map[m - 1, n] | map[m, n - 1]) { map2[m, n] = true; flag = true; }
                        }
                        else
                        {
                            if (map[m - 1, n] & map[m, n - 1]) { map2[m, n] = true; flag = true; }
                        }
                    }
                }
                if (!flag) return cc+1;
                map = map2;
            }

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
