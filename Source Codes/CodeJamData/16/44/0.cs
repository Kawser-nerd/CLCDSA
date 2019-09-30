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


            int N;
            int[,] move;


            public void input()
            {
                N = cin.nextInt();
                move = new int[N, N];
                for (int i = 0; i < N; i++)
                {
                    string S = cin.next();
                    for (int j = 0; j < N; j++)
                    {
                        move[i, j] = S[j] - '0';
                    }
                }
            }

            public void calc()
            {
                int ans = N * N;
                for (int t = 0; t < (1 << (N * N)); t++)
                {
                    int now = bitCount(t);
                    if (now >= ans) continue;

                    int[,] a = new int[N, N];
                    for (int i = 0; i < N; i++)
                    {
                        for (int j = 0; j < N; j++)
                        {
                            a[i, j] = move[i, j] | ((t >> (N * i + j)) % 2);
                        }
                    }

                    if (check(a))
                    {
                        ans = now;
                    }
                }
                Console.WriteLine(ans);
            }


            bool check(int[,] a)
            {
                int[] person = new int[N];
                int[] machine = new int[N];
                for (int i = 0; i < N; i++)
                {
                    person[i] = machine[i] = i;
                }

                do
                {
                    Array.Sort(machine);
                    do
                    {
                        bool[] used = new bool[N];
                        for (int i = 0; i < N; i++)
                        {
                            for (int j = 0; j <= N; j++)
                            {
                                if (j == N) return false;
                                if (used[machine[j]]) continue;
                                if (a[person[i], machine[j]] == 0) continue;
                                used[machine[j]] = true;
                                break;
                            }
                        }

                    } while (next_permutation(machine));
                } while (next_permutation(person));
                return true;
            }

            int bitCount(long x)
            {
                x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);
                x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
                x = (x & 0x0f0f0f0f0f0f0f0f) + (x >> 4 & 0x0f0f0f0f0f0f0f0f);
                x = (x & 0x00ff00ff00ff00ff) + (x >> 8 & 0x00ff00ff00ff00ff);
                x = (x & 0x0000ffff0000ffff) + (x >> 16 & 0x0000ffff0000ffff);
                return (int)((x & 0x00000000ffffffff) + (x >> 32 & 0x00000000ffffffff));
            }

            public static bool next_permutation<T>(T[] array) where T : IComparable<T>
            {
                return next_permutation(array, 0, array.Length);
            }

            public static bool next_permutation<T>(T[] array, int start, int length) where T : IComparable<T>
            {
                int end = start + length - 1;
                if (end <= start) return false;
                int last = end;
                while (true)
                {
                    int pos = last--;
                    if (array[last].CompareTo(array[pos]) < 0)
                    {
                        int i;
                        for (i = end + 1; array[last].CompareTo(array[--i]) >= 0;) { }
                        T tmp = array[last]; array[last] = array[i]; array[i] = tmp;
                        Array.Reverse(array, pos, end - pos + 1);
                        return true;
                    }
                    if (last == start)
                    {
                        //Array.Reverse(array, start, end - start);
                        return false;
                    }
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
