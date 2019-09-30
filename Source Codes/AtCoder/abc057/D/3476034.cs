using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N, A, B;
        public long[] V;
        public long MOD = 1000000007;

        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                A = line[1];
                B = line[2];
            }
            V = Input.ReadLongArray();
            Array.Sort(V);
            Array.Reverse(V);

            var comb = new PascalCombination(100);
            comb.Run();
            
            long val = V[A - 1];
            int up = 0;
            int same = 0;

            for (int i = 0; i < N; i++)
            {
                if (V[i] > val) up++;
                if (V[i] == val) same++;
            }

            {
                long retc = 0;
                int mn = A - up;
                int mx;
                if (up == 0)
                {
                    mx = Math.Min(same, B - up);
                }
                else
                {
                    mx = mn;
                }
                    
                for (int j = mn; j <= mx ; j++)
                {
                    Console.Error.WriteLine($"{same} {j}");
                    retc += comb.Combination(same, j);
                }

                double avg = V.Take(A).Sum() * 1.0 / A;
                Console.WriteLine(avg);
                Console.WriteLine(retc);
            }
        }
    }

    // libs ----------
    // ?????????N????mod???????
    class PascalCombination
    {
        public long N;
        public long[,] Comb;

        public PascalCombination(int N)
        {
            this.N = N;
            Comb = new long[N + 1, N + 1];
        }

        public void Run()
        {
            // i == 0????
            Comb[0, 0] = 1;

            // i => 1????
            for (int i = 1; i <= N; i++)
            {
                for (int j = 0; j <= N; j++)
                    if (j == 0)
                    {
                        Comb[i, j] = 1;
                    }
                    else
                    {
                        Comb[i, j] = Comb[i - 1, j - 1] + Comb[i - 1, j];
                    }
            }
        }

        public long Combination(int n, int k)
        {
            if (k < 0 || k > n) return 0;
            return Comb[n, k];
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