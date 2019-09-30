using System;
using System.Collections.Generic;

class Program {
  static void Main (string[] args) {
    string str = Console.ReadLine();
    int ans = int.Parse(str);
    string ans_str = "Christmas";
    if (25 - ans != 0) {
      for (int cnt = 0; cnt < 25 - ans; cnt++) {
        ans_str += " Eve";
      }
      Console.WriteLine(ans_str);
    }
    else {
      Console.WriteLine(ans_str);
    }
  }
}