using System;
using System.Collections;
using System.Collections.Generic;

namespace ABC008 {
  class ProblemC {
    static void Main(string[] args) {
      int n = int.Parse(System.Console.ReadLine());
      int[] coins = new int[n];
      for (int i = 0; i < n; i++) {
        coins[i] = int.Parse(System.Console.ReadLine());
      }

      double ans = 0;
      for (int i = 0; i < n; i++) {
        int d = 0;
        for (int j = 0; j < n; j++) {
          if (coins[i] % coins[j] == 0) {
            d++;
          }
        }
        if (d % 2 != 0) { // ??
          ans += (double)(d + 1) / (2 * d);
        } else {  // ??
          ans += 0.5;
        }
      }
      System.Console.WriteLine(ans);
    }
  }
}