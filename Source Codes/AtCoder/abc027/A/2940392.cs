using System;
using System.Linq;

class Program {
  static void Main() {
    int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    if (a == b) Console.WriteLine(c);
    else if (a == c) Console.WriteLine(b);
    else Console.WriteLine(a);
  }
}