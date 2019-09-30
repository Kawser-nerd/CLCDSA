using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine()) % 30;
    int[] a = { 1, 2, 3, 4, 5, 6 };
    for (int i = 0; i < n; i++) {
      int s = i % 5;
      int t = a[s];
      a[s] = a[s + 1];
      a[s + 1] = t;
    }
    foreach (var i in a) Console.Write(i);
    Console.WriteLine();
  }
}