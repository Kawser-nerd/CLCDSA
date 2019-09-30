using System;
using System.Collections.Generic;

class Program {
  static void Main (string[] args) {
    string[] str = Console.ReadLine().Split(' ');
    int a = int.Parse(str[0]);
    int b = int.Parse(str[1]);
    int ans = a + (b / 2);
    Console.WriteLine(ans);
  }
}