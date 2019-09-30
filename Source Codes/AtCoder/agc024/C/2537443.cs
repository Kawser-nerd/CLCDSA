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
            N = Input.ReadInt();
            A = new int[N];
            for (int i = 0; i < N; i++)
            {
                A[i] = Input.ReadInt();
            }

            // check
            if (A[0] != 0)
            {
                Console.WriteLine(-1);
                return;
            }

            for (int i = 0; i < N - 1; i++)
            {
                if (A[i + 1] > A[i] + 1)
                {
                    Console.WriteLine(-1);
                    return;
                }
            }

            // solve
            long ret = 0;
            int load = -1;
            for (int i = N - 1; i >= 0; i--)
            {
                if (load != A[i])
                {
                    ret += A[i];
                }

                load = A[i];
                load--;
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