using System;
class A{
  static void Main(){
    var s = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
    Console.WriteLine(s[0] % 3 == 0 || s[1] % 3 == 0 || (s[0]+s[1]) % 3 == 0?"Possible":"Impossible");
  }
}