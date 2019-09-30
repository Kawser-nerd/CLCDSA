using System;
using System.Linq;

class Program {
  static void Main() {
    var arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int x1 = arr[0];
    int y1 = arr[1];
    int x2 = arr[2];
    int y2 = arr[3];
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x3 = x2 - dy;
    int y3 = y2 + dx;
    int x4 = x1 - dy;
    int y4 = y1 + dx;
    Console.WriteLine($"{x3} {y3} {x4} {y4}");
  }
}