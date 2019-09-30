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
      var n = ReadLine().ToInt();
      var a = ReadLine().Split(' ').Select(x => x.ToInt()).ToArray();

      var sortedA = a.OrderByDescending(x => x).ToArray();
      int alice = 0;
      int bob = 0;
      for (int i = 0; i < n; i++) {
         if (i % 2 == 0) {
            alice += sortedA[i];
         } else {
            bob += sortedA[i];
         }
      }
      WriteLine(alice - bob);
   }
}