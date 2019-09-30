using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public int[] V;
        public int ret = Int32.MaxValue;
        public void Run()
        {
            N = Input.ReadInt();
            V = new int[N];
            for (int i = 0; i < N; i++)
            {
                V[i] = Input.ReadInt();
            }

            var bf = new BruteForceBit(N, Process);
            bf.DFSRun();
            Console.WriteLine(ret);
        }

        public void Process(bool[] F)
        {
            int r1 = 0;
            int r2 = 0;
            for (int i = 0; i < N; i++)
            {
                if (F[i]) r1 += V[i];
                else r2 += V[i];
            }

            int r = Math.Max(r1, r2);
            ret = Math.Min(r, ret);

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