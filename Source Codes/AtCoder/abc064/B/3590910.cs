using System;
using System.Linq;

class prog{
  static void Main(){
    Console.ReadLine();
    int[] a = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();
    Console.WriteLine(a[a.Length - 1] - a[0]);
  }
}