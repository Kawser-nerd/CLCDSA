using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codejam
{
    class B
    {
        private static ThreadStart s_threadStart = new B().Go;
        private static bool s_time = false;

        int N;
        Node[] nodes;
        class Node
        {
            public int Id;
            public int Parent;
            public List<int> Adj = new List<int>();
            public int SubtreeCount;
            public int SubtreRemoved;
        }

        void Solve(int start)
        {
            Node node = nodes[start];
            int childCount = node.Adj.Count;
            if (node.Parent >= 0) childCount--;

            List<int> diffs = new List<int>();
            node.SubtreeCount = 1;
            foreach (int i in node.Adj)
            {
                if (node.Parent != i)
                {
                    nodes[i].Parent = start;
                    Solve(i);
                    node.SubtreeCount += nodes[i].SubtreeCount;

                    diffs.Add(nodes[i].SubtreeCount - nodes[i].SubtreRemoved);
                }
            }

            node.SubtreRemoved = node.SubtreeCount - 1;
            if (childCount >= 2)
            {
                diffs.Sort();
                diffs.Reverse();
                node.SubtreRemoved -= diffs[0] + diffs[1];
            }
        }


        private void Test(int tt)
        {
            N = GetInt();
            nodes = new Node[N];
            for (int i = 0; i < N; i++)
            {
                nodes[i] = new Node()
                {
                    Id = i
                };
            }

            for (int i = 0; i < N - 1; i++)
            {
                int x = GetInt()-1;
                int y = GetInt()-1;
                nodes[x].Adj.Add(y);
                nodes[y].Adj.Add(x);
            }

            int ans = N - 1;
            for (int i = 0; i < N; i++)
            {
                nodes[i].Parent = -1;
                Solve(i);
                ans = Math.Min(ans, nodes[i].SubtreRemoved);
            }

            Wl(tt, ans);
        }

        #region Template

        private void Go()
        {
            int T = GetInt();
            for (int t = 1; t <= T; t++)
            {
                Test(t);
            }
        }

        public static void Main(string[] args)
        {
            System.Diagnostics.Stopwatch timer = new System.Diagnostics.Stopwatch();
            Thread main = new Thread(new ThreadStart(s_threadStart), 1 * 1024 * 1024 * 1024);
            timer.Start();
            main.Start();
            main.Join();
            timer.Stop();
            if (s_time)
                Console.WriteLine(timer.ElapsedMilliseconds);
        }

        private static IEnumerator<string> ioEnum;
        private static string GetString()
        {
            do
            {
                while (ioEnum == null || !ioEnum.MoveNext())
                {
                    ioEnum = Console.ReadLine().Split().AsEnumerable().GetEnumerator();
                }
            } while (string.IsNullOrEmpty(ioEnum.Current));

            return ioEnum.Current;
        }

        private static int GetInt()
        {
            return int.Parse(GetString());
        }

        private static long GetLong()
        {
            return long.Parse(GetString());
        }

        private static double GetDouble()
        {
            return double.Parse(GetString());
        }

        private static List<int> GetIntArr(int n)
        {
            List<int> ret = new List<int>(n);
            for (int i = 0; i < n; i++)
            {
                ret.Add(GetInt());
            }
            return ret;
        }

        private static void Wl<T>(int testCase, T o)
        {
            Console.WriteLine("Case #{0}: {1}", testCase, o.ToString());
        }

        private static void Wl<T>(int testCase, IEnumerable<T> enumerable)
        {
            Wl(testCase, string.Join(" ", enumerable.Select(e => e.ToString()).ToArray()));
        }

        #endregion
    }
}