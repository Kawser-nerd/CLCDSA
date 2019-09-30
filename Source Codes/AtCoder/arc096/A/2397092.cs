using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;

namespace Competitive
{
    internal class Solution
    {
        private long A, B, C, X, Y;

        public void Run()
        {
            var line1 = Input.ReadIntArray();
            A = line1[0];
            B = line1[1];
            C = line1[2];
            X = line1[3];
            Y = line1[4];

            var ret = long.MaxValue;
            for (int i = 0; i <= 200000; i++)
            {
                ret = Math.Min(ret, i * C + Math.Max(0, X - i / 2) * A + Math.Max(0, Y - i / 2) * B);
            }
            Console.WriteLine(ret);
        }

    }

    
    internal static class Input
    {
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