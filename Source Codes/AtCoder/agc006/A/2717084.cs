using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public string S, T;

        public void Run()
        {
            N = Input.ReadInt();
            S = Console.ReadLine();
            T = Console.ReadLine();

            int overlap = 0;
            int overlapMax = Math.Min(S.Length, T.Length);
            for (int o = overlapMax; o >= 1; o--)
            {
                bool flg = true;
                for (int j = 0; j < o; j++)
                {
                    if (T[j] != S[S.Length - o + j])
                    {
                        flg = false;
                        break;
                    }
                }

                if (flg)
                {
                    overlap = o;
                    break;
                }
            }

            Console.WriteLine(S.Length + T.Length - overlap);
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