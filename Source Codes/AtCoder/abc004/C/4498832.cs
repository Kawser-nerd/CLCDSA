using System;

namespace ABC004 {
  class ProblemC {
    static void Main(string[] args) {
      int n = int.Parse(System.Console.ReadLine());
      int count = n % 30;
      int[] card = {1, 2, 3, 4, 5, 6};
      for (int i = 0; i < count; i++) {
        Swap(ref card[i % 5], ref card[i % 5 + 1]);
      }
      for (int i = 0; i < card.Length; i++) {
        System.Console.Write(card[i]);
      }
      System.Console.WriteLine();
    }
    static void Swap(ref int n, ref int m) {
      int tmp;
      tmp = m;
      m = n;
      n = tmp;
    }
  }
}