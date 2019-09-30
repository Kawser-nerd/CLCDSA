using System;
class A{
  static void Main(){
    var s = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    var a = s[0] + s[1];
    Console.WriteLine(a >= 10?"error":a.ToString());
  }
}