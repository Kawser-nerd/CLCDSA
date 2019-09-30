using System;
using System.Linq;
using System.Text;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var t = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int m = int.Parse(Console.ReadLine());
    var sb = new StringBuilder();
    while (m-- > 0) {
      var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
      int p = arr[0] - 1;
      int x = arr[1];
      int tmp = t[p];
      t[p] = x;
      sb.AppendLine(t.Sum().ToString());
      t[p] = tmp;
    }
    Console.Write(sb);
  }
}