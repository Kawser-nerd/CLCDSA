using System;
class A{
  static void Main(){
    var s = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    Console.WriteLine(Math.Abs(s[0] - s[1]) < Math.Abs(s[0] - s[2])? "A":"B");
  }
}