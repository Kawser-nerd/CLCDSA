using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int Q;
        public bool[] P;
        public int[] C;
        public const int PMAX = 100000;
        public void Run()
        {
            P = new bool[PMAX+1];

            for (int i = 2; i <= PMAX; i++)
            {
                P[i] = true;
            }

            for (int i = 2; i <= PMAX; i++)
            {
                if (P[i])
                {
                    for (int j = i * 2; j <= PMAX ; j += i)
                    {
                        P[j] = false;
                    }
                }
            }

            C = new int[PMAX+1];
            int c = 0;
            for (int i = 3; i <= PMAX; i += 2)
            {
                if (P[i] && P[(i + 1) / 2]) c++;
                C[i] = c;
            }


            Q = Input.ReadInt();
            for (int i = 0; i < Q; i++)
            {
                var line = Input.ReadIntArray();
                int l = line[0];
                int r = line[1];

                int a = C[r] - (l == 1 ? 0 : C[l - 2]);

                Console.WriteLine(a);
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