using System;
using System.IO;

namespace CompetitiveProgramming
{

  class Solve
  {
    public Solve()
    {
      string input = Console.ReadLine();
      int N = int.Parse(input.Split()[0]);
      int M = int.Parse(input.Split()[1]);

      Edge[] edges = new Edge[M];
      for (int i = 0; i < M; i++)
      {
        string[] t = Console.ReadLine().Split();
        edges[i] = new Edge(int.Parse(t[0]) - 1, int.Parse(t[1]) - 1, int.Parse(t[2]));
      }

      int Q = int.Parse(Console.ReadLine());
      int[] v = new int[Q];
      int[] w = new int[Q];
      int[] idx = new int[Q];
      int[] ans = new int[Q];

      for (int i = 0; i < Q; i++)
      {
        string[] t = Console.ReadLine().Split();
        v[i] = int.Parse(t[0]) - 1;
        w[i] = int.Parse(t[1]);
        idx[i] = i;
      }

      Array.Sort(w, idx);
      Array.Sort(edges, (a, b) => a.year - b.year);

      UnionFind UF = new UnionFind(N);

      int m = M - 1;
      for (int i = Q - 1; i >= 0; i--)
      {
        while (m >= 0 && edges[m].year > w[i])
        {
          UF.Unite(edges[m].start, edges[m].goal);
          m--;
        }
        ans[idx[i]] = UF.Size[UF.Find(v[idx[i]])];
      }

      Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
      for (int i = 0; i < Q; i++)
      {
        Console.WriteLine(ans[i]);
      }
      Console.Out.Flush();
    }
  }

  class Edge
  { 
    public int start { get; set; }
    public int goal { get; set; }
    public int year { get; set; }


    public Edge(int start, int goal, int year)
    {
      this.start = start;
      this.goal = goal;
      this.year = year;
    }
  }

  class Program
  {
    static void Main(string[] args)
    {
      new Solve();
    }
  }

  class UnionFind
  {
    int[] Parent;
    int[] Rank;
    public int[] Size;

    public UnionFind(int N)
    {
      Parent = new int[N];
      Rank = new int[N];
      Size = new int[N];

      for (int i = 0; i < N; i++)
      {
        Parent[i] = i;
        Size[i] = 1;
      }
    }

    public int Find(int x)
    {
      if (Parent[x] == x) 
      {
        return x;
      }
      else 
      {
        return Parent[x] = Find(Parent[x]);
      }
    }

    public void Unite(int x, int y)
    {
      x = Find(x);
      y = Find(y);
      if (x == y)
      {
        return;
      }

      

      if (Rank[x] < Rank[y])
      {
        Parent[x] = y;
        Size[y] += Size[x];
      } 
      else
      {
        Parent[y] = x;
        Size[x] += Size[y];
        if (Rank[x] == Rank[y])
        {
          Rank[x]++;
        }
      }
    }

    public bool IsSame(int x, int y)
    {
      return (Find(x) == Find(y));
    }
  }
}