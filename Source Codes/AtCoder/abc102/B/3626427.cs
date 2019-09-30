using System;
using System.Linq;

class prog{
  static void Main(){
    Console.ReadLine();
    int[] A = Console.ReadLine().Split().Select(int.Parse).OrderBy(x => x).ToArray();
    Console.WriteLine(A[A.Length - 1] - A[0]);    
  }
}