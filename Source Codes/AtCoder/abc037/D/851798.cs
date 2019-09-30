using System;
using System.IO;
using System.Linq;

namespace CompetitiveProgramming
{

  class Solve
  {
    int H, W;
    int[,] a;

    const ulong MOD = (ulong)(1e9) + 7;

    ulong[,] memo;

    ulong rec(int y, int x)
    {
      if (a[y, x] == 0)
      {
        return 0;
      }

      if (memo[y, x] > 0) 
      {
        return memo[y, x];
      }

      ulong ret = 1;
      
      if (a[y, x] < a[y + 1, x])
      {
        ret = (ret + rec(y + 1, x)) % MOD;;
      }
      if (a[y, x] < a[y, x + 1]) 
      {
        ret = (ret + rec(y, x + 1)) % MOD;
      }
      if (a[y, x] < a[y - 1, x])
      {
        ret = (ret + rec(y - 1, x)) % MOD;
      }
      if (a[y, x] < a[y, x - 1])
      {
        ret = (ret + rec(y, x - 1)) % MOD;
      }

      return memo[y, x] = ret;
    }

    private void main()
    {
      int[] HW = Console.ReadLine().Split().Select(int.Parse).ToArray();
      H = HW[0]; W = HW[1];
      a = new int[H + 2, W + 2];
      memo = new ulong[1002, 1002];

      for (int y = 0; y < H; y++)
      {
        int[] row = Console.ReadLine().Split().Select(int.Parse).ToArray();
        for (int x = 0; x < W; x++)
        {
          a[y + 1, x + 1] = row[x];
        }
      }

      ulong ans = 0;

      for (int y = 1; y <= H; y++)
      {
        for (int x = 1; x <= W; x++)
        {
          ans = (ans + rec(y, x)) % MOD;
        }
      }

      Console.WriteLine(ans);
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