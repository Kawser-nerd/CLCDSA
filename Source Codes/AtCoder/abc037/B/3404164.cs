using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int q = arr[1];
    int[] a = new int[n];
    while (q-- > 0) {
      arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
      int L = arr[0] - 1;
      int r = arr[1] - 1;
      int t = arr[2];
      for (int i = L; i <= r; i++) {
        a[i] = t;
      }
    }
    for (int i = 0; i < n; i++) {
      Console.WriteLine(a[i]);
    }
  }
}