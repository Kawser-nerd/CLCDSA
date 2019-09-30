using System;
using System.Linq;
 
class P{
  static void Main(){
    var n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine(2*(n[0]*n[1]+n[1]*n[2]+n[2]*n[0]));
  }
}