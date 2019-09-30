using System;
using System.Linq;
using System.Diagnostics;
using System.Collections.Generic;
class P
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        List<Path>[] path = Enumerable.Repeat(0,n).Select(x => new List<Path>()).ToArray();
        for (int i = 0; i < n - 1; i++)
        {
            int[] abc = Console.ReadLine().Split().Select(int.Parse).ToArray();
            path[abc[0] - 1].Add(new Path(abc[1] - 1, abc[2]));
            path[abc[1] - 1].Add(new Path(abc[0] - 1, abc[2]));
        }
        int[] qk = Console.ReadLine().Split().Select(int.Parse).ToArray();
        long[] cost = Enumerable.Repeat(long.MaxValue, n).ToArray();
        Queue<int> queue = new Queue<int>();
        queue.Enqueue(qk[1] - 1);
        cost[qk[1] - 1] = 0;
        while (queue.Count != 0)
        {
            int index = queue.Dequeue();
            List<Path> paths = path[index];
            for (int i = 0; i < paths.Count; i++)
            {
                if (cost[paths[i].To] > cost[index] + paths[i].Cost)
                {
                    cost[paths[i].To] = cost[index] + paths[i].Cost;
                    queue.Enqueue(paths[i].To);
                }
            }
        }
        for (int i = 0; i < qk[0]; i++)
        {
            int[] xy = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Console.WriteLine(cost[xy[0] - 1] + cost[xy[1] - 1]);
        }
    }
}
struct Path
{
    public int To;
    public long Cost;
    public Path(int to,long cost)
    {
        To = to;
        Cost = cost;
    }
}