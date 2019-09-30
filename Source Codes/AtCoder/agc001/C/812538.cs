using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace CompetitiveProgramming
{
  class Solve
  {
    public Solve() {
      int N = Scanner.nextInt();
      int K = Scanner.nextInt();

      List<List<int>> e = new List<List<int>>();

      for (int i = 0; i < N; i++) 
      {
        e.Add(new List<int>());
      }
      for (int i = 0; i < N - 1; i++) 
      {
        int A = Scanner.nextInt() - 1;
        int B = Scanner.nextInt() - 1;
        e[A].Add(B);
        e[B].Add(A);
      }


      int maxDist = K / 2;
      var ans = Int32.MaxValue;
      for (int i = 0; i < N; i++)
      {
        if (K % 2 == 0) 
        {
          ans = Math.Min(ans, dfs(i, -1, 0, maxDist, e));
        }
        else
        {
          foreach (var j in e[i]) 
          {
            ans = Math.Min(ans, dfs(i, j, 0, maxDist, e) + dfs(j, i, 0, maxDist, e));
          }
        }
      }

      Console.WriteLine(ans);
    }

    int dfs(int cur, int prev, int dist, int maxDist, List<List<int>> e) 
    {
      int ret = (dist > maxDist) ? 1 : 0;
      foreach( var next in e[cur]) {
        if (next == prev)
        {
          continue;
        }
        ret += dfs(next, cur, dist + 1, maxDist, e);
      }

      return ret;
    }
  }

  class Program
  {
    static void Main(string[] args)
    {
        new Solve();
    }
  }

  public class Pair<T, U>
  {
    public Pair()
    {

    }
    public Pair(T first, U second)
    {
      this.first = first;
      this.second = second;
    }
    public T first { get; set; }
    public U second { get; set; }
  }

  class Scanner
  {
    private static List<string> buf = new List<string>();

    private static void next()
    {
      if (buf.Count == 0)
      {
        buf = Console.ReadLine().Split().ToList();
      }
    }

    private static string pop()
    {
      string ret = buf[0];
      buf.RemoveAt(0);
      return ret;
    }

    public static int nextInt()
    {
      next();
      return int.Parse(pop());
    }
    public static long nextLong()
    {
      next();
      return long.Parse(pop());
    }
    public static string nextString()
    {
      next();
      return pop();
    }
    public static double nextDouble()
    {
      next();
      return double.Parse(pop());
    }
  }
}