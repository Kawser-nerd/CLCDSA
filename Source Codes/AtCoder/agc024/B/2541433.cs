using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Net.Mail;

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
            var array = Array();
            var result = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = int.Parse(array[i]);
            }

            return result;
        }
        public long[] LongArray()
        {
            var array = Array();
            var result = new long[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = long.Parse(array[i]);
            }

            return result;
        }
    }


    class Program
    {
        private int N;
        private int[] P;
        public void Solve()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            P = new int[N];
            for (int i = 0; i < N; i++)
            {
                P[i] = sc.NextInt() - 1;
            }
            var index = new int[N];
            for (int i = 0; i < N; i++)
            {
                index[P[i]] = i;
            }
            var dp = new int[N];
            for (int i = 0; i < N; i++)
            {
                if (P[i] == 0)
                {
                    dp[i] = 1;
                    continue;
                }
                dp[i] = dp[index[P[i] - 1]] + 1;
            }
            Console.WriteLine(N - dp.Max());
        }

        static void Main(string[] args)
        {
            new Program().Solve();
        }
    }
}