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
      var a = new int[n];

      for (int i = 0; i < n; i++)
         a[i] = ReadLine().ToInt();

      WriteLine(a.GroupBy(x => x).Count());
   }
}