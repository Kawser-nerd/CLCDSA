using System;
using System.Linq;

class Program {
  static void Main() {
    int[] a = new int[int.Parse(Console.ReadLine()) + 1];
    var t = Console.ReadLine().Split().Select(int.Parse).ToArray();
    a[t[0]]++;
    a[t[1]]++;
    Console.ReadLine();
    t = Console.ReadLine().Split().Select(int.Parse).ToArray();
    foreach (var i in t) {
      if (++a[i] > 1) {
        Console.WriteLine("NO");
        return;
      }
    }
    Console.WriteLine("YES");
  }
}