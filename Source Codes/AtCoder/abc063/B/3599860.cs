using System;
using System.Linq;

class prog{
  static void Main(){
    string S = Console.ReadLine();
    int a = S.Distinct().Count();
    int b = S.Length;
    Console.WriteLine(a == b ? "yes" : "no");
  }
}