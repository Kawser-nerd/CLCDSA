using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace AtCoder.ABC109.D
{
    class Program
    {
        static void Main()
        {
            var sc = new Scanner();
            var h = sc.Nextint();
            var w = sc.Nextint();
            var a = new int[h][];
            for (int i = 0; i < h; i++)
            {
                a[i] = sc.Arrayint(w);
            }

            var operations = new List<string>();
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (a[i][j] % 2 != 0)
                    {
                        if (j + 1 < w)
                        {
                            a[i][j]--;
                            a[i][j + 1]++;
                            operations.Add(string.Format("{0} {1} {0} {2}", i + 1, j + 1, j + 2));
                        }
                        else if (i + 1 < h)
                        {
                            a[i][j]--;
                            a[i + 1][j]++;
                            operations.Add(string.Format("{0} {1} {2} {1}", i + 1, j + 1, i + 2));
                        }
                    }
                }
            }
            Console.WriteLine(operations.Count);
            foreach (var item in operations)
            {
                Console.WriteLine(item);
            }

            // for (int i = 0; i < h; i++)
            // {
            //     Console.Error.WriteLine(string.Join(" ", a[i]));
            // }
        }
    }
    class Scanner
    {
        string[] s;
        long i;

        char[] cs = new char[] { ' ' };

        public Scanner()
        {
            s = new string[0];
            i = 0;
        }

        public string Next()
        {
            if (i < s.Length) return s[i++];
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            if (s.Length == 0) return Next();
            i = 0;
            return s[i++];
        }

        public int Nextint()
        {
            return int.Parse(Next());
        }
        public int[] Arrayint(int N, int add = 0)
        {
            int[] Array = new int[N];
            for (int i = 0; i < N; i++)
            {
                Array[i] = Nextint() + add;
            }
            return Array;
        }

        public long NextLong()
        {
            return long.Parse(Next());
        }

        public long[] ArrayLong(int N, long add = 0)
        {
            long[] Array = new long[N];
            for (long i = 0; i < N; i++)
            {
                Array[i] = NextLong() + add;
            }
            return Array;
        }

        public double NextDouble()
        {
            return double.Parse(Next());
        }

        public double[] ArrayDouble(long N, double add = 0)
        {
            double[] Array = new double[N];
            for (long i = 0; i < N; i++)
            {
                Array[i] = NextDouble() + add;
            }
            return Array;
        }

        public decimal NextDecimal()
        {
            return decimal.Parse(Next());
        }

        public decimal[] ArrayDecimal(long N, decimal add = 0)
        {
            decimal[] Array = new decimal[N];
            for (long i = 0; i < N; i++)
            {
                Array[i] = NextDecimal();
            }
            return Array;
        }
    }
}