using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.D_Challenge
{
    class ABC_064
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            string s = Read();
            int requireLeft = 0;
            int requireRight = 0;
            for(int i = 0; i < n; i++)
            {
                if (s[i] == ')')
                {
                    if (requireRight > 0)
                    {
                        requireRight--;
                    }
                    else
                    {
                        requireLeft++;
                    }
                }
                else
                {
                    requireRight++;
                }
            }

            string res = "";
            for(int i = 0; i < requireLeft; i++)
            {
                res += "(";
            }
            res += s;
            for(int i = 0; i < requireRight; i++)
            {
                res += ")";
            }
            Console.WriteLine(res);
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