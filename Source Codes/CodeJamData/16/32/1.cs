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
            Solve[] SV = new Solve[T];
            for (int i = 0; i < T; i++)
            {
                SV[i] = new Solve();
                SV[i].input();
            }

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

            int N;
            long M;
            public void input()
            {
                N = cin.nextInt();
                M = cin.nextLong();
            }
            
            public void calc()
            {
                int[,] ans = new int[N, N];
                
                for (int i = 0; i < N - 1; i++)
                {
                    ans[i, i + 1] = 1;
                }
                long[] num = new long[N];
                num[N - 1] = 1;

                for (int i = N - 2; i >= 0; i--)
                {
                    num[i] = 0;
                    long M2 = M;
                    for (int j = i + 1; j < N; j++)
                    {
                        if(num[j] <= M2)
                        {
                            ans[i, j] = 1;
                            M2 -= num[j];
                            num[i] += num[j];
                        }
                    }
                }
                if (M != num[0])
                {
                    Console.WriteLine("IMPOSSIBLE");
                    return;
                }

                Console.WriteLine("POSSIBLE");
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        Console.Write(ans[i,j]);
                    }
                    Console.WriteLine();
                }
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
