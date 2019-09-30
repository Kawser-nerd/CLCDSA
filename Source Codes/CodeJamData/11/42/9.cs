using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace R2ProblemB
{
    class Program
    {
        public static int[,] a, b;
        public static int r, c;

        static int getsum(int x1, int y1, int x2, int y2)
        {
            return b[x2, y2] - b[x2, y1 - 1] - b[x1 - 1, y2] + b[x1 - 1, y1 - 1];
        }

        static bool check(int x, int y, int len)
        {
            if (len % 2 == 0)
            {
                int half = len / 2;
                int s1 = getsum(x, y, x + half - 1, y + len - 1) - a[x, y] - a[x, y + len - 1];
                int s2 = getsum(x + half, y, x + len - 1, y + len - 1) - a[x + len - 1, y] - a[x + len - 1, y + len - 1];
                int s3 = getsum(x, y, x + len - 1, y + half - 1) - a[x, y] - a[x + len - 1, y];
                int s4 = getsum(x, y + half, x + len - 1, y + len - 1) - a[x, y + len - 1] - a[x + len - 1, y + len - 1];
                if ((s1 == s2) && (s3 == s4)) return true;
            }
            else
            {
                int half = len / 2;
                int s1 = getsum(x, y, x + half - 1, y + len - 1) - a[x, y] - a[x, y + len - 1];
                int s2 = getsum(x + half + 1, y, x + len - 1, y + len - 1) - a[x + len - 1, y] - a[x + len - 1, y + len - 1];
                int s3 = getsum(x, y, x + len - 1, y + half - 1) - a[x, y] - a[x + len - 1, y];
                int s4 = getsum(x, y + half + 1, x + len - 1, y + len - 1) - a[x, y + len - 1] - a[x + len - 1, y + len - 1];
                if ((s1 == s2) && (s3 == s4)) return true;
            }
            return false;
        }

        static int calc()
        {
            int n = Math.Min(r, c);
            for (int x = n; x >= 3; --x)
            {
                for (int i = 1; i + x - 1 <= r; ++i)
                {
                    for (int j = 1; j + x - 1 <= c; ++j)
                    {
                        if (check(i, j, x)) return x;
                    }
                }
            }
            return -1;
        }

        static void Main(string[] args)
        {
            int totalCase = Convert.ToInt32(Console.ReadLine());
            for (int curCase = 0; curCase < totalCase; ++curCase)
            {
                string[] str = Console.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                r = Convert.ToInt32(str[0]);
                c = Convert.ToInt32(str[1]);
                a = new int[r + 1, c + 1];
                b = new int[r + 1, c + 1];
                for (int i = 1; i <= r; ++i)
                {
                    string line = Console.ReadLine();
                    for (int j = 1; j <= c; ++j)
                    {
                        a[i, j] = Convert.ToInt32(line[j - 1]);
                    }
                }
                for (int i = 0; i <= r; ++i)
                {
                    b[i, 0] = 0;
                }
                for (int j = 0; j <= c; ++j)
                {
                    b[0, j] = 0;
                }
                for (int i = 1; i <= r; ++i)
                {
                    for (int j = 1; j <= r; ++j)
                    {
                        b[i, j] = b[i - 1, j] + b[i, j - 1] + a[i, j] - b[i - 1, j - 1];
                    }
                }
                int ans = calc();
                if (ans != -1)
                {
                    Console.WriteLine("Case #{0}: {1}", curCase + 1, ans);
                }
                else
                {
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", curCase + 1);
                }
            }
        }
    }
}
