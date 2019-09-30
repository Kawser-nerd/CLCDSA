using System;
using System.Linq;

class prog{
  static void Main(){
    int[] n = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Console.WriteLine(n[0] % 3 == 0||n[1] % 3 == 0||(n[0] + n[1]) % 3 == 0 ? "Possible" : "Impossible");
  }
}