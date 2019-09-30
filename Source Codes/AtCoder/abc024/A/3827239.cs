using System;
class A{
  static void Main(){
    var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
    var b = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
    Console.WriteLine(a[0]*b[0]+a[1]*b[1]-(b[0]+b[1]>=a[3]?(b[0]+b[1])*a[2]:0));
  }
}