using System;
class A{
  static void Main(){
    var s = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
    Console.WriteLine(2*(s[0]*s[1]+s[0]*s[2]+s[1]*s[2]));
  }
}