using System;
using System.Linq;
class A{
  static void Main(){
    Console.WriteLine(Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse).OrderByDescending(x => x).Skip(1).Sum());
  }
}