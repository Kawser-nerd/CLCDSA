using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using static System.Console;
using static System.Math;

namespace AtTest.ARC_C
{
    class _011
    {
        static void Main(string[] args)
        {
            Method(args);
            ReadLine();
        }

        static void Method(string[] args)
        {
            string[] fl = Read().Split();
            int n = ReadInt();
            char[][] ss = new char[n+2][];
            ss[0] = fl[0].ToCharArray();
            ss[n + 1] = fl[1].ToCharArray();
            for(int i =1; i <= n; i++)
            {
                ss[i] = Read().ToCharArray();
            }

            if (fl[0].Equals(fl[1]))
            {
                WriteLine(0);
                WriteLine(ss[0]);
                WriteLine(ss[n + 1]);
                return;
            }

            List<int>[] graph = new List<int>[n + 2];
            for (int i = 0; i < n + 2; i++)
            {
                graph[i] = new List<int>();
                for (int j = 0; j < n + 2; j++)
                {
                    if (i == j) continue;

                    int difCnt = ss[i].Length;
                    for (int k = 0; k < ss[i].Length; k++)
                    {
                        if (ss[i][k] == ss[j][k]) difCnt--;
                    }
                    if (difCnt == 1) graph[i].Add(j);
                }
            }
            Queue<int[]> queue = new Queue<int[]>();
            queue.Enqueue(new int[2] { 0, 0 });
            int[] dist = new int[n + 2];
            for (int i = 0; i < n + 2;i++) dist[i] = int.MaxValue;
            bool can = false;
            while (queue.Count > 0)
            {
                int[] val = queue.Dequeue();
                if (dist[val[0]] <= val[1]) continue;

                dist[val[0]] = val[1];
                if (val[0] == n + 1)
                {
                    can = true;
                    break;
                }

                for(int i = 0; i < graph[val[0]].Count; i++)
                {
                    queue.Enqueue(new int[2]
                    {
                        graph[val[0]][i],val[1]+1
                    });
                }
            }
            if (can)
            {
                int len = dist[n + 1] + 1;
                int[] resIndex = new int[len];
                resIndex[len - 1] = n + 1;
                for(int i = len - 1; i > 0; i--)
                {
                    for(int j = 0; j < graph[resIndex[i]].Count; j++)
                    {
                        int index = graph[resIndex[i]][j];
                        if (dist[resIndex[i]] == dist[index] + 1)
                        {
                            //WriteLine(dist[index]);
                            resIndex[i - 1] = index;
                            break;
                        }
                    }
                }
                WriteLine(len - 2);
                for(int i = 0; i < len; i++)
                {
                    WriteLine(ss[resIndex[i]]);
                }
            }
            else
            {
                WriteLine(-1);
            }
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