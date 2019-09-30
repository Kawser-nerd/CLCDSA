using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;
using System.Diagnostics;

namespace CompetitiveProgramming
{

  class Solve
  {
    public Solve()
    {
      string input = Console.ReadLine();
      int N = int.Parse(input.Split()[0]);
      int M = int.Parse(input.Split()[1]);

      int[] p = new int[N];

      for (int i = 0; i < M; i++) 
      {
        input = Console.ReadLine();
        int x = int.Parse(input.Split()[0]) - 1;
        int y = int.Parse(input.Split()[1]) - 1;
        p[y] |= (1 << x);
      }

      ulong[] dp = new ulong[1 << N];

      dp[0] = 1;
      for (int s = 0; s < (1 << N); s++)
      {
        for (int i = 0; i < N; i++)
        {
          int t = 1 << i;
          
          if ((t & s) == 0 &&(p[i] & s) == 0)
          {
            dp[s | t] += dp[s];
          }
        }
      }

      Console.WriteLine(dp[(1 << N) - 1]);
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