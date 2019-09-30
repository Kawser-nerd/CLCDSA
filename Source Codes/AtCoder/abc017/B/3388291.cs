using System;

class Program {
  static void Main() {
    var x = Console.ReadLine();
    var s = "YES";
    for (int i = 0; i < x.Length; i++) {
      if (x[i] == 'o' || x[i] == 'k' || x[i] == 'u') {
        continue;
      } else if (i < x.Length - 1 && x[i] == 'c' && x[++i] == 'h') {
        continue;
      } else {
        s = "NO";
        break;
      }
    }
    Console.WriteLine(s);
  }
}