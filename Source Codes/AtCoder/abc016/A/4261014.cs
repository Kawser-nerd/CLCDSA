using System;

class Program
{
  public static void Main(string[] args)
  {
    string[] s = Console.ReadLine().Split();
    int m = int.Parse(s[0]);
    int d = int.Parse(s[1]);
    int result = m % d;
    if (result == 0) Console.WriteLine("YES");
    else Console.WriteLine("NO");
  }
}