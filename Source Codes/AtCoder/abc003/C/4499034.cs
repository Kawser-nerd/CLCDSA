using System;

namespace ABC003 {
  class ProblemC {
    static void Main(string[] args) {
      string[] str1 = System.Console.ReadLine().Split(' '), str2 = System.Console.ReadLine().Split(' ');
      int n = int.Parse(str1[0]), k = int.Parse(str1[1]);
      int[] rate = new int[n];
      for (int i = 0; i < str2.Length; i++) {
        rate[i] = int.Parse(str2[i]);
      }

      double ret = 0;
      Array.Sort(rate);
      for (int i = 0; i < k; i++) {
        ret = (ret + rate[n - k + i]) / 2;
      }
      System.Console.WriteLine(ret);

    }
    
  }
}