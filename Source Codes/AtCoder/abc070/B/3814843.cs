using System;

class Program {
  static void Main(string[] args) {
    string[] s = Console.ReadLine().Split(' ');
    int a = int.Parse(s[0]);
    int b = int.Parse(s[1]);
    int c = int.Parse(s[2]);
    int d = int.Parse(s[3]);
  
    int max = System.Math.Min(b, d);
    int min = System.Math.Max(a, c);
    if (max - min > 0) {
      Console.WriteLine(max-min);
      return;
    }
    Console.WriteLine(0);
  }
}