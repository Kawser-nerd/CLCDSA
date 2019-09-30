using System;
using System.Linq;

class prog{
  static void Main(){
    int N = int.Parse(Console.ReadLine());
    int n = (int)Math.Sqrt(N);
    Console.WriteLine(n * n);
  }
}