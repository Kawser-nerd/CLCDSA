using System;

namespace ABC002 {
  class ProblemB {
    static void Main(string[] args) {
      string str = Console.ReadLine();

      for (int i = 0; i < str.Length; i++) {
        if (str[i] != 'a' && str[i] != 'i' && str[i] != 'u' && str[i] != 'e' && str[i] != 'o') {
          System.Console.Write(str[i]);
        }
      }
      System.Console.WriteLine();
    }
  }
}