using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public int[] A;

        public void Run()
        {
            {
                N = Input.ReadInt();
                A = Input.ReadIntArray();
            }

            Dictionary<int, int> count = new Dictionary<int, int>();

            for (int i = 0; i < N; i++)
            {
                if(!count.ContainsKey(A[i])) count.Add(A[i], 0);
                count[A[i]]++;
            }

            long ret = 0;
            foreach (var kv in count)
            {
                if (kv.Value < kv.Key) ret += kv.Value;
                else ret += kv.Value - kv.Key;
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