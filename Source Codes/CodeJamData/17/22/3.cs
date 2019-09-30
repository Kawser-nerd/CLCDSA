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

            int N;
            int R, O, Y, G, B, V;

            public void input()
            {
                N = cin.nextInt();
                R = cin.nextInt();
                O = cin.nextInt();
                Y = cin.nextInt();
                G = cin.nextInt();
                B = cin.nextInt();
                V = cin.nextInt();
            }
            

            string imp = "IMPOSSIBLE";

            string first = "";
            string mid = "";
            string last = "";

            public string calc()
            {
                int[] num = new int[6];
                num[0] = R;
                num[1] = Y;
                num[2] = B;
                num[3] = G;
                num[4] = V;
                num[5] = O;
                string st = "RYBGVOryb";
                

                for (int i = 0; i < 3; i++)
                {
                    if(num[i] + num[i+3] == N && num[i] == num[i+3])
                    {
                        StringBuilder SB = new StringBuilder();
                        for (int j = 0; j < num[i]; j++)
                        {
                            SB.Append(st[i]);
                            SB.Append(st[i + 3]);
                        }
                        return SB.ToString();
                    }
                }


                bool[] flag = new bool[3];                

                for (int i = 0; i < 3; i++)
                {
                    num[i] -= num[i + 3];
                    if (num[i] <= 0 && num[i + 3] > 0) return imp;
                    if (num[i] < 0) return imp;
                }

                StringBuilder sb = new StringBuilder();
                int prev = -1;

                int f = -1;

                while (true) {
                    int sum = num[0] + num[1] + num[2];
                    if (sum == 0) break;
                    int p = -9;
                    int next = -1;
                    for (int i = 0; i < 3; i++)
                    {
                        if (i == prev) continue;
                        if (num[i] == 0) continue;
                        int tp = num[i] * 2;
                        if (f == i) tp++;
                        if (tp > p)
                        {
                            next = i;
                            p = tp;
                        }
                    }
                    if (next == -1) return imp;
                    char addChar = st[next];
                    if (!flag[next])
                    {
                        addChar = st[next + 6];
                        flag[next] = true;
                        if (sb.Length == 0) f = next;
                    }
                    sb.Append(addChar);
                    num[next]--;
                    prev = next;
                }
                string ans = sb.ToString();

                for (int i = 0; i < 3; i++)
                {
                    string baseSt = st[i + 6] + "";
                    string targetSt = st[i] + "";
                    StringBuilder add = new StringBuilder();
                    for (int j = 0; j < num[i+3]; j++)
                    {
                        add.Append(st[i + 3]);
                        add.Append(st[i]);
                    }
                    targetSt += add.ToString();
                    ans = ans.Replace(baseSt, targetSt);
                }

                for (int i = 0; i < ans.Length; i++)
                {
                    int j = (i + 1) % ans.Length;
                    for (int a = 0; a < 6; a++)
                    {
                        if (st[a] != ans[i]) continue;
                        for (int b = 0; b < 6; b++)
                        {
                            if (st[b] != ans[j]) continue;
                            if(a >= 3 || b >= 3)
                            {
                                if (Math.Abs(a - b) != 3) return imp;
                            }
                            if (a == b) return imp;
                        }
                    }
                }
                if (ans.Length != N) return imp;
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
