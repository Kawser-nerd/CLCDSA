using System;
using System.Linq;
using System.Collections.Generic;
using static System.Math;
using MethodImplAttribute = System.Runtime.CompilerServices.MethodImplAttribute;
using MethodImplOptions = System.Runtime.CompilerServices.MethodImplOptions;
using LayoutKind = System.Runtime.InteropServices.LayoutKind;
using StructLayoutAttribute = System.Runtime.InteropServices.StructLayoutAttribute;
using FieldOffsetAttribute = System.Runtime.InteropServices.FieldOffsetAttribute;

class P
{
    static void Main()
    {
        var nm = Console.ReadLine().Split().Select(int.Parse).ToList();
        var n = nm[0];
        var m = nm[1];
        int[,] adjacencyMatrix = new int[n, n];
        for (int i = 0; i < m; i++)
        {
            var ab = Console.ReadLine().Split().Select(x => int.Parse(x) - 1).ToList();
            adjacencyMatrix[ab[0], ab[1]] = 1;
            adjacencyMatrix[ab[1], ab[0]] = 1;
        }

        List<List<int>> neighbours = Enumerable.Repeat(0, n).Select(_ => new List<int>()).ToList();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j) continue;
                if (adjacencyMatrix[i, j] == 0) neighbours[i].Add(j);
            }
        }

        int[] mark = new int[n];
        List<Tuple<int, int>> groups = new List<Tuple<int, int>>();
        for (int i = 0; i < n; i++)
        {
            if (mark[i] != 0) continue;
            int a = 0, b = 0;
            Stack<Tuple<int, int>> stack = new Stack<Tuple<int, int>>();
            stack.Push(new Tuple<int, int>(i, 1));
            while (stack.Count > 0)
            {
                var item = stack.Pop();
                if (mark[item.Item1] == -item.Item2) goto invalid;
                else if (mark[item.Item1] == item.Item2) continue;
                if (item.Item2 == 1) a++;
                else b++;
                mark[item.Item1] = item.Item2;
                foreach (var neighbour in neighbours[item.Item1])
                {
                    if (mark[neighbour] == 0) stack.Push(new Tuple<int, int>(neighbour, -item.Item2));
                    else if (mark[neighbour] == item.Item2) goto invalid;
                }
            }
            groups.Add(new Tuple<int, int>(a, b));
        }

        bool[,] dp = new bool[n, n];
        dp[0, 0] = true;
        foreach (var group in groups)
        {
            bool[,] newdp = new bool[n, n];
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!dp[i, j]) continue;
                    if (i + group.Item1 < n && j + group.Item2 < n) newdp[i + group.Item1, j + group.Item2] = true;
                    if (i + group.Item2 < n && j + group.Item1 < n) newdp[i + group.Item2, j + group.Item1] = true;
                }
            }
            dp = newdp;
        }

        int res = int.MaxValue;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i, j]) res = Min(res, i * (i - 1) / 2 + j * (j - 1) / 2);
            }
        }
        Console.WriteLine(res);
        return;
        invalid:;
        Console.WriteLine(-1);
    }
}