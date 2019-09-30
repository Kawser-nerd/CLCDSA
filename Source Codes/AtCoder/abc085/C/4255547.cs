using System;
using System.Linq;
using static System.Console;

static class Extensions {
   public static int ToInt(this string str) {
      return int.Parse(str);
   }
}

class Program {
   public static void Main(string[] args) {
      var arr = ReadLine().Split(' ').Select(x => x.ToInt()).ToArray();
      var n = arr[0];
      var y = arr[1];

      for (int i = 0; i <= n; i++) {
         for (int j = 0; j + i <= n; j++) {
            var k = n - i - j;
            var sum = 10000 * i + 5000 * j + 1000 * k;
            
            if (sum == y) {
               WriteLine($"{i} {j} {k}");
               return;
            }
         }
      }
      
      WriteLine("-1 -1 -1");
   }
}