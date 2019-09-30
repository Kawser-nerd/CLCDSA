using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int n = int.Parse(Console.ReadLine());
    int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
    Array.Sort(s);
    Array.Reverse(s);
    int alice = 0;
    int bob = 0;
    for (int i = 0; i < n; i ++) {
      if (i % 2 == 0) alice += s[i];
      else bob += s[i];
    }
    Console.WriteLine(alice - bob);
  }
}