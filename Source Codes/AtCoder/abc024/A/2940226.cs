using System;
using System.Linq;

class Program {
  static void Main() {
    int[] arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];
    int k = arr[3];
    arr = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int s = arr[0];
    int t = arr[1];
    int ans = s * a + t * b;
    if (s + t >= k) ans -= c * (s + t);
    Console.WriteLine(ans);
  }
}