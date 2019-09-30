using System;
using System.Linq;
using System.Collections.Generic;

public class Program{
  public static void Main(){
    var n = Array.ConvertAll(Console.ReadLine().Split(' '), UInt16.Parse);
    ulong a = (ulong) n[1];
    for(var i=1; i<n[0]; i++) a*= (ulong)n[1]-1;
    Console.WriteLine(a.ToString());
  }
}