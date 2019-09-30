using System;
using System.Linq;
class A{
  public static void Main(){
    Console.WriteLine(-4 + Console.ReadLine().Count(x => x == '+') * 2);
  }
}