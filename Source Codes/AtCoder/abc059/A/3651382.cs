using System;
class P{
  static void Main(){
    var a=Console.ReadLine().Split();
    Console.WriteLine($"{(char)(a[0][0]-32)}{(char)(a[1][0]-32)}{(char)(a[2][0]-32)}");
  }
}