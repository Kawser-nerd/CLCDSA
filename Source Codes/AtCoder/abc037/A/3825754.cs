using System;
class A{
  static void Main(){
    var s = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
    Console.WriteLine(s[2]/Math.Min(s[0],s[1]));
  }
}