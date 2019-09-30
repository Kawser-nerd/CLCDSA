using System.Collections.Generic;
using System;

public class PriorityQueue<T> where T : IComparable
{
    private IComparer<T> _comparer = null;
    private int _type = 0;
    private T[] _heap;
    private int _sz = 0;
    private int _count = 0;
    /// <summary>
    /// Priority Queue with custom comparer
    /// </summary>
    public PriorityQueue(int maxSize, IComparer<T> comparer)
    {
        _heap = new T[maxSize];
        _comparer = comparer;
    }

    /// <summary>
    /// Priority queue
    /// </summary>
    /// <param name="maxSize">max size</param>
    /// <param name="type">0: asc, 1:desc</param>
    public PriorityQueue(int maxSize, int type = 0)
    {
        _heap = new T[maxSize];
        _type = type;
    }
    private int Compare(T x, T y)
    {
        if (_comparer != null) return _comparer.Compare(x, y);
        return _type == 0 ? x.CompareTo(y) : y.CompareTo(x);
    }
    public void Push(T x)
    {
        _count++;
        //node number
        var i = _sz++;
        while (i > 0)
        {
            //parent node number
            var p = (i - 1) / 2;

            if (Compare(_heap[p], x) <= 0) break;

            _heap[i] = _heap[p];
            i = p;
        }
        _heap[i] = x;
    }
    public T Pop()
    {
        _count--;
        T ret = _heap[0];
        T x = _heap[--_sz];

        int i = 0;
        while (i * 2 + 1 < _sz)
        {
            //children
            int a = i * 2 + 1;
            int b = i * 2 + 2;

            if (b < _sz && Compare(_heap[b], _heap[a]) < 0) a = b;

            if (Compare(_heap[a], x) >= 0) break;

            _heap[i] = _heap[a];
            i = a;
        }
        _heap[i] = x;
        return ret;
    }
    public int Count()
    {
        return _count;
    }
    public T Peek()
    {
        return _heap[0];
    }
    public bool Contains(T x)
    {
        for (int i = 0; i < _sz; i++) if (x.Equals(_heap[i])) return true;
        return false;
    }
    public void Clear()
    {
        while (this.Count() > 0) this.Pop();
    }
    public IEnumerator<T> GetEnumerator()
    {
        var ret = new List<T>();
        while (this.Count() > 0)
        {
            ret.Add(this.Pop());
        }
        foreach (var r in ret)
        {
            this.Push(r);
            yield return r;
        }
    }
    public T[] ToArray()
    {
        T[] array = new T[_sz];
        int i = 0;
        foreach (var r in this)
        {
            array[i++] = r;
        }
        return array;
    }
}
public struct Edge
{
    public int to { get; set; }
    public long d { get; set; }
}
public class Node : IComparable
{
    public int id { get; set; }
    public long d { get; set; }
    public int CompareTo(object obj)
    {
        var x = (Node)obj;
        if (this.d > x.d) return 1;
        else if (this.d == x.d) return 0;
        else return -1;
    }
}

public class Hello
{
    public const long INF = 9999999999999;
    public static void Main()
    {
        string[] line = Console.ReadLine().Trim().Split(' ');
        var n = int.Parse(line[0]);
        var m = int.Parse(line[1]);
        var a = new List<Edge>[n];
        for (int i = 0; i < n; i++) a[i] = new List<Edge>();
        for (int i = 0; i < m; i++)
        {
            line = Console.ReadLine().Trim().Split(' ');
            var a1 = int.Parse(line[0]) - 1;
            var a2 = int.Parse(line[1]) - 1;
            a[a1].Add(new Edge { to = a2, d = 1 });
            a[a2].Add(new Edge { to = a1, d = 1 });
        }
        var mind = new long[n];
        for (int i = 0; i < n; i++) mind[i] = INF;
        goDijk(a, 0, n, mind);
        Console.WriteLine(mind[n - 1] == 2 ? "POSSIBLE" : "IMPOSSIBLE");
    }
    public static void goDijk(List<Edge>[] aa, int r, int n, long[] mind)
    {
        var pq = new PriorityQueue<Node>(n + 1000, 0);
        pq.Push(new Node { id = r, d = 0 });
        while (pq.Count() > 0)
        {
            var targ = pq.Pop();
            var nowd = targ.d;
            var nowid = targ.id;
            if (mind[nowid] < nowd) continue;
            mind[nowid] = nowd;
            foreach (var x in aa[nowid])
                if (nowd + x.d < mind[x.to])
                    pq.Push(new Node { id = x.to, d = nowd + x.d });
        }
    }
}