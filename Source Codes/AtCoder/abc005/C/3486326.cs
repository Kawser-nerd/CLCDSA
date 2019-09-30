using System;
using System.Linq;

class Program {
  static void Main() {
    int t = int.Parse(Console.ReadLine());
    Console.ReadLine();
    var A = Console.ReadLine().Split().Select(int.Parse).ToList();
    Console.ReadLine();
    var B = Console.ReadLine().Split().Select(int.Parse).ToList();
    foreach (var b in B) {
      bool f = false;
      for (int i = 0; i < A.Count; i++) {
        if (A[i] <= b && b <= A[i] + t) {
          A.RemoveAt(i);
          f = true;
          break;
        }
      }
      if (!f) {
        Console.WriteLine("no");
        return;
      }
    }
    Console.WriteLine("yes");
  }
}