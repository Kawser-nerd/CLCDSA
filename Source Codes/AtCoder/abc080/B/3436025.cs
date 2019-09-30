using System;
using System.Linq;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var h = n.ToString().ToArray().Select(x => int.Parse(x.ToString())).Sum();
    Console.WriteLine(n % h == 0 ? "Yes" : "No");
  }
}