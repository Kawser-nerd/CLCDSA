using System;
class A{
  static void Main(){
    var s = int.Parse(Console.ReadLine());
    Console.WriteLine(Math.Ceiling(s/2.0)*Math.Floor(s/2.0));
  }
}