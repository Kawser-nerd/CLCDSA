using System;
using System.Linq;
using System.Text;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int h = arr[0];
    int w = arr[1];
    var sb = new StringBuilder();
    var s = new string('#', w + 2);
    sb.AppendLine(s);
    while (h-- > 0) {
      sb.Append("#");
      sb.Append(Console.ReadLine());
      sb.AppendLine("#");
    }
    sb.AppendLine(s);
    Console.Write(sb);
  }
}