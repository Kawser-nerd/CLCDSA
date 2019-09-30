using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.C_Challenge
{
    class ABC_076
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            char[] s = Console.ReadLine().ToCharArray();
            char[] t = Console.ReadLine().ToCharArray();
            for (int i = s.Length - t.Length; i >= 0; i--)
            {
                bool ok = true;
                for(int j = 0; j < t.Length; j++)
                {
                    if (s[i + j] == t[j] || s[i + j] == '?')
                    {
                        continue;
                    }
                    else
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                {
                    for(int j = 0; j < t.Length; j++)
                    {
                        s[i + j] = t[j];
                    }
                    string result = new string(s).Replace('?', 'a');
                    Console.WriteLine(result);
                    return;
                }
                else
                {
                    continue;
                }
            }
            Console.WriteLine("UNRESTORABLE");
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