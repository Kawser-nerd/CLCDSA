using System;
using System.Collections.Generic;
using System.Linq;

namespace Competitive
{

    internal class Solution
    {
        public int N, A, B;

        public void Run()
        {
            var line = Input.ReadIntArray();
            N = line[0];
            A = line[1];
            B = line[2];
            
            Console.WriteLine((A - B) % 2 == 0 ? "Alice": "Borys");
        }

    }

    // libs ----------
    
    // common ----------

    internal static class Input
    {
        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
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