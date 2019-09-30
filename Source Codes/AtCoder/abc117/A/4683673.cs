using System;

class Program {
  static void Main (string[] args) {
    string[] str = Console.ReadLine().Split(' ');
    int a = int.Parse(str[0]);
    int b = int.Parse(str[1]);
    float ans = a * 1.0f / b;
    Console.WriteLine(ans);
  }
}