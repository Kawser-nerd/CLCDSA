using System;
class A{
  static void Main(){
    var s = Console.ReadLine();
    Console.WriteLine(s.Contains("a") && s.Contains("b") && s.Contains("c") ? "Yes" : "No");
  }
}