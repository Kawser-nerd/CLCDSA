using System;
using System.Collections.Generic;
using System.Linq;

namespace abc014_4
{
    class Program
    {
        static List<int>[] edge;
        static int[,] parent;
        static int[] depth;
        static void Dfs(int deep, int a)
        {
            depth[a] = deep;
            foreach (var item in edge[a])
            {
                if (parent[item, 0] == 0 && item != 1)
                { parent[item, 0] = a; Dfs(deep + 1, item); }
            }
        }
        static int Doubleing(int x, int count)
        {
            for (int i = 0; i < 20; i++)
            {
                if ((count & (1 << i)) > 0) x = parent[x, i];
            }
            return x;
        }
        static int Binary_search(int index1, int index2, int count1, int count2)
        {
            int ng = -1;
            int ok = 1 << 21;

            while (Math.Abs(ok - ng) > 1)
            {
                int mid = ng + (ok - ng) / 2;

                if (Doubleing(index1, count1 + mid) == Doubleing(index2, count2 + mid)) ok = mid;
                else ng = mid;
            }

            return Doubleing(index1, count1 + ok);
        }
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            edge = new List<int>[n + 1];
            for (int i = 0; i <= n; i++) edge[i] = new List<int>();
            for (int i = 1; i < n; i++)
            {
                int[] x = Console.ReadLine().Split().Select(int.Parse).ToArray();
                edge[x[0]].Add(x[1]); edge[x[1]].Add(x[0]);
            }
            parent = new int[n + 1, 20]; depth = new int[n + 1];
            Dfs(0, 1); parent[1, 0] = 1;
            for (int i = 1; i < 20; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    parent[j, i] = parent[parent[j, i - 1], i - 1];
                }
            }
            int q = int.Parse(Console.ReadLine());
            for (int i = 0; i < q; i++)
            {
                int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();
                int depth1 = depth[a[0]]; int depth2 = depth[a[1]];
                int ret = depth1 + depth2; int min = Math.Min(depth1, depth2);
                depth1 -= min; depth2 -= min;
                Console.WriteLine(ret - depth[Binary_search(a[0], a[1], depth1, depth2)] * 2 + 1);
            }
        }
    }
}