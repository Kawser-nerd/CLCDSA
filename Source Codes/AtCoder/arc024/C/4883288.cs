using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _024
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nk = ReadInts();
            int n = nk[0];
            int k = nk[1];

            string s = Read();
            int[][] cnts = new int[n - k + 1][];
            cnts[0] = new int[27];
            for (int i = 0; i < k; i++) cnts[0][s[i] - 'a']++;
            cnts[0][26] = 0;
            for(int i = 1; i < n - k + 1; i++)
            {
                cnts[i] = new int[27];
                for (int j = 0; j < 26; j++) cnts[i][j] = cnts[i - 1][j];
                cnts[i][s[i - 1] - 'a']--;
                cnts[i][s[i + k - 1] - 'a']++;
                cnts[i][26] = i;
            }
            for (int i = 0; i < 26; i++)
            {
                cnts = cnts.OrderBy(a => a[i]).ToArray();
            }
            int now = 0;
            for (int i = 0; i < n - k + 1; i++)
            {
                bool same = true;
                for(int j = 0; j < 26; j++)
                {
                    if (cnts[now][j] != cnts[i][j])
                    {
                        same = false;
                        break;
                    }
                }
                if (same)
                {
                    if (cnts[now][26] + k <= cnts[i][26])
                    {
                        WriteLine("YES");
                        return;
                    }
                }
                else
                {
                    now = i;
                }
            }
            WriteLine("NO");
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}