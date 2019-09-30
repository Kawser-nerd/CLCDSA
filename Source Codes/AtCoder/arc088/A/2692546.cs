using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long X, Y;

        public void Run()
        {
            Input.ReadLongArray(out X, out Y);

            int ret = 0;
            long a = X;
            while (true)
            {
                ret++;
                a *= 2;
                if (a > Y) break;
            }

            Console.WriteLine(ret);
        }
    }

    // libs ----------
    

    // common ----------

    internal static class Input
    {
        public static string ReadString()
        {
            string line = Console.ReadLine();
            return line;
        }

        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
        }

        public static void ReadLongArray(out long v1, out long v2)
        {
            string line = Console.ReadLine();
            var ary = line.Split(' ').Select(long.Parse).ToArray();
            v1 = ary[0];
            v2 = ary[1];
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static long[] ReadLongArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(double.Parse).ToArray();
        }
    }
    
    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solution();
            s.Run();
        }
    }
}