using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _022
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            int n = ReadInt();
            Dictionary<int, bool>[] graph = new Dictionary<int, bool>[n];
            for (int i = 0; i < n; i++)
            {
                graph[i] = new Dictionary<int, bool>();
            }
            for (int i = 0; i < n - 1; i++)
            {
                int[] ab = ReadInts();
                int a = ab[0] - 1;
                int b = ab[1] - 1;
                graph[a].Add(b, true);
                graph[b].Add(a, true);
            }
            Stack<int> stack = new Stack<int>();
            for (int i = 0; i < n; i++)
            {
                if (graph[i].Count == 1) stack.Push(i);
            }

            int[,] lengthes = new int[n, 2];//index.length
            for (int i = 0; i < n; i++) lengthes[i, 0] = i;
            int[] res = new int[3];//left,right,length
            while (stack.Count > 0)
            {
                int now = stack.Pop();
                if (graph[now].Count != 1) continue;

                int to = graph[now].First().Key;
                int next = lengthes[now, 1] + 1;
                int sum = next + lengthes[to, 1];
                if (sum > res[2])
                {
                    res = new int[3]
                    { lengthes[now, 0], lengthes[to, 0], sum };
                }

                if (lengthes[to, 1] < next)
                {
                    lengthes[to, 0] = lengthes[now, 0];
                    lengthes[to, 1] = next;
                }
                graph[to].Remove(now);
                stack.Push(to);
            }
            WriteLine((res[0] + 1) + " " + (res[1] + 1));
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