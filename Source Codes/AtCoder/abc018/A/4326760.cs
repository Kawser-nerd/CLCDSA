using System;

class Program
{
  public static void Main(string[] args)
  {
    int[] x = new int[3];
    for (int i = 0; i < 3; i ++) x[i] = int.Parse(Console.ReadLine());
    int a = x[0];
    int b = x[1];
    int c = x[2];
    Array.Sort(x);
    Array.Reverse(x);
    Console.WriteLine(Array.IndexOf(x, a)+1);
    Console.WriteLine(Array.IndexOf(x, b)+1);
    Console.WriteLine(Array.IndexOf(x, c)+1);
  }
}