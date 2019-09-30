using System;
using System.Linq;
using System.Text;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    var h = arr[0];
    var w = arr[1];
    var sb = new StringBuilder();
    for (int i = 0; i < h; i++) {
      var s = Console.ReadLine();
      sb.AppendLine(s + "\n" + s);
    }
    Console.Write(sb);
  }
}