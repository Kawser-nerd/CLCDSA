using System;
class A{
  static void Main(){
    var s = Array.ConvertAll(new [] { Console.ReadLine(), Console.ReadLine(), Console.ReadLine() }, int.Parse);
    Console.Write((s[0]+s[1])*s[2]/2);
  }
}