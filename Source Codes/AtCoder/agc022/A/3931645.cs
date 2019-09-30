using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _022_A
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            string s = Read();
            var remain = new List<char>();
            for(int i = 0; i < 26; i++)
            {
                remain.Add((char)('a' + i));
            }

            for(int i = 0; i < s.Length; i++)
            {
                remain.Remove(s[i]);
            }

            if (s.Length < 26)
            {
                s += remain[0];
                Console.WriteLine(s);
                return;
            }
            else
            {
                for(int i = s.Length - 1; i >= 0; i--)
                {
                    for (int j = 0; j < remain.Count; j++)
                    {
                        if (s[i] < remain[j])
                        {
                            s = s.Substring(0, i);
                            s += remain[j];
                            Console.WriteLine(s);
                            return;
                        }
                    }
                    remain.Add(s[i]);
                    s = s.Substring(0, i);
                }
                Console.WriteLine(-1);
            }
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