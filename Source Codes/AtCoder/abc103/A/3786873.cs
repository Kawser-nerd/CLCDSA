using System;
using System.Linq;
class A{
  static void Main(){
    var sum = 0;
    var s = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse).OrderBy(x => x).ToArray();
    for (int i = 0; i < s.Count() - 1; i++)
      sum += s[i + 1] - s[i];
    Console.Write(sum);
  }
}