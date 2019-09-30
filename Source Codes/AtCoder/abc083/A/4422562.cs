using System;
using System.Linq;

class Program
{
  public static void Main(string[] args)
  {
    int[] s = Console.ReadLine().Split().Select(int.Parse).ToArray();
    if(s[0] + s[1] > s[2] + s[3]) Console.WriteLine("Left");
    else if(s[0] + s[1] < s[2] + s[3]) Console.WriteLine("Right");
    else Console.WriteLine("Balanced");
  }
}