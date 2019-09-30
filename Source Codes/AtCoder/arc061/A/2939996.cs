using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        string S;
        public bool[] F;
        public long ret;
        public void Run()
        {
            S = Console.ReadLine();
            N = S.Length;
            F = new bool[S.Length];
            DFSRun();
            Console.WriteLine(ret);
        }

        void DFSRun()
        {
            ret = 0;
            DFS(0);
        }

        void DFS(int i)
        {
            if (i == N - 1)
            {
                F[i] = true;
                ret += Calc();
            }
            else
            {
                F[i] = true;
                DFS(i + 1);
                F[i] = false;
                DFS(i + 1);
            }
        }

        public long Calc()
        {
            long ret = 0;
            int st = 0;
            for (int i = 0; i < N; i++)
            {
                if (F[i])
                {
                    int en = i + 1;
                    ret += long.Parse(S.Substring(st, en - st));
                    st = i + 1;
                }
            }

            return ret;
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