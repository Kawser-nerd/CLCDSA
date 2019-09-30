using System;
using System.Linq;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        var n = int.Parse(Console.ReadLine());
        var csQuery =
            from c in Enumerable.Range(0, n)
            let xy = Console.ReadLine().Split()
                .Select(x => int.Parse(x))
                .ToArray()
            select new { c, xy };
        var cs = csQuery.ToArray();

        var ps = Enumerable.Range(0, 2)
            .Select(a => cs.Select(x => x.xy[a]).ToArray())
            .ToArray();

        var byAxis = new int[2][];
        var greedy = new PriorityQueue<int, Tuple<int, int>>();
        for (int a = 0; a < 2; ++a)
        {
            byAxis[a] = cs.Select(x => x.c).ToArray();
            Array.Sort(ps[a], byAxis[a]);

            for (int i = 0; i < n - 1; ++i)
            {
                var key = Math.Abs(ps[a][i + 1] - ps[a][i]);
                var value = Tuple.Create(byAxis[a][i], byAxis[a][i + 1]);
                greedy.Enqueue(key, value);
            }
        }

        var count = 1;
        var cost = 0L;
        var uf = new UnionFind(n);
        var neighborhood =
            from withCost in greedy
            let u = withCost.Value.Item1
            let v = withCost.Value.Item2
            where !uf.Union(u, v)
            select new { cost = withCost.Key, u, v };
        foreach (var edge in neighborhood.TakeWhile(_ => count < n))
        {
            cost += edge.cost;
            uf.Unite(edge.u, edge.v);
            ++count;
        }

        Console.WriteLine(cost);
    }
}

class PriorityQueue<TKey, TValue> : IEnumerable<KeyValuePair<TKey, TValue>>
{
    SortedDictionary<TKey, Queue<TValue>> container = new SortedDictionary<TKey, Queue<TValue>>();

    public void Enqueue(TKey key, TValue value)
    {
        Queue<TValue> queue;
        if (!container.TryGetValue(key, out queue))
        {
            queue = new Queue<TValue>();
            container.Add(key, queue);
        }
        queue.Enqueue(value);
    }

    public TValue Dequeue()
    {
        return container.First().Value.Dequeue();
    }

    public TValue Peek()
        => container.First().Value.Peek();

    public IEnumerator<KeyValuePair<TKey, TValue>> GetEnumerator()
    {
        var q =
            from withKey in container
            from x in withKey.Value
            select new KeyValuePair<TKey, TValue>(withKey.Key, x);
        foreach (var item in q)
        {
            yield return item;
        }
    }

    System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        => (System.Collections.IEnumerator)this.GetEnumerator();
}

class UnionFind
{
    int[] nodes;
    int[] ranks;

    public UnionFind(int size)
    {
        this.nodes = Enumerable.Range(0, size).ToArray();
        this.ranks = new int[size];
    }

    public int Find(int x)
    {
        var p = nodes[x];
        if (p == x)
        {
            return x;
        }

        return nodes[x] = Find(p);
    }

    public void Unite(int x, int y)
    {
        var p = Find(x);
        var q = Find(y);
        if (p == q)
        {
            return;
        }

        var r = ranks[p];
        var s = ranks[q];
        if (r < s)
        {
            nodes[p] = q;
        }
        else
        {
            nodes[q] = p;
            if (r == s)
            {
                ++ranks[p];
            }
        }
    }

    public bool Union(int x, int y)
        => Find(x) == Find(y);
}