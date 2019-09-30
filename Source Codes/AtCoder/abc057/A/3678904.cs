using System;
class P{
  static void Main(){
    var s=Console.ReadLine().Split();
    Console.WriteLine((int.Parse(s[1])+int.Parse(s[0]))%24);
  }
}