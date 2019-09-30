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
                A = Input.ReadIntArray();
            }

            Dictionary<int, int> count = new Dictionary<int, int>();

            for (int i = 0; i < N; i++)
            {
                if(!count.ContainsKey(A[i])) count.Add(A[i], 0);
                count[A[i]]++;
            }

            List<int> c = new List<int>();
            foreach (var kv in count)
            {
                c.Add(kv.Value);
            }

            c.Sort();

            int ret = 0;
            for (int i = 0; i < c.Count - K; i++) ret += c[i];
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