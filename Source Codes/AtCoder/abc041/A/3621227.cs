using System;
using System.Linq;
 
class Program {
  static void Main()
  {    
    string s = Console.ReadLine();
    int n = int.Parse(Console.ReadLine());
    Console.WriteLine(s.Substring(n - 1, 1));
  }
}