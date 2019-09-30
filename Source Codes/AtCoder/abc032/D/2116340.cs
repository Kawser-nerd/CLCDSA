using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Contest
{
    class Scanner
    {
        private string[] line = new string[0];
        private int index = 0;
        public string Next()
        {
            if (line.Length <= index)
            {
                line = Console.ReadLine().Split(' ');
                index = 0;
            }
            var res = line[index];
            index++;
            return res;
        }
        public int NextInt()
        {
            return int.Parse(Next());
        }
        public long NextLong()
        {
            return long.Parse(Next());
        }
        public string[] Array()
        {
            line = Console.ReadLine().Split(' ');
            index = line.Length;
            return line;
        }
        public int[] IntArray()
        {
            return Array().Select(int.Parse).ToArray();
        }
        public long[] LongArray()
        {
            return Array().Select(long.Parse).ToArray();
        }
    }

    class Program
    {
        private int N, W;
        private long[] v, w;
        private long vmax, wmax;
        private void Scan()
        {
            var line = Console.ReadLine().Split(' ');
            N = int.Parse(line[0]);
            W = int.Parse(line[1]);
            v = new long[N];
            w = new long[N];
            vmax = 0;
            wmax = 0;
            for (int i = 0; i < N; i++)
            {
                line = Console.ReadLine().Split(' ');
                v[i] = int.Parse(line[0]);
                w[i] = int.Parse(line[1]);
                vmax = Math.Max(vmax, v[i]);
                wmax = Math.Max(wmax, w[i]);
            }
        }

        public void Solve()
        {
            Scan();
            if (wmax <= 1000)
            {
                B();
            }
            else if (vmax <= 1000)
            {
                C();
            }
            else if (N <= 30)
            {
                A();
            }
        }

        private void A()
        {
            Console.WriteLine(DFS(0, 0, 0));
        }

        private long DFS(long n, long ww, long vv)
        {
            if (n == N)
            {
                return vv;
            }
            long res = DFS(n + 1, ww, vv);
            if (ww + w[n] <= W)
            {
                res = Math.Max(DFS(n + 1, ww + w[n], vv + v[n]), res);
            }
            return res;
        }

        private void B()
        {
            long[] Arr = new long[200001];
            for (int i = 0; i < N; i++)
            {
                for (int j = 200000; j >= 0; j--)
                {
                    if (j + w[i] <= 200000)
                    {
                        Arr[j + w[i]] = Math.Max(Arr[j + w[i]], Arr[j] + v[i]);
                    }
                }
            }
            long ans = 0;
            for (int i = 0; i <= W; i++)
            {
                ans = Math.Max(ans, Arr[i]);
            }
            Console.WriteLine(ans);
        }

        private void C()
        {
            var dp = new long[2000001];
            for (int i = 0; i <= 200000; i++)
            {
                dp[i] = long.MaxValue;
            }
            dp[0] = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 200000; j >= 0; j--)
                {
                    if (dp[j] != long.MaxValue)
                    {
                        dp[j + v[i]] = Math.Min(dp[j + v[i]], dp[j] + w[i]);
                    }
                }
            }
            for (int i = 200000; i >= 0; i--)
            {
                if (dp[i] <= W && dp[i] != long.MaxValue)
                {
                    Console.WriteLine(i);
                    return;
                }
            }
        }

        static void Main(string[] args)
        {
            new Program().Solve();
        }
    }
}