using System;

class Program {
  static void Main() {
    var s = Console.ReadLine();
    int t = int.Parse(Console.ReadLine());
    int a = 0, x = 0, y = 0;
    foreach (var c in s) {
      if (c == 'L') x--;
      else if (c == 'R') x++;
      else if (c == 'U') y++;
      else if (c == 'D') y--;
      else a++;
    }
    int d = Math.Abs(x) + Math.Abs(y);
    if (t == 1) {
      d += a;
    } else {
      if (d - a >= 0) d -= a;
      else d = (d - a) % 2 * -1;
    }
    Console.WriteLine(d);
  }
}