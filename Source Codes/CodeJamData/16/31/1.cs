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
                Console.WriteLine("Case #{0}: {1}", i + 1, SV[i].calc());
            }
            
        }



        class Solve
        {
            public Solve() { }

            public static Scanner cin;

            int N;
            int[] num;
            public void input()
            {
                N = cin.nextInt();
                num = new int[N];
                for (int i = 0; i < N; i++)
                {
                    num[i] = cin.nextInt();
                }
            }
            
            public string calc()
            {
                int sum = num.Sum();
                int turn = (sum + 1) / 2;

                List<string> ansl = new List<string>();
                for (int i = 0; i < turn; i++)
                {
                    string ans = "";
                    while (ans.Length == 0 || sum % 2 != 0)
                    {
                        int maxnum = -1;
                        int maxp = -1;
                        for (int j = 0; j < N; j++)
                        {
                            if (num[j] > maxnum)
                            {
                                maxnum = num[j];
                                maxp = j;
                            }
                        }
                        num[maxp]--;
                        ans += (char)('A' + maxp);
                        sum--;
                    }
                    ansl.Add(ans);
                }


                return String.Join(" ", ansl);
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
