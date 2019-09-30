using System;
class A{
  static void Main(){
    var s = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
    var r = s[0]*s[3];
    var l = s[1]*s[2];
    Console.WriteLine(r==l?"DRAW":r>l?"AOKI":"TAKAHASHI");
  }
}