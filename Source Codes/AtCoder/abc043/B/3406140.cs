using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    int[] a = new int[10];
    int p = 0;
    foreach (var c in s) {
      if (c == '0') p++;
      else if (c == '1') a[p++] = 1;
      else {
        if (p > 0) a[--p] = 0;
      }
    }
    for (int i = 0; i < p; i++) {
      Console.Write(a[i]);
    }
    Console.WriteLine();
  }
}