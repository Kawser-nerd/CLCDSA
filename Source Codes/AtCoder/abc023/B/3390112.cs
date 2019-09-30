using System;

class Program {
  static void Main() {
    int n = int.Parse(Console.ReadLine());
    var s = Console.ReadLine();
    var acc = "b";
    if ((n & 1) == 0) {
      Console.WriteLine(-1);
      return;
    }
    int p = (n - 1) / 2;
    for (int i = 1; i <= p; i++) {
      if (i % 3 == 1) acc = "a" + acc + "c";
      else if (i % 3 == 2) acc = "c" + acc + "a";
      else  acc = "b" + acc + "b";
    }
    Console.WriteLine(acc == s ? p : -1);
  }
}