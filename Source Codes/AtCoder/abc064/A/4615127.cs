using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Program
    {
        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }

        private static void Yes() { print("YES"); }
        private static void No() { print("NO"); }
        private static void print(object obj) { Console.WriteLine(obj); }

        static void Main(string[] args)
        {
            var a = ReadInts();
            if ((a[0] * 100 + a[1] * 10 + a[2]) % 4 == 0)
            {
                Yes();
            }
            else
            {
                No();
            }

        }
    }
}