using System;
using System.Linq;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var a = new string[n];
    var b = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      var arr = Console.ReadLine().Split().ToArray();
      a[i] = arr[0];
      b[i] = int.Parse(arr[1]);
      sum += b[i];
    }
    int m = sum / 2;
    for (int i = 0; i < n; i++) {
      if (b[i] > m) {
        Console.WriteLine(a[i]);
        return;
      }
    }
    Console.WriteLine("atcoder");
  }
}