using System;
using System.Collections.Generic;
using System.Linq;

namespace Competitive
{
    internal class Solution
    {
        private long N, M;
        
        public void Run()
        {
            int[] ary = Input.ReadIntArray();
            N = ary[0];
            M = ary[1];

            if (N > M)
            {
                long tmp = N;
                N = M;
                M = tmp;
            }

            if (N >= 2)
            {
                Console.WriteLine((N - 2) * (M - 2));
            }
            else if (M >= 2)
            {
                Console.WriteLine(M - 2);
            }
            else
            {
                Console.WriteLine(1);
            }

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