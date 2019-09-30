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

            public static void init()
            {

            }


            int N, K;
            double[] p;
            public void input()
            {
                N = cin.nextInt();
                K = cin.nextInt();
                p = new double[N];
                for (int i = 0; i < N; i++)
                {
                    p[i] = cin.nextDouble();
                }
                Array.Sort(p);
            }


            public void calc()
            {
                double ans = 0;
                for (int C = 0; C <= K; C++)
                {
                    List<double> l = new List<double>();
                    for (int i = 0; i < C; i++)
                    {
                        l.Add(p[i]);
                    }
                    for (int i = 0; i < K - C; i++)
                    {
                        l.Add(p[p.Length - i - 1]);
                    }
                    

                    double[] dp = new double[K + 1];
                    dp[0] = 1;
                    for (int i = 0; i < K; i++)
                    {
                        for (int j = i; j >= 0; j--)
                        {
                            double move = dp[j] * l[i];
                            dp[j + 1] += move;
                            dp[j] -= move;
                        }
                    }

                    ans = Math.Max(ans, dp[K / 2]);
                }

                Console.WriteLine("{0:0.0000000000000}", ans);
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
