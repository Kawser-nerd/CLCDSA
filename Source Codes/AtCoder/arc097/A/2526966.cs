using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive.lib
{

    internal class Solution
    {
        public string S;
        public int K;

        public void Run()
        {
            List<string> lst = new List<string>();

            S = Console.ReadLine();
            K = Input.ReadInt();

            for (int i = 0; i < S.Length; i++)
            {
                for (int k = 1; k <= K; k++)
                {
                    if(i + k <= S.Length) lst.Add(S.Substring(i, k));
                }
            }

            lst = lst.Distinct().ToList();
            lst.Sort();
            Console.WriteLine(lst[K-1]);
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