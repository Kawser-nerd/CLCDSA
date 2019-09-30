using System;
 using System.Linq;
 
 class Program {
     public static void Main(string[] args) {
         var n = Console.ReadLine();
         var l = Console.ReadLine().Split(' ')
             .Select(int.Parse).ToList();
         l.Sort();
         var total = l.Where((a, i) => i % 2 == 0).Sum();
         Console.WriteLine(total);
     }
 }