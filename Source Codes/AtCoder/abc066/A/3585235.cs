using System;
using System.Linq;

class prog{
  static void Main(){
    int[] n = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();
    Console.WriteLine(n[0] + n[1]);
  }
}