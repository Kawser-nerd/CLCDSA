using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.Numerics;

namespace GoogleCodeJam
{
    class Program
    {
        static Scanner cin;
        static void Main(string[] args)
        {
            cin = new Scanner();
            Solve.cin = cin;
            int T = cin.nextInt();
            Solve.init();
            Solve[] SV = new Solve[T];
            for (int i = 0; i < T; i++)
            {
                SV[i] = new Solve();
                SV[i].input();
            }

            Solve.init();
            string[] ans = new string[T];


            bool highspeed = false;

            //high speed;
            if (highspeed)
            {
                Parallel.For(0, T, i =>
                {
                    ans[i] = SV[i].calc();
                    SV[i] = null;
                });
            }

            //low speed
            if (!highspeed)
            {
                for (int i = 0; i < T; i++)
                {
                    ans[i] = SV[i].calc();
                    SV[i] = null;
                }
            }

            for (int i = 0; i < T; i++)
            {
                Console.Write("Case #{0}: ", i + 1);
                Console.WriteLine(ans[i]);
            }


        }


        public class XRand
        {
            uint x, y, z, w;


            public XRand()
            {
                init();
            }

            public XRand(uint s)
            {
                init();
                init_xor128(s);
            }

            void init()
            {
                x = 314159265; y = 358979323; z = 846264338; w = 327950288;

            }

            public void init_xor128(uint s)
            {
                z ^= s;
                z ^= z >> 21; z ^= z << 35; z ^= z >> 4;
                z *= 736338717;
            }

            uint next()
            {
                uint t = x ^ x << 11; x = y; y = z; z = w; return w = w ^ w >> 19 ^ t ^ t >> 8;
            }

            public long nextLong(long m)
            {
                return (long)((((ulong)next() << 32) + next()) % (ulong)m);
            }

            public int nextInt(int m)
            {
                return (int)(next() % m);
            }

            public int nextInt(int min, int max)
            {
                return min + nextInt(max - min + 1);
            }

            public int nextIntP(int a)
            {
                return (int)Math.Pow(a, nextDouble());
            }

            public int nextIntP(int min, int max)
            {
                int diff = max - min;
                return min + nextIntP(diff + 2) - 1;
            }

            public double nextDouble()
            {
                return (double)next() / uint.MaxValue;
            }

            public double nextDoubleP(double a)
            {
                return Math.Pow(a, nextDouble());
            }
        }



        class Solve
        {
            public Solve() { }

            public static Scanner cin;

            

            public static void init()
            {

            }

            int N, P;
            int[] G;
            
            public void input()
            {
                N = cin.nextInt();
                P = cin.nextInt();
                G = new int[N];
                for (int i = 0; i < N; i++)
                {
                    G[i] = cin.nextInt();
                }
            }


            public string calc()
            {
                int[] num = new int[P];
                for (int i = 0; i < N; i++)
                {
                    num[G[i] % P]++;
                }
                int ans = num[0];
                dp = new int[101 * 101 * 101];
                for (int i = 0; i < dp.Length; i++)
                {
                    dp[i] = -1;
                }
                List<int> L = new List<int>();
                for (int i = 1; i < P; i++)
                {
                    L.Add(num[i]);
                }
                ans += dfs(L.ToArray(), 0);

                dp = new int[0];

                return ans.ToString();
            }

            int[] dp;
            int dfs(int[] num, int nokori)
            {
                int hash = gethash(num);
                if (hash == 0) return 0;
                if (dp[hash] != -1) return dp[hash];
                int ans = 0;
                for (int i = 0; i < P - 1; i++)
                {
                    if (num[i] == 0) continue;
                    num[i]--;
                    int nextnokori = (nokori + (i + 1)) % P;
                    ans = Math.Max(ans, dfs(num, nextnokori));
                    num[i]++;
                }
                if (nokori == 0) ans++;
                return dp[hash] = ans;
            }

            int gethash(int[] num)
            {
                int ans = 0;
                for (int i = 0; i < num.Length; i++)
                {
                    ans *= 101;
                    ans += num[i];
                }
                return ans;
            }
        }
    }


    class Scanner
    {
        string[] s;
        int i;

        char[] cs = new char[] { ' ' };

        public Scanner()
        {
            s = new string[0];
            i = 0;
        }

        public string next()
        {
            if (i < s.Length) return s[i++];
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return s[i++];
        }

        public int nextInt()
        {
            return int.Parse(next());
        }

        public long nextLong()
        {
            return long.Parse(next());
        }

        public double nextDouble()
        {
            return double.Parse(next());
        }

    }
}
