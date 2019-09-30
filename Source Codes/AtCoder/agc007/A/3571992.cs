using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int h = arr[0];
    int w = arr[1];
    int sum = 0;
    for (int i = 0; i < h; i++) {
      sum += Console.ReadLine().Count(x => x == '#');
    }
    Console.WriteLine(sum == h + w - 1 ? "Possible" : "Impossible");
  }
}