using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _016_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string s = Read();
            var freq = new int[26];
            int cnt = s.Length - 1;
            var dict = new Dictionary<char, int>();
            for(int i = 0; i < s.Length; i++)
            {
                if (!dict.ContainsKey(s[i])) dict.Add(s[i], 0);

                dict[s[i]]++;
            }
            foreach(char c in dict.Keys)
            {
                string ss = s;
                if (dict[c] == s.Length)
                {
                    Console.WriteLine(0);
                    return;
                }
                for(int j = 0; j < s.Length; j++)
                {
                    string sss = "";
                    int sameCnt = 0;
                    for (int k = 0; k < ss.Length - 1; k++)
                    {
                        if (ss[k] == c||ss[k+1]==c)
                        {
                            sss += c;
                            sameCnt++;
                        }
                        else
                        {
                            sss += ss[k];
                        }
                    }
                    ss = sss;
                    if (sameCnt == ss.Length)
                    {
                        cnt = Math.Min(cnt, j + 1);
                    }
                }
            }
            Console.WriteLine(cnt);
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}