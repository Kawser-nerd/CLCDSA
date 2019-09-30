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
            var b = Read();
            switch (b)
            {
                case "A":
                    WriteLine("T");
                    break;
                case "T":
                    WriteLine("A");
                    break;
                case "C":
                    WriteLine("G");
                    break;
                case "G":
                    WriteLine("C");
                    break;

                default:
                    break;
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