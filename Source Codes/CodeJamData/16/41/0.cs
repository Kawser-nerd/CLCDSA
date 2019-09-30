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

            //high speed;

            /*
            string[] ans = new string[T];
            Parallel.For(0, T, i =>
            {
                ans[i] = SV[i].calc();
            });

            for (int i = 0; i < T; i++)
            {
                Console.WriteLine("Case #{0}:\n{1}", i + 1, ans[i]);
            }
            */

            //low speed
            
            for (int i = 0; i < T; i++)
            {
                Console.Write("Case #{0}: ", i + 1);
                SV[i].calc();
            }
            
        }



        class Solve
        {
            public Solve() { }

            public static Scanner cin;

            int N, R, P, S;
            public void input()
            {
                N = cin.nextInt();
                R = cin.nextInt();
                P = cin.nextInt();
                S = cin.nextInt();
            }


            static string memo = "RPS";
            const int NMAX = 13;
            static string[,] ans = new string[NMAX, 3];
            static int[,,] count = new int[NMAX, 3, 3];

            public static void init()
            {
                for (int j = 0; j < 3; j++)
                {
                    ans[0, j] = memo[j] + "";
                    count[0, j, j] = 1;
                }
                for (int i = 1; i < NMAX; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (ans[i - 1, j].CompareTo(ans[i - 1, (j + 2) % 3]) < 0)
                        {
                            ans[i, j] = ans[i - 1, j] + ans[i - 1, (j + 2) % 3];
                        }
                        else
                        {
                            ans[i, j] = ans[i - 1, (j + 2) % 3] + ans[i - 1, j];
                        }
                        for (int k = 0; k < 3; k++)
                        {
                            count[i, j, k] = count[i - 1, j, k] + count[i - 1, (j + 2) % 3, k];
                        }
                    }
                }
            }

            public void calc()
            {
                string ret = "IMPOSSIBLE";
                for (int i = 0; i < 3; i++)
                {
                    if (count[N, i, 0] != R) continue;
                    if (count[N, i, 1] != P) continue;
                    if (count[N, i, 2] != S) continue;
                    if (ret == "IMPOSSIBLE" || ans[N, i].CompareTo(ret) < 0)
                    {
                        ret = ans[N, i];
                    }
                }
                Console.WriteLine(ret);
                return;
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
