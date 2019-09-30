using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var a = new string[n];
    for (int i = 0; i < n; i++) {
      a[i] = Console.ReadLine();
    }
    for (int i = 0; i < n; i++) {
      for (int j = n - 1; j >= 0; j--) {
        Console.Write(a[j][i]);
      }
      Console.WriteLine();
    }
  }
}