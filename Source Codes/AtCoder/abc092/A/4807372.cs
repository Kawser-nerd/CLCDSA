using System;
using System.Linq;
public class c
{
  public static void Main()
  {
    int a=int.Parse(Console.ReadLine());
    int b=int.Parse(Console.ReadLine());
    int c=int.Parse(Console.ReadLine());
    int d=int.Parse(Console.ReadLine());
    if(a>b)a=b;
    if(c>d)c=d;
    Console.WriteLine(a+c);
  }
}