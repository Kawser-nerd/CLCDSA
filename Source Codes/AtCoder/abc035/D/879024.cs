using System;
using System.Collections;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace CompetitiveProgramming
{
  class PriorityQueue<T> where T : IComparable
  {
    const int MAX_SIZE = 100010;
    private T[] heap;
    public int Size { get; protected set; }

    public PriorityQueue()
    {
      heap = new T[MAX_SIZE];
    }

    public void Push(T x)
    {
      int i = Size++;

      while (i > 0)
      {
        int p = (i - 1) / 2;
        if (heap[p].CompareTo(x) <= 0)
        {
          break;
        }
        heap[i] = heap[p];
        i = p;
      }
      heap[i] = x;
    }

    public T Top()
    {
      return heap[0];
    }

    public void Pop()
    {
      T x = heap[--Size];

      int i = 0;
      while (i * 2 + 1 < Size)
      {
        int a = i * 2 + 1, b = i * 2 + 2;
        if (b < Size && heap[b].CompareTo(heap[a]) < 0)
        {
          a = b;
        }

        if (heap[a].CompareTo(x) >= 0)
        {
          break;
        }
        heap[i] = heap[a];
        i = a;
      }
      heap[i] = x;
    }
  }

  class Pair<T1, T2> : IComparable where T1 : IComparable
  {
    public T1 first { get; set; }
    public T2 second { get; set; }

    public Pair() { }

    public Pair(T1 first, T2 second)
    {
      this.first = first;
      this.second = second;
    }

    public int CompareTo(object obj)
    {
      if (obj == null)
      {
        return 1;
      }
      return first.CompareTo(((Pair<T1, T2>)obj).first);
    }
  }

  class Edge
  {
    public int start { get; set; }
    public int goal { get; set; }
    public int cost { get; set; }


    public Edge(int start, int goal, int cost)
    {
      this.start = start;
      this.goal = goal;
      this.cost = cost;
    }
  }

  class Dijkstra
  {
    const int INF = (int)(1e9) + 10;
    public int[] d { get; protected set; }

    /* ???V????edges???????s???????d?s??????????? */
    public Dijkstra(int V, ArrayList edges, int s)
    {
      d = new int[V];
      PriorityQueue<Pair<int, int>> que = new PriorityQueue<Pair<int, int>>();

      for (int i = 0; i < V; i++)
      {
        d[i] = INF;
      }
      d[s] = 0;
      que.Push(new Pair<int, int>(0, s));

      while (que.Size > 0)
      {
        Pair<int, int> p = que.Top(); que.Pop();
        int v = p.second;
        if (d[v] < p.first)
        {
          continue;
        }

        for (int i = 0; i < ((ArrayList)edges[v]).Count; i++)
        {
          Edge e = (Edge)((ArrayList)edges[v])[i];
          if (d[e.goal] > d[v] + e.cost)
          {
            d[e.goal] = d[v] + e.cost;
            que.Push(new Pair<int, int>(d[e.goal], e.goal));
          }
        }
      }
    }
  }

  class Solve
  {
    const int INF = (int)(1e9) + 10;

    private void Main()
    {
      int[] NMT = Scanner.GetLine_Int();
      int N = NMT[0], M = NMT[1], T = NMT[2];
      int[] A = Scanner.GetLine_Int();

      ArrayList edges1 = new ArrayList();
      ArrayList edges2 = new ArrayList();

      for (int i = 0; i < N; i++)
      {
        edges1.Add(new ArrayList());
        edges2.Add(new ArrayList());
      }

      for (int i = 0; i < M; i++)
      {
        int[] abc = Scanner.GetLine_Int();
        int a = abc[0] - 1, b = abc[1] - 1, c = abc[2];
        ((ArrayList)edges1[a]).Add(new Edge(a, b, c));
        ((ArrayList)edges2[b]).Add(new Edge(b, a, c));
      }

      Dijkstra d1 = new Dijkstra(N, edges1, 0);
      Dijkstra d2 = new Dijkstra(N, edges2, 0);

      long ans = 0;
      for (int i = 0; i < N; i++)
      {
        int t = d1.d[i] + d2.d[i];
        ans = Math.Max(ans, (T - t) * (long)A[i]);
      }
      Console.WriteLine(ans);
    }

    public Solve()
    {
      Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
      Main();
      Console.Out.Flush();
    }
  }

  class Program
  {
    static void Main(string[] args)
    {
      new Solve();
    }
  }

  class Scanner
  {
    public static string GetLine()        { return Console.ReadLine().Trim(); }
    public static int[]  GetLine_Int()    { return Console.ReadLine().Trim().Split().Select(int.Parse).ToArray(); }
    public static long[] GetLine_Long()   { return Console.ReadLine().Trim().Split().Select(long.Parse).ToArray(); }
    public static ulong[] GetLine_ULong() { return Console.ReadLine().Trim().Split().Select(ulong.Parse).ToArray();  }
    public static string GetContents()    { return Console.In.ReadToEnd();  }
    public static int NextInt()     { return int.Parse(Console.ReadLine().Trim());  }
    public static long NextLong()   { return long.Parse(Console.ReadLine().Trim()); }
    public static ulong NextULong() { return ulong.Parse(Console.ReadLine().Trim());  }
  }
}