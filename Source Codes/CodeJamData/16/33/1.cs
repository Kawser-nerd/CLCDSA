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

            int K;
            int[] num = new int[3];
            public void input()
            {
                for (int i = 0; i < 3; i++)
                {
                    num[i] = cin.nextInt();
                }
                K = cin.nextInt();
            }

            int[,][,] pair;
            bool[,,] set;
            int[][] used;

            public void calc()
            {
                pair = new int[3, 3][,];
                set = new bool[num[0], num[1], num[2]];
                used = new int[3][];
                for (int i = 0; i < 3; i++)
                {
                    used[i] = new int[num[i]];
                    for (int j = i + 1; j < 3; j++)
                    {
                        pair[i, j] = new int[num[i], num[j]];
                    }
                }

                int turn = 0;

                List<string> ans = new List<string>();
                int pre = 0;
                int add = num[2];
                while (gcd(add, num[1]) != 1) add++;

                for (int i = 0; i < num[0]; i++)
                {
                    for (int j = 0; j < num[1]; j++)
                    {
                        int max = Math.Min(K, num[2]);
                        for (int kk = 0; kk < max; kk++)
                        {
                            int k = pre;

                            ans.Add(string.Format("{0} {1} {2}", i + 1, j + 1, k + 1));
                            pre += 1;
                            pre %= num[2];
                        }
                    }
                    pre += (add - num[2]);
                    pre %= num[2];

                }

                Console.WriteLine(ans.Count);
                foreach (var item in ans)
                {
                    Console.WriteLine(item);
                }
            }
            
            int gcd(int a, int b)
            {
                if (b == 0) return a;
                else return gcd(b, a % b);
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
