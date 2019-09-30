using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        Queue<Tuple<int, int>> stack = new Queue<Tuple<int, int>>();
        int n = int.Parse(Console.ReadLine());
        List<int>[] edges = Enumerable.Repeat(0, n).Select(_ => new List<int>()).ToArray();
        for (int i = 0; i < n - 1; i++)
        {
            int[] a =  Console.ReadLine().Split().Select(int.Parse).ToArray();
            edges[a[0] - 1].Add(a[1] - 1);
            edges[a[1] - 1].Add(a[0] - 1);
        }
        int[] visit = new int[n];
        visit[0] = 1;
        visit[n - 1] = -1;
        stack.Enqueue(new Tuple<int, int>(0, 1));
        stack.Enqueue(new Tuple<int, int>(n - 1, -1));
        while (stack.Count != 0)
        {
            Debug.WriteLine(string.Join(" ", visit));
            var tup = stack.Dequeue();
            int[] edge = edges[tup.Item1].ToArray();
            Debug.WriteLine(string.Join(" ", edge));
            foreach (var vert in edge)
            {
                if (visit[vert] == 0)
                {
                    visit[vert] = tup.Item2;
                    stack.Enqueue(new Tuple<int, int>(vert, tup.Item2));
                }
            }
        }
        Console.WriteLine(visit.Count(x => x == 1) > visit.Count(x => x == -1) ? "Fennec" : "Snuke");
    }
}