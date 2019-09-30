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
      var a = ReadLine().ToInt(); // 500yen
      var b = ReadLine().ToInt(); // 100yen
      var c = ReadLine().ToInt(); //  50yen
      var total = ReadLine().ToInt();

      int ctr = 0;
      for (int i = 0; i <= a; i++) {
         for (int j = 0; j <= b; j++) {
            for(int k = 0; k <= c; k++) {
               if (i*500 + j*100 + k*50 == total) ctr++;
               else if (i*500 + j*100 + k*50 > total) break;
            }
         }
      }

      WriteLine(ctr);
   }
}