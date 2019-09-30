using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    char[] s = Console.ReadLine().ToCharArray();
    Console.WriteLine(s.Where(x => x.ToString() == "1").Count());
  }
}