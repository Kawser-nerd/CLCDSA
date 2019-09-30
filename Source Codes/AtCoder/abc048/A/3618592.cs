using System;
using System.Linq;

class p{
  static void Main(){
    string[] n = Console.ReadLine().Split().ToArray();
    Console.WriteLine("A" + n[1].Substring(0, 1) + "C");
  }
}