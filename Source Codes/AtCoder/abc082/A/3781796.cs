using System;
using System.Linq;
class A{
  public static void Main(){
    Console.WriteLine(Math.Ceiling(Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse).Average()));
  }
}