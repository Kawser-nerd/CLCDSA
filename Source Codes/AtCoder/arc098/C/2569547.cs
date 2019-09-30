using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N, K, Q;
        public int[] A, ASort;
        public bool[] B;

        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                K = line[1];
                Q = line[2];
                A = Input.ReadIntArray();
            }

            B = new bool[N];
            for (int i = 0; i < N; i++)
            {
                B[i] = false;
            }

            ASort = new int[N];
            Array.Copy(A, ASort, A.Length);
            Array.Sort(ASort);

            int ret = int.MaxValue;

            for (int x = 0; x < N; x++)
            {
                ret = Math.Min(ret, SolvePartial(x));
            }

            Console.WriteLine(ret);
        }

        // i???????????????????
        public int SolvePartial(int x)
        {
            for (int i = 0; i < N; i++)
            {
                if (A[i] < ASort[x]) B[i] = true;
                else B[i] = false;
            }

            List<int> cand = new List<int>();
            List<int> current = new List<int>();
            for (int i = 0; i < N; i++)
            {
                if (B[i])
                {
                    current.Sort();
                    for (int j = 0; j < current.Count - (K - 1); j++)
                    {
                        cand.Add(current[j]);
                    }
                    current.Clear();
                }
                else
                {
                    current.Add(A[i]);
                }

                if (i == N - 1)
                {
                    current.Sort();
                    for (int j = 0; j < current.Count - (K - 1); j++)
                    {
                        cand.Add(current[j]);
                    }
                    current.Clear();
                }
            }

            cand.Sort();
            if (cand.Count < Q) return int.MaxValue;
            else return cand[Q - 1] - cand[0];

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