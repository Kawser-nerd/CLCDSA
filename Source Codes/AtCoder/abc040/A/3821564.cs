using System;
class A{
  static void Main(){
    var s = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
    Console.WriteLine(Math.Min(s[0]-s[1],s[1]-1));
  }
}