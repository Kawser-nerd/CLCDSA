using System;
using System.Text;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < s.Length; i += 2) {
      sb.Append(s[i]);
    }
    Console.WriteLine(sb);
  }
}