using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_B
{
    class _014
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            var dict = new Dictionary<string, bool>();
            string res = "DRAW";
            bool done = false;
            string first = Read();
            dict.Add(first, true);
            char prevLast = first[first.Length - 1];
            for(int i = 1; i < n; i++)
            {
                string s = Read();
                if (done) continue;
                if (dict.ContainsKey(s) || prevLast != s[0])
                {
                    if (i % 2 == 0)
                    {
                        res = "LOSE";
                    }
                    else
                    {
                        res = "WIN";
                    }
                    done = true;
                }
                else
                {
                    dict.Add(s, true);
                    prevLast = s[s.Length - 1];
                }
            }
            WriteLine(res);
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