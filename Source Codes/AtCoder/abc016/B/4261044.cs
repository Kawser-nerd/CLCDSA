using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
    int a = s[0];
    int b = s[1];
    int c = s[2];
    int plus = a + b;
    int minus = a - b;
    if (plus == c && minus == c) Console.WriteLine("?");
    else if (plus == c && minus != c) Console.WriteLine("+");
    else if (plus != c && minus == c) Console.WriteLine("-");
    else Console.WriteLine("!");
  }
}