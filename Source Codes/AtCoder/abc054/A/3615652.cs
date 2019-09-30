using System;
using System.Linq;

class prog{
  static void Main(){
    
    int[] i = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int[] s = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1};
    Console.WriteLine(Array.IndexOf(s, i[0]) > Array.IndexOf(s,i[1]) ? "Alice" : Array.IndexOf(s, i[0]) == Array.IndexOf(s, i[1]) ? "Draw" : "Bob");
    
  }
}