using System;
class A{
  static void Main(){
    var a = int.Parse(Console.ReadLine());
    var b = int.Parse(Console.ReadLine());
    Console.WriteLine(a%b==0?0:b-a%b);
  }
}