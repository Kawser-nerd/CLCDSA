using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        const int P = 10007;
        static int nP(int n)
        {
            int rtn = 0;
            while (n % P == 0)
            {
                n /= P;
                rtn++;
            }
            return rtn;
        }
        static int reduce(int n)
        {
            while (n % P == 0)
            {
                n /= P;
            }
            return n;
        }
        static int[] inv = new int[P];
        static void fillInv()
        {
            for (int i = 1; i < P; i++)
            {
                for (int j = 1; j < P; j++)
                {
                    if ((i * j) % P == 1)
                        inv[i] = j;
                }
            }
        }
        static Dictionary<int, Dictionary<int, int>> memoized = new Dictionary<int, Dictionary<int, int>>();
        static int NCR(int n, int r)
        {
            if (r < 0 || r > n)
                return 0;
            if (r > n / 2)
                r = n - r;
            if (!memoized.ContainsKey(n))
                memoized[n] = new Dictionary<int, int>();
            if (memoized[n].ContainsKey(r))
                return memoized[n][r];
            int top = 0;
            int bottom = 0;
            for (int i = 1; i <= r; i++)
            {
                bottom += nP(i);
                top += nP(n + 1 - i);
            }
            if (top > bottom)
                return 0;
            int tot = 1;

            for (int i = 1; i <= r; i++)
            {
                tot *= reduce(n + 1 - i);
                tot *= inv[reduce(i)];
            }
            memoized[n][r] = tot;
            return tot;
        }
        static int numWays(int dx, int dy)
        {
            if (dx * dy < 0)
                return 0;
            if ((dx + dy) % 3 != 0)
                return 0;
            if (dx < 0)
            {
                dx *= -1;
                dy *= -1;
            }
            return NCR((dx + dy) / 3, (2 * dx - dy) / 3);
        }
        static int numWays(List<int[]> steps)
        {
            steps.Sort((i1, i2) => (i1[0] - i2[0]));
            int total = 1;
            for (int i = 0; i < steps.Count-1; i++)
            {
                total = (total * numWays(steps[i][0] - steps[i + 1][0], steps[i][1] - steps[i + 1][1])) % P;
            }
            return total;
        }
        static int fill(int[][] R, int cur, List<int[]> taken)
        {
            int total = 0;
            total += numWays(taken);
            for (int i = cur; i < R.Length; i++)
            {
                taken.Add(R[i]);
                total -= fill(R, cur + 1, taken);
                taken.RemoveAt(taken.Count - 1);
            }
            return total;
        }
        static int slow(int H, int W, int[][] R)
        {
            int[,] numways = new int[H, W];
            numways[0, 0] = 1;
            for (int i = 1; i < H; i++)
            {
                for (int j = 1; j < W; j++)
                {
                    if (i >= 1 && j >= 2)
                    {
                        numways[i, j] += numways[i - 1, j - 2];
                    }
                    if (i >= 2 && j >= 1)
                    {
                        numways[i, j] += numways[i - 2, j - 1];
                    }
                    for (int k = 0; k < R.Length; k++)
                    {
                        if (R[k][0] == i+1 && R[k][1] == j+1)
                            numways[i, j] = 0;
                    }
                    numways[i, j] = numways[i, j] % P;
                }
            }
            return numways[H-1, W-1];
        }
        static void Main(string[] args)
        {
            //fillInv();
            StreamReader sr = new StreamReader(args[0]);
            int N = int.Parse(sr.ReadLine());
            for (int t = 1; t <= N; t++)
            {
                string[] split = sr.ReadLine().Split();
                int H = int.Parse(split[0]);
                int W = int.Parse(split[1]);
                int R = int.Parse(split[2]);
                int[][] rocks = new int[R][];
                for (int i = 0; i < R; i++)
                {
                    rocks[i] = new int[2];
                    split = sr.ReadLine().Split();
                    rocks[i][0] = int.Parse(split[0]);
                    rocks[i][1] = int.Parse(split[1]);
                }
                var l = new List<int[]>();
                l.Add(new[] { 1, 1 });
                l.Add(new[] { H, W });
                /*int rtn = fill(rocks, 0, l);
                while (rtn < 0)
                    rtn += P;
                rtn = rtn % P;
                Console.WriteLine("Case #{0}: {1}", t, rtn);*/
                Console.WriteLine("Case #{0}: {1}", t, slow(H,W,rocks));
            }
        }
    }
}
