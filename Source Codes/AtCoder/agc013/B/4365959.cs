using System;
using System.Collections.Generic;
using System.Text;

namespace AtTest.AGC_Challenge
{
    class _013_B
    {
        static void Main(string[] args)
        {
            Method(args);
            Console.ReadLine();
        }

        static void Method(string[] args)
        {
            int[] nm = ReadInts();
            int n = nm[0];
            int m = nm[1];
            List<int>[] graph = new List<int>[n];
            for(int i = 0; i < n; i++)
            {
                graph[i] = new List<int>();
            }
            for(int i = 0; i < m; i++)
            {
                int[] ab = ReadInts();
                int a = ab[0] - 1;
                int b = ab[1] - 1;
                graph[a].Add(b);
                graph[b].Add(a);
            }
            bool[] visites = new bool[n];
            List<int> startPaths = new List<int>();
            List<int> endPaths = new List<int>();
            int now = 0;
            while (true)
            {
                startPaths.Add(now);
                visites[now] = true;
                bool proceedTemp = false;
                for(int i = 0; i < graph[now].Count; i++)
                {
                    if (!visites[graph[now][i]])
                    {
                        proceedTemp = true;
                        now = graph[now][i];
                        break;
                    }
                }
                if (!proceedTemp)
                {
                    break;
                }
            }
            now = 0;
            while (true)
            {
                endPaths.Add(now);
                visites[now] = true;
                bool proceedTemp = false;
                for (int i = 0; i < graph[now].Count; i++)
                {
                    if (!visites[graph[now][i]])
                    {
                        proceedTemp = true;
                        now = graph[now][i];
                        break;
                    }
                }
                if (!proceedTemp)
                {
                    break;
                }
            }

            Console.WriteLine(startPaths.Count + endPaths.Count - 1);
            for(int i = startPaths.Count-1; i>=0; i--)
            {
                Console.Write((startPaths[i] + 1) + " ");
            }
            for(int i = 1; i < endPaths.Count; i++)
            {
                Console.Write((endPaths[i] + 1) + " ");
            }
            Console.WriteLine();
        }

        private static string Read() { return Console.ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}