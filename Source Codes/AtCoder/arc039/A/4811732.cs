using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_A
{
    class _039
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            string[] ab = Read().Split();
            char[] a = ab[0].ToCharArray();
            char[] b = ab[1].ToCharArray();
            int max = -5000;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j <= 9; j++)
                {
                    if (i == 0 && j == 0) continue;

                    char aNow = a[i];
                    char bNow = b[i];
                    
                    a[i] = (char)('0' + j);
                    int val = int.Parse(new string(a))
                        - int.Parse(new string(b));
                    a[i] = aNow;
                    b[i] = (char)('0' + j);
                    int val2 = int.Parse(new string(a))
                        - int.Parse(new string(b));
                    max = Max(max, Max(val, val2));
                    b[i] = bNow;
                }
            }
            WriteLine(max);
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