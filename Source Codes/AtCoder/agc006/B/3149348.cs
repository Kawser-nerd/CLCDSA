using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N, X;
        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                X = line[1];
            }

            if (X == 1 || X == 2 * N - 1)
            {
                Console.WriteLine("No");
                return;
            }
            else
            {
                Console.WriteLine("Yes");
            }

            int[] A = new int[2 * N - 1];

            int c = 2;
            for (int i = 0; i < 2 * N - 1; i++)
            {
                if (i == N - 1) A[i] = X;
                else if (i == N - 2) A[i] = 1;
                else if (i == N) A[i] = 2 * N - 1;
                else
                {
                    if (c == X) c++;
                    A[i] = c;
                    c++;
                }

                Console.WriteLine(A[i]);
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