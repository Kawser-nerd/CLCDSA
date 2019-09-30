using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace At
{
    class Program
    {
        static void Main(string[] args)
        {
            var s = Read();
            string str="";
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i].ToString() == "A"|| s[i].ToString() == "C"||s[i].ToString() == "G"||s[i].ToString() == "T")
                {
                    str += "1";
                }
                else
                {
                    str += "0";
                }
            }

            if (str.Contains("1111111111"))
            {
                Console.WriteLine("10");
            }
            else if (str.Contains("111111111"))
            {
                Console.WriteLine("9");
            }
            else if (str.Contains("11111111"))
            {
                Console.WriteLine("8");
            }
            else if (str.Contains("1111111"))
            {
                Console.WriteLine("7");
            }
            else if (str.Contains("111111"))
            {
                Console.WriteLine("6");
            }
            else if (str.Contains("11111"))
            {
                Console.WriteLine("5");
            }
            else if (str.Contains("1111"))
            {
                Console.WriteLine("4");
            }
            else if (str.Contains("111"))
            {
                Console.WriteLine("3");
            }
            else if (str.Contains("11"))
            {
                Console.WriteLine("2");
            }
            else if (str.Contains("1"))
            {
                Console.WriteLine("1");
            }
            else
            {
                Console.WriteLine("0");
            }

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