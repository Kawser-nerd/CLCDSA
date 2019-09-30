using System;
using System.Collections.Generic;
using System.Linq;

namespace Competitive
{
    internal class Solution
    {
        private int N, K;
        
        public void Run()
        {
            int[] ary = Input.ReadIntArray();
            N = ary[0];
            K = ary[1];

            long ret = 0;
            for (int b = K + 1; b <= N; b++)
            {
                int res = K == 0 ? N % b : Math.Max(0, N % b - K + 1);
                ret += (N / b) * (b - K) + res;
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