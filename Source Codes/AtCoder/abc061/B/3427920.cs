using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int n = arr[0];
    int m = arr[1];
    int[] a = new int[n];
    while (m-- > 0) {
      arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
      a[arr[0] - 1]++;
      a[arr[1] - 1]++;
    }
    foreach (var item in a) {
      Console.WriteLine(item);
    }
  }
}