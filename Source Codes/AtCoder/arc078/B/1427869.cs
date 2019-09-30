using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public struct Edge
{
    public readonly int U;
    public readonly int V;

    public Edge(int u, int v)
    {
        U = u;
        V = v;
    }
}

public sealed class IS
    : IEnumerable<int>
{
    public readonly bool IsEmpty;
    public readonly int Head;
    public readonly IS Tail;

    public static readonly IS Empty = new IS();

    public IS()
    {
        IsEmpty = true;
    }

    public IS(int head, IS tail)
    {
        IsEmpty = false;
        Head = head;
        Tail = tail;
    }

    public IEnumerator<int> GetEnumerator()
    {
        var xs = this;
        while (!xs.IsEmpty)
        {
            yield return xs.Head;
            xs = xs.Tail;
        }
    }

    IEnumerator IEnumerable.GetEnumerator()
    {
        return GetEnumerator();
    }
}

public class Program
{
    #region Standard I/O
    readonly TextReader input;
    readonly TextWriter output;

    X[] ReadLine<X>(Func<string, X> func)
    {
        return input.ReadLine().Split(' ').Select(func).ToArray();
    }

    void WriteLineOne(object obj)
    {
        output.WriteLine("{0}", obj);
    }

    void WriteLineMany(params object[] objects)
    {
        output.WriteLine(string.Join(" ", objects.Select(obj => obj.ToString())));
    }
    #endregion

    const int First = 0;
    const int Second = 1;

    int n;
    Edge[] edges;
    List<int>[] g;

    void Read()
    {
        n = ReadLine(int.Parse)[0];

        edges = new Edge[n - 1];

        for (var i = 0; i < edges.Length; i++)
        {
            var l = ReadLine(int.Parse);
            edges[i] = new Edge(l[0] - 1, l[1] - 1);
        }

        g = Enumerable.Repeat(0, n).Select(_ => new List<int>()).ToArray();
        foreach (var e in edges)
        {
            g[e.U].Add(e.V);
            g[e.V].Add(e.U);
        }
    }

    // 0 ?? n-1 ??????????
    int[] Spine()
    {
        var queue = new Queue<IS>();
        queue.Enqueue(new IS(0, IS.Empty));
        var done = new bool[n];

        while (queue.Count > 0)
        {
            var s = queue.Dequeue();

            if (s.Head == n - 1)
            {
                return s.Reverse().ToArray();
            }
            else
            {
                done[s.Head] = true;

                foreach (var v in g[s.Head])
                {
                    if (done[v]) continue;

                    queue.Enqueue(new IS(v, s));
                }
            }
        }

        throw new InvalidOperationException();
    }

    int Count(IEnumerable<int> friends, IEnumerable<int> opponents)
    {
        var stack = new Stack<int>();
        var done = new bool[n];

        foreach (var v in friends)
        {
            stack.Push(v);
        }

        foreach (var v in opponents)
        {
            done[v] = true;
        }

        var count = 0;
        while (stack.Count > 0)
        {
            var u = stack.Pop();
            if (done[u]) continue;

            done[u] = true;
            count++;

            foreach (var v in g[u])
            {
                stack.Push(v);
            }
        }
        return count;
    }

    int Solve()
    {
        var spine = Spine();
        var m = (spine.Length + 1) / 2;
        var blacks = new ArraySegment<int>(spine, 0, m);
        var whites = new ArraySegment<int>(spine, m, spine.Length - m);
        var blackCount = Count(blacks, whites);
        var whiteCount = Count(whites, blacks);
        return blackCount > whiteCount ? First : Second;
    }

    public void Run()
    {
        Read();
        WriteLineOne(Solve() == First ? "Fennec" : "Snuke");
    }

    public Program(TextReader input, TextWriter output)
    {
        this.input = input;
        this.output = output;
    }

    public static void Main(string[] args)
    {
        new Program(Console.In, Console.Out).Run();
    }
}