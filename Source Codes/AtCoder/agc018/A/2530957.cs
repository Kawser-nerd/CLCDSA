using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{

    internal class Solution
    {
        public int N, K;
        public int[] A;

        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                K = line[1];
            }

            A = Input.ReadIntArray();

            int gcd = A[0];
            for (int i = 1; i < A.Length; i++)
                gcd = Util.GCD(gcd, A[i]);

            bool success = (K % gcd == 0) && (A.Max() >= K);
            Console.WriteLine(success ? "POSSIBLE" : "IMPOSSIBLE");

        }
    }

    // libs ----------
    class Util
    {
        // validation: AOJ 0005
        public static int GCD(int a, int b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }

    }

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