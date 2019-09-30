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
        private string S;
        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            S = sc.Next();
        }

        public void Solve()
        {
            Scan();
            int[] cnt = new int[N];
            cnt[0] = 0;
            int[] cnt2 = new int[N];
            cnt[N - 1] = 0;
            for (int i = 1; i < N; i++)
            {
                cnt[i] = cnt[i - 1] + (S[i - 1] == 'E' ? 0 : 1);
                cnt2[N - i - 1] = cnt2[N - i] + (S[N - i] == 'W' ? 0 : 1);
            }

            int ans = int.MaxValue;
            for (int i = 0; i < N; i++)
            {
                ans = Math.Min(ans, cnt[i] + cnt2[i]);
            }
            Console.WriteLine(ans);
        }

        static void Main() => new Program().Solve();
    }
}