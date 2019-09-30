using System;
using System.Collections.Generic;

class Program {
  static void Main (string[] args) {
    string str = Console.ReadLine();
    int ans = int.Parse(str);
    if (ans == 3 || ans == 5 || ans == 7) {
      Console.WriteLine("YES");
    }
    else
    {
      Console.WriteLine("NO");
    }
  }
}