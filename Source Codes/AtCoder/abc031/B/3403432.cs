using System;
using System.Linq;
using System.Text;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int L = arr[0];
    int h = arr[1];
    int n = int.Parse(Console.ReadLine());
    var sb = new StringBuilder();
    while (n-- > 0) {
      int a = int.Parse(Console.ReadLine());
      if (h < a) sb.AppendLine("-1");
      else if (a < L) sb.AppendLine((L - a).ToString());
      else sb.AppendLine("0");
    }
    Console.Write(sb);
  }
}