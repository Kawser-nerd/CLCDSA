using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Globalization;
using System.IO;

namespace Test
{
   class Program
   {
      static void Main(string[] args)
      {
         checkFreecell();
      }

      private static int toInt(char a) {
         return ((int)a - (int)'A');
      }

      //TODO: find more efficient way

      private static bool slowCheck(int min, int max, int percent) {
         for(int i = min; i <= max; i++) {
            // do 100x = p * y.
            int rhs = percent * i;
            if(rhs % 100 == 0) {
               Console.WriteLine("Possible with i = " + i + " and rhs = " + rhs + " and percent = " + percent);
               return true;
            }
         }
         return false;
      }

      private static String doFreecell(String line) {
         Console.WriteLine("Case: " + line);
         String[] parts = line.Split(new char[]{' '});

         int maxToday;

         if(parts[0].Length > 5) {
            maxToday = 1000;
         } else {
            maxToday = int.Parse(parts[0]);
         }

         int percentWinToday = int.Parse(parts[1]);
         int percentWinTotal = int.Parse(parts[2]);

         if(percentWinTotal == 100 || percentWinTotal == 0) {
            if (percentWinToday != percentWinTotal) {
               return "Broken";
            }
         }

         if (maxToday > 100) {
            // always possible, since you can always play 100 games and win a specific amount
            return "Possible";
         }

         // is it possible to win percentWinToday with total < maxToday games today?
         if(slowCheck(1, maxToday, percentWinToday)) {
            return "Possible";
         }
         

         return "Broken";
      }


      private static void checkFreecell()
      {

         String output = "";
         String[] lines = File.ReadAllLines("input");
         int numCases = int.Parse(lines[0]);
         for (int i = 1; i <= numCases; i++ )
         {

            output += ("Case #" + i + ": " + doFreecell(lines[i]));
            output += "\n";
         }

         Console.WriteLine("----Output----");
         Console.WriteLine(output);

         File.WriteAllText("output", output);
      }
   }
}
