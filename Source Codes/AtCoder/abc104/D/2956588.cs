using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public string S;
        public long[] B, C, BC, ABC, T;
        public void Run()
        {
            S = Console.ReadLine();
            int L = S.Length;

            B = new long[S.Length + 1];
            C = new long[S.Length + 1];
            BC = new long[S.Length + 1];
            ABC = new long[S.Length + 1];
            T = new long[S.Length + 1];

            B[L] = 0;
            C[L] = 0;
            BC[L] = 0;
            ABC[L] = 0;
            T[L] = 1;

            for (int i = L - 1; i >= 0; i--)
            {
                if (S[i] == 'A' || S[i] == '?')
                {
                    B[i] += B[i + 1];
                    C[i] += C[i + 1];
                    BC[i] += BC[i + 1];
                    ABC[i] += ABC[i + 1];
                    T[i] += T[i + 1];

                    ABC[i] += BC[i + 1];
                }

                if (S[i] == 'B' || S[i] == '?')
                {
                    B[i] += B[i + 1];
                    C[i] += C[i + 1];
                    BC[i] += BC[i + 1];
                    ABC[i] += ABC[i + 1];
                    T[i] += T[i + 1];

                    B[i] += T[i + 1];
                    BC[i] += C[i + 1];
                }

                if (S[i] == 'C' || S[i] == '?')
                {
                    B[i] += B[i + 1];
                    C[i] += C[i + 1];
                    BC[i] += BC[i + 1];
                    ABC[i] += ABC[i + 1];
                    T[i] += T[i + 1];

                    C[i] += T[i + 1];
                }

                B[i] %= 1000000007;
                C[i] %= 1000000007;
                BC[i] %= 1000000007;
                T[i] %= 1000000007;
                ABC[i] %= 1000000007;
            }

            Console.WriteLine(ABC[0]);
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