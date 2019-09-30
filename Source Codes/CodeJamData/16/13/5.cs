using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;

namespace Codejam
{
    class C
    {
        private static ThreadStart s_threadStart = new C().Go;
        private static bool s_time = false;

        private void Test(int tt)
        {
            int N = GetInt();
            int[] next = new int[N + 1];
            List<int>[] inverseTree = new List<int>[N + 1];
            for (int i = 1; i <=N; i++)
            {
                inverseTree[i] = new List<int>();
            }
            for (int i = 1; i <= N; i++)
            {
                next[i] = GetInt();
                inverseTree[next[i]].Add(i);
            }

            int ans = 0;

            for (int i = 1; i <= N; i++)
            {
                if (next[i] > i && next[next[i]] == i)
                {
                    int s1 = i;
                    int s2 = next[i];

                    int tmpAns = 2;
                    int maxDepth = 0;

                    maxDepth = 0;
                    foreach (int child in inverseTree[s1])
                        if (child != s2)
                            maxDepth = Math.Max(maxDepth, Depth(inverseTree, child));
                    tmpAns += maxDepth;

                    maxDepth = 0;
                    foreach (int child in inverseTree[s2])
                        if (child != s1)
                            maxDepth = Math.Max(maxDepth, Depth(inverseTree, child));
                    tmpAns += maxDepth;

                    ans += tmpAns;
                }
            }

            bool[] visited = new bool[N + 1];
            for (int i = 1; i <= N; i++)
            {
                if (!visited[i])
                {
                    bool breakout = false;
                    int curr = i;
                    HashSet<int> set = new HashSet<int>();
                    while (!set.Contains(curr))
                    {
                        if (visited[curr])
                        {
                            breakout = true;
                            break;
                        }

                        visited[curr] = true;
                        set.Add(curr);
                        curr = next[curr];
                    }
                    if (breakout)
                        continue;

                    int count = 1;
                    int p = next[curr];
                    while (p != curr)
                    {
                        count++;
                        p = next[p];
                    }

                    ans = Math.Max(ans, count);
                }
            }

            Wl(tt, ans);
        }

        private int Depth(List<int>[] adj, int root)
        {
            if (adj[root].Count == 0) return 1;
            int ans = 0;
            foreach (int child in adj[root])
                ans = Math.Max(ans, Depth(adj, child));

            return ans + 1;
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
            Thread main = new Thread(new ThreadStart(s_threadStart));
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