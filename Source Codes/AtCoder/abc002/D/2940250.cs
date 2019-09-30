using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N, M;
        public bool[,] C;
        public int ret;

        public void Run()
        {
            {
                var line = Input.ReadIntArray();
                N = line[0];
                M = line[1];
            }

            C = new bool[N, N];
            for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                C[i, j] = i == j;

            for (int i = 0; i < M; i++)
            {
                var line = Input.ReadIntArray();
                int x = line[0] - 1;
                int y = line[1] - 1;
                C[x, y] = true;
                C[y, x] = true;
            }

            ret = 0;
            var bf = new BruteForceBit(N, Process);
            bf.DFSRun();

            Console.WriteLine(ret);
        }

        public void Process(bool[] F)
        {
            for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (F[i] && F[j])
                    if (!C[i, j])
                        return;

            ret = Math.Max(ret, F.Select(b => b ? 1 : 0).Sum());
        }

    }

    // libs ----------
    class BruteForceBit
    {
        public int N;
        public bool[] F;
        private Action<bool[]> Process;

        public BruteForceBit(int N, Action<bool[]> process)
        {
            this.N = N;
            F = new bool[N];
            Process = process;
        }

        public void DFSRun()
        {
            DFS(0);
        }

        private void DFS(int i)
        {
            if (i == N)
            {
                Process(F);
            }
            else
            {
                F[i] = true;
                DFS(i + 1);
                F[i] = false;
                DFS(i + 1);
            }
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