using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.ARC_A
{
    class _049
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string s = Read();
            int[] abcd = ReadInts();
            var res = new List<char>();
            int now = 0;
            for (int i = 0; i < s.Length; i++)
            {
                if (now < 4 && i == abcd[now])
                {
                    res.Add('"');
                    now++;
                }
                res.Add(s[i]);
            }
            if (now == 3 && s.Length == abcd[now])
            {
                res.Add('"');
                now++;
            }
            Console.WriteLine(res.ToArray());
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