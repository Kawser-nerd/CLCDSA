using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int K;
        public int[] A;
        public void Run()
        {
            K = Input.ReadInt();
            A = Input.ReadIntArray();
            A = A.Reverse().ToArray();

            long mn = 2;
            long mx = 2;
            for (int i = 0; i < A.Length; i++)
            {
                long a = A[i];
                mn = mn % a == 0 ? mn : (mn / a + 1) * a;
                mx = (mx / a) * a;
                mx += (a - 1);
            }

            if (mx < mn)
            {
                Console.WriteLine(-1);
            }
            else
            {
                Console.WriteLine("{0} {1}", mn, mx);
            }
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