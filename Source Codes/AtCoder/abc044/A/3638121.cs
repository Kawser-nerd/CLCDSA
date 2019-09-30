using System;
namespace a{
  public class buri{
    public static void Main(){
      int n = int.Parse(Console.ReadLine()),
      k = int.Parse(Console.ReadLine()),
      x = int.Parse(Console.ReadLine()),
      y = int.Parse(Console.ReadLine());
      if (k <= n)
      {
        Console.WriteLine(k * x + (n - k) * y);          
      }
      else
      {
          Console.WriteLine(n * x);
      }
    }
  }
}