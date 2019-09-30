using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public long[,] A;

        public void Run()
        {
            {
                N = Input.ReadInt();
            }

            A = new long[N, 2];
            for (int i = 0; i < N; i++)
            {
                long[] vals = Input.ReadLongArray();
                A[i, 0] = vals[0];
                A[i, 1] = vals[1];
            }

            long sum = 0;
            for (int i = 0; i < N; i++)
            {
                sum += A[i, 0];
            }

            bool same = true;
            for (int i = 0; i < N; i++)
            {
                if (A[i, 0] != A[i, 1]) same = false;
            }

            if (same)
            {
                Console.WriteLine(0);
                return;
            }

            long res = long.MaxValue;
            for (int i = 0; i < N; i++)
            {
                if (A[i, 0] > A[i, 1]) res = Math.Min(res, A[i, 1]);
            }

            long ret = sum - res;

            Console.WriteLine(ret);

        }
        
    }

    // libs ----------
    internal class BinarySearch
    {
        // ???false, ???true????????
        public static bool Cond(long i, long x)
        {
            if (i * i >= x) return true;
            return false;
        }

        // ???Cond?true???index???
        // ?????????????N???
        public static long Search(long x)
        {
            long left = 0;
            long right = 1000000001;

            if (Cond(0, x)) return 0;
            if (!Cond(right - 1, x)) return right;

            while (left + 1 < right)
            {
                long mid = (left + right) / 2;
                if (!Cond(mid, x))
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
            return right;
        }
    }


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