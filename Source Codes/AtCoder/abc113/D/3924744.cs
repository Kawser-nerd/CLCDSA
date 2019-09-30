using System;
using System.Linq;
using System.Collections.Generic;

class Program
{
  static void Main(string[] args)
  {

    var line = Console.ReadLine().Split(' ').Select(Int32.Parse).ToArray();
    var H = line[0];
    var W = line[1];
    var K = line[2];

    var dp = new int[H + 1, W];
    dp[0, 0] = 1;
    for (var hi = 0; hi < H; hi++)
    {
      for (var wi = 0; wi < W; wi++)
      {
        for (var bit = 0; bit < (1 << (W - 1)); bit++)
        {
          var invalid = false;
          for (var i = 0; i < W - 2; i++)
          {
            if ((bit & (1 << i)) != 0 && (bit & (1 << (i + 1))) != 0)
            {
              invalid = true;
            }
          }
          if (invalid) continue;

          var mod = 1000000007;
          if ((bit & (1 << (wi - 1))) != 0 && wi - 1 >= 0)
          {
            dp[hi + 1, wi - 1] += dp[hi, wi];
            dp[hi + 1, wi - 1] %= mod;
          }
          else if ((bit & (1 << wi)) != 0 && wi + 1 < W)
          {
            dp[hi + 1, wi + 1] += dp[hi, wi];
            dp[hi + 1, wi + 1] %= mod;
          }
          else
          {
            dp[hi + 1, wi] += dp[hi, wi];
            dp[hi + 1, wi] %= mod;
          }
        }
      }
    }

    Console.WriteLine(dp[H, K - 1]);
  }
}