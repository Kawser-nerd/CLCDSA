using System;
class B{
  static void Main(){
    var s = int.Parse(Console.ReadLine());
    var n = 1;
    while(n*2<=s)
      n *= 2;
    Console.Write(n);
  }
}