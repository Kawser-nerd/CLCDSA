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
      var a = arr[1];
      var b = arr[2];

      int sum = 0;
      for (int i = 0; i <= n; i++) {
         var temp = i.ToString().Select(x => x.ToString()).Select(int.Parse).Sum();
         if (a <= temp && temp <= b) {
            sum += i;
         } 
      }
      WriteLine(sum);
   }
}