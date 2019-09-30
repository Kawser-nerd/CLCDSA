using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    string[] s = { "Positive", "Zero", "Negative" };
    int t = 0;
    if (0 < a && 0 < b) t = 0;
    else if (a <= 0 && 0 <= b) t = 1;
    else if (((b - a + 1) % 2) == 1) t = 2;
    Console.WriteLine(s[t]);
  }
}