using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.AGC_Challenge
{
    class _009_B
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            List<int>[] graph = new List<int>[n];
            int[] childCnts = new int[n];
            int[] parents = new int[n];
            for (int i = 0; i < n; i++) graph[i] = new List<int>();
            for (int i = 1; i < n; i++)
            {
                int a = ReadInt() - 1;
                graph[a].Add(i);
                childCnts[a]++;
                parents[i] = a;
            }
            int[] depthes = new int[n];
            Queue<int> queue = new Queue<int>();
            for(int i = 0; i < n; i++)
            {
                if (childCnts[i] == 0) queue.Enqueue(i);
            }
            while (queue.Count > 0)
            {
                int now = queue.Dequeue();
                int[] nowDepthes = new int[graph[now].Count];
                for(int i = 0; i < nowDepthes.Length; i++)
                {
                    nowDepthes[i] = depthes[graph[now][i]];
                }
                Array.Sort(nowDepthes);
                int depth = 0;
                for (int i = 0; i < nowDepthes.Length; i++)
                {
                    if (depth >= nowDepthes[i]) depth++;
                    else depth = nowDepthes[i] + 1;
                }
                depthes[now] = depth;
                //WriteLine(now + ":" + depth);

                if (now != 0)
                {
                    childCnts[parents[now]]--;
                    if (childCnts[parents[now]] == 0)
                    {
                        queue.Enqueue(parents[now]);
                    }
                }
            }
            WriteLine(depthes[0]);
        }

        static int GetDepth(List<int>[] graph,ref int[] depthes, int now)
        {
            if (depthes[now] >= 0) return depthes[now];

            int len = graph[now].Count;
            if (len == 0) return 0;
            int[] nowDepthes = new int[len];
            for (int i = 0; i < len; i++)
            {
                nowDepthes[i] = GetDepth(graph, ref depthes, graph[now][i]);
            }
            Array.Sort(nowDepthes);
            int depth = 0;
            for (int i = 0; i < len; i++)
            {
                if (depth >= nowDepthes[i]) depth++;
                else depth = nowDepthes[i] + 1;
            }
            depthes[now] = depth;
            return depth;
        }

        private static string Read() { return ReadLine(); }
        private static int ReadInt() { return int.Parse(Read()); }
        private static long ReadLong() { return long.Parse(Read()); }
        private static double ReadDouble() { return double.Parse(Read()); }
        private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
        private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
        private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
    }
}