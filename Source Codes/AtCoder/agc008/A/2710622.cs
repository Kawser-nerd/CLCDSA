using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int X, Y;

        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                X = line[0];
                Y = line[1];
            }

            int ret = int.MaxValue;

            if (Y >= X) ret = Math.Min(ret, Y - X);
            if ((-Y) >= X) ret = Math.Min(ret, (-Y - X) + 1); // 1.. -> Reverse
            if(Y >= (-X)) ret = Math.Min(ret, (Y - (-X)) + 1); // Reverse -> 1..
            if ((-Y) >= (-X)) ret = Math.Min(ret, ((-Y) - (-X)) + 2); // Reverse -> 1.. -> Reverse
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