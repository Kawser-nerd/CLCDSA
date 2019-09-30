using System;

namespace ABC006 {
  class ProblemC {
    static int Main(string[] args) {
      string[] str = System.Console.ReadLine().Split(' ');
      int n = int.Parse(str[0]), m = int.Parse(str[1]);
      int a, b, c;

      if (m % 2 == 0) {
        b = 0;
        for (int i = 0; i < m / 4 + 1; i++) {
          c = i; a = m / 2 - 2 * c;
          if (a + b + c == n) {
            System.Console.WriteLine(a + " " + b + " " + c);
            return 0;
          }
        }
        System.Console.WriteLine("-1 -1 -1 ");
        return 0;
      } else {
        b = 1;
        for (int i = 0; i < (m - 3) / 4 + 1; i++) {
          c = i; a = (m - 3) / 2 - 2 * c;
          if (a + b + c == n) {
            System.Console.WriteLine(a + " " + b + " " + c);
            return 0;
          }
        }
        System.Console.WriteLine("-1 -1 -1");
        return 0;
      }
    }
  }
}