using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
    Console.WriteLine(Math.Max(0, Math.Min(a[1],a[3])-Math.Max(a[0],a[2])));
  }
}