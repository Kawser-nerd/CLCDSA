using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        List<edge>[] edges = Enumerable.Repeat(0, n).Select(_ => new List<edge>()).ToArray();
        for (int i = 0; i < n - 1; i++)
        {
            int[] abc = Console.ReadLine().Split().Select(int.Parse).ToArray();
            edges[abc[0] - 1].Add(new edge(abc[1] - 1, abc[2]));
            edges[abc[1] - 1].Add(new edge(abc[0] - 1, abc[2]));
        }
        int[] qk = Console.ReadLine().Split().Select(int.Parse).ToArray();
        long[] totalCost = Enumerable.Repeat(long.MaxValue, n).ToArray();
        totalCost[qk[1] - 1] = 0;
        Queue<int> queue = new Queue<int>();
        queue.Enqueue(qk[1] - 1);
        while (queue.Count != 0)
        {
            int ind = queue.Dequeue();
            List<edge> list = edges[ind];
            for (int i = 0; i < list.Count; i++)
            {
                if (totalCost[list[i].to] > totalCost[ind])
                {
                    totalCost[list[i].to] = totalCost[ind] + list[i].cost;
                    queue.Enqueue(list[i].to);
                }
            }
        }
        for (int i = 0; i < qk[0]; i++)
        {
            int[] ab = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Console.WriteLine(totalCost[ab[0] - 1] + totalCost[ab[1] - 1]);
        }
    }
}
struct edge
{
    public int to;
    public long cost;
    public edge(int to, long cost)
    {
        this.to = to;
        this.cost = cost;
    }
}