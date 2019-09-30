using System;
using System.Collections;
using System.IO;
using System.Linq;

namespace CompetitiveProgramming
{

  class Solve
  {
    const ulong MOD = (ulong)(1e9) + 7;
    
    int N;
    ArrayList edges = new ArrayList();

    ulong[,] memo;
    ulong rec(int node, int parent, int isParentBlack) 
    {
      ulong ret = 1;

      if (memo[node, isParentBlack] > 0)
      {
        return memo[node, isParentBlack];
      }

      foreach(int e in (ArrayList)edges[node])
      {
        if (e == parent)
        {
          continue;
        }
        if (isParentBlack == 0)
        {
          ret = (ret * ((rec(e, node, 1) + rec(e, node, 0)) % MOD)) % MOD;
        }
        else
        {
          ret = (ret * rec(e, node, 0)) % MOD;
        }
      }
      return memo[node, isParentBlack] = (ret % MOD);
    }

    private void main()
    {
      N = int.Parse(Console.ReadLine());
      memo = new ulong[N, 2];
      for (int i = 0; i < N; i++)
      {
        edges.Add(new ArrayList());
      }

      for (int i = 0; i < N - 1; i++)
      {
        int[] ab = Console.ReadLine().Split().Select(int.Parse).ToArray();
        ((ArrayList)edges[ab[0] - 1]).Add(ab[1] - 1);
        ((ArrayList)edges[ab[1] - 1]).Add(ab[0] - 1);
      }

      Console.WriteLine((rec(0, -1, 1) + rec(0, -1, 0)) % MOD);
    }


    public Solve()
    {
      Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
      main();
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
}