using System;
class B{
  static void Main(){
    var s = Console.ReadLine();
    Console.Write($"{s[0]}{s.Length-2}{s[s.Length-1]}");
  }
}