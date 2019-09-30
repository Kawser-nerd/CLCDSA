using System;
class A{
  static void Main(){
    var s = Console.ReadLine().Split(' ');
    Console.WriteLine($"{s[0][0]}{s[1][0]}{s[2][0]}".ToUpper());
  }
}